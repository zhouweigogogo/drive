#include "yolo.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "cpu.h"

static float softmax(
        const float* src,
        float* dst,
        int length
        )
{
    float alpha = -FLT_MAX;
    for (int c = 0; c < length; c++)
    {
        float score = src[c];
        if (score > alpha)
        {
            alpha = score;
        }
    }

    float denominator = 0;
    float dis_sum = 0;
    for (int i = 0; i < length; ++i)
    {
        dst[i] = expf(src[i] - alpha);
        denominator += dst[i];
    }
    for (int i = 0; i < length; ++i)
    {
        dst[i] /= denominator;
        dis_sum += i * dst[i];
    }
    return dis_sum;
}
static float fast_exp(float x)
{
    union {
        uint32_t i;
        float f;
    } v{};
    v.i = (1 << 23) * (1.4426950409 * x + 126.93490512f);
    return v.f;
}

static float sigmoid(float x)
{
    return 1.0f / (1.0f + fast_exp(-x));
}
static float intersection_area(const Object& a, const Object& b)
{
    cv::Rect_<float> inter = a.rect & b.rect;
    return inter.area();
}

static void qsort_descent_inplace(std::vector<Object>& faceobjects, int left, int right)
{
    int i = left;
    int j = right;
    float p = faceobjects[(left + right) / 2].prob;

    while (i <= j)
    {
        while (faceobjects[i].prob > p)
            i++;

        while (faceobjects[j].prob < p)
            j--;

        if (i <= j)
        {
            // swap
            std::swap(faceobjects[i], faceobjects[j]);

            i++;
            j--;
        }
    }

    //     #pragma omp parallel sections
    {
        //         #pragma omp section
        {
            if (left < j) qsort_descent_inplace(faceobjects, left, j);
        }
        //         #pragma omp section
        {
            if (i < right) qsort_descent_inplace(faceobjects, i, right);
        }
    }
}

static void qsort_descent_inplace(std::vector<Object>& faceobjects)
{
    if (faceobjects.empty())
        return;

    qsort_descent_inplace(faceobjects, 0, faceobjects.size() - 1);
}

static void nms_sorted_bboxes(const std::vector<Object>& faceobjects, std::vector<int>& picked, float nms_threshold)
{
    picked.clear();

    const int n = faceobjects.size();

    std::vector<float> areas(n);
    for (int i = 0; i < n; i++)
    {
        areas[i] = faceobjects[i].rect.width * faceobjects[i].rect.height;
    }

    for (int i = 0; i < n; i++)
    {
        const Object& a = faceobjects[i];

        int keep = 1;
        for (int j = 0; j < (int)picked.size(); j++)
        {
            const Object& b = faceobjects[picked[j]];

            // intersection over union
            float inter_area = intersection_area(a, b);
            float union_area = areas[i] + areas[picked[j]] - inter_area;
            // float IoU = inter_area / union_area
            if (inter_area / union_area > nms_threshold)
                keep = 0;
        }

        if (keep)
            picked.push_back(i);
    }
}

static void generate_proposals_v5(
    const ncnn::Mat& anchors,
    const int stride,
    const ncnn::Mat& feat_blob,
    const float prob_threshold,
    std::vector<Object>& objects
)
{
    const int num_w = feat_blob.w;
    const int num_grid_y = feat_blob.c;
    const int num_grid_x = feat_blob.h;

    const int num_anchors = anchors.w / 2;
    const int walk = num_w / num_anchors;
    const int num_class = walk - 5;

    for (int i = 0; i < num_grid_y; i++)
    {
        for (int j = 0; j < num_grid_x; j++)
        {

            const float* matat = feat_blob.channel(i).row(j);

            for (int k = 0; k < num_anchors; k++)
            {
                const float anchor_w = anchors[k * 2];
                const float anchor_h = anchors[k * 2 + 1];
                const float* ptr = matat + k * walk;
                float box_confidence = ptr[4];
                if (box_confidence >= prob_threshold)
                {
                    // find class index with max class score
                    int class_index = 0;
                    float class_score = -FLT_MAX;
                    for (int c = 0; c < num_class; c++)
                    {
                        float score = ptr[5 + c];
                        if (score > class_score)
                        {
                            class_index = c;
                            class_score = score;
                        }
                        float confidence = box_confidence * class_score;

                        if (confidence >= prob_threshold)
                        {
                            float dx = ptr[0];
                            float dy = ptr[1];
                            float dw = ptr[2];
                            float dh = ptr[3];

                            float pb_cx = (dx * 2.f - 0.5f + j) * stride;
                            float pb_cy = (dy * 2.f - 0.5f + i) * stride;

                            float pb_w = powf(dw * 2.f, 2) * anchor_w;
                            float pb_h = powf(dh * 2.f, 2) * anchor_h;

                            float x0 = pb_cx - pb_w * 0.5f;
                            float y0 = pb_cy - pb_h * 0.5f;
                            float x1 = pb_cx + pb_w * 0.5f;
                            float y1 = pb_cy + pb_h * 0.5f;

                            Object obj;
                            obj.rect.x = x0;
                            obj.rect.y = y0;
                            obj.rect.width = x1 - x0;
                            obj.rect.height = y1 - y0;
                            obj.label = class_index;
                            obj.prob = confidence;

                            objects.push_back(obj);

                        }
                    }
                }
            }
        }
    }
}
static void generate_proposals_v8(
        int stride,
        const ncnn::Mat& feat_blob,
        const float prob_threshold,
        std::vector<Object>& objects
        )
{
    const int reg_max = 16;
    float dst[16];
    const int num_w = feat_blob.w;
    const int num_grid_y = feat_blob.c;
    const int num_grid_x = feat_blob.h;

    const int num_class = num_w - 4 * reg_max;

    for (int i = 0; i < num_grid_y; i++)
    {
        for (int j = 0; j < num_grid_x; j++)
        {

            const float* matat = feat_blob.channel(i).row(j);

            int class_index = 0;
            float class_score = -FLT_MAX;
            for (int c = 0; c < num_class; c++)
            {
                float score = matat[4 * reg_max + c];
                if (score > class_score)
                {
                    class_index = c;
                    class_score = score;
                }
            }

            if (class_score >= prob_threshold)
            {

                float x0 = j + 0.5f - softmax(matat, dst, 16);
                float y0 = i + 0.5f - softmax(matat + 16, dst, 16);
                float x1 = j + 0.5f + softmax(matat + 2 * 16, dst, 16);
                float y1 = i + 0.5f + softmax(matat + 3 * 16, dst, 16);

                x0 *= stride;
                y0 *= stride;
                x1 *= stride;
                y1 *= stride;

                Object obj;
                obj.rect.x = x0;
                obj.rect.y = y0;
                obj.rect.width = x1 - x0;
                obj.rect.height = y1 - y0;
                obj.label = class_index;
                obj.prob = class_score;
                objects.push_back(obj);

            }
        }
    }
}
static void generate_proposals_v6lite(int stride, const ncnn::Mat& pred, float prob_threshold, std::vector<Object>& objects)
{
    const int num_c = pred.c;
    const int num_grid_y = pred.h;
    const int num_grid_x = pred.w;
    const int num_classes = num_c - 4;

    for (int i = 0; i < num_grid_y; i++) {
        for (int j = 0; j < num_grid_x; j++) {
            const float *ptr = (float *) pred.data;
            int class_index = 0;
            float class_score = -1.f;
            for (int c = 0; c < num_classes; c++) {
                float score = ptr[c * num_grid_y * num_grid_x + i * num_grid_x + j];
                if (score > class_score) {
                    class_index = c;
                    class_score = score;
                }
            }
            if (class_score >= prob_threshold && class_score < 1.f) {
                float x0 = ptr[num_classes * num_grid_y * num_grid_x + i * num_grid_x + j];
                float y0 = ptr[(num_classes + 1) * num_grid_y * num_grid_x + i * num_grid_x + j];
                float x1 = ptr[(num_classes + 2) * num_grid_y * num_grid_x + i * num_grid_x + j];
                float y1 = ptr[(num_classes + 3) * num_grid_y * num_grid_x + i * num_grid_x + j];

                x0 = (j + 0.5f - x0) * stride;
                y0 = (i + 0.5f - y0) * stride;
                x1 = (j + 0.5f + x1) * stride;
                y1 = (i + 0.5f + y1) * stride;

                Object obj;
                obj.rect.x = x0;
                obj.rect.y = y0;
                obj.rect.width = x1 - x0;
                obj.rect.height = y1 - y0;
                obj.label = class_index;
                obj.prob = class_score;

                objects.push_back(obj);

            }
        }
    }
}

Yolo::Yolo()
{
    //    blob_pool_allocator.set_size_compare_ratio(0.f);
    //    workspace_pool_allocator.set_size_compare_ratio(0.f);
}


int Yolo::load(char* modeltype, int *target_size, float probThreshold,\
               float nmsThreshold, float focalLength, bool use_gpu)
{
    //    yolo.clear();
    //    blob_pool_allocator.clear();
    //    workspace_pool_allocator.clear();

    //    ncnn::set_cpu_powersave(1);
    ncnn::set_omp_num_threads(ncnn::get_big_cpu_count());

    yolo.opt = ncnn::Option();

#if NCNN_VULKAN
    yolo.opt.use_vulkan_compute = use_gpu;
#endif

    yolo.opt.num_threads = ncnn::get_big_cpu_count();
    //    printf("%d\n",ncnn::get_big_cpu_count());
    //    yolo.opt.blob_allocator = &blob_pool_allocator;
    //    yolo.opt.workspace_allocator = &workspace_pool_allocator;
    prob_threshold = probThreshold;
    nms_threshold = nmsThreshold;
    focal_length = focalLength;

    char parampath[256];
    char modelpath[256];

    QString pwd=QCoreApplication::applicationDirPath();
//    qDebug()<<(pwd+"/models/%s.param");

    sprintf(parampath, (pwd+"/models/%s.param").toLocal8Bit().data(), modeltype);
    sprintf(modelpath, (pwd+"/models/%s.bin").toLocal8Bit().data(), modeltype);

    yolo.load_param(parampath);
    yolo.load_model(modelpath);

    net_h = target_size[0];
    net_w = target_size[1];

    return 0;
}

int Yolo::detect_v8(const cv::Mat& rgb, std::vector<Object>& objects)
{
    int img_w = rgb.cols;
    int img_h = rgb.rows;

    // pad to multiple of 64
    int w = img_w;
    int h = img_h;
    float scale = 1.f;
    if (w > h)
    {
        scale = net_w / (float)w;
        w = net_w;
        h = h * scale;
    }
    else
    {
        scale = net_h / (float)h;
        h = net_h;
        w = w * scale;
    }

    ncnn::Mat in = ncnn::Mat::from_pixels_resize(rgb.data, ncnn::Mat::PIXEL_RGB2BGR, img_w, img_h, w, h);

    // pad to net_h net_w rectangle
    int wpad = (w + max_stride - 1) / max_stride * max_stride - w;
    int hpad = (h + max_stride - 1) / max_stride * max_stride - h;

    ncnn::Mat in_pad;
    ncnn::copy_make_border(in, in_pad, hpad / 2, hpad - hpad / 2, wpad / 2, wpad - wpad / 2, ncnn::BORDER_CONSTANT,  114.f);
    const float norm_vals[3] = {1 / 255.f,1 / 255.f,1 / 255.f};
    in_pad.substract_mean_normalize(0, norm_vals);

    ncnn::Extractor ex = yolo.create_extractor();

    ex.input("in0", in_pad);

    std::vector<Object> proposals;


    // stride 8
    {
        ncnn::Mat out;
        ex.extract("out0", out);

        std::vector<Object> objects8;
        generate_proposals_v8(8, out, prob_threshold, objects8);

        proposals.insert(proposals.end(), objects8.begin(), objects8.end());
    }

    // stride 16
    {
        ncnn::Mat out;

        ex.extract("out1", out);

        std::vector<Object> objects16;
        generate_proposals_v8(16, out, prob_threshold, objects16);

        proposals.insert(proposals.end(), objects16.begin(), objects16.end());
    }

    // stride 32
    {
        ncnn::Mat out;

        ex.extract("out2", out);

        std::vector<Object> objects32;
        generate_proposals_v8(32, out, prob_threshold, objects32);

        proposals.insert(proposals.end(), objects32.begin(), objects32.end());
    }

    qsort_descent_inplace(proposals);

    // apply nms with nms_threshold
    std::vector<int> picked;
    nms_sorted_bboxes(proposals, picked, nms_threshold);

    int count = picked.size();

    objects.resize(count);
    for (int i = 0; i < count; i++)
    {
        objects[i] = proposals[picked[i]];

        // adjust offset to original unpadded
        float x0 = (objects[i].rect.x - (wpad / 2)) / scale;
        float y0 = (objects[i].rect.y - (hpad / 2)) / scale;
        float x1 = (objects[i].rect.x + objects[i].rect.width - (wpad / 2)) / scale;
        float y1 = (objects[i].rect.y + objects[i].rect.height - (hpad / 2)) / scale;

        // clip
        x0 = std::max(std::min(x0, (float)(img_w - 1)), 0.f);
        y0 = std::max(std::min(y0, (float)(img_h - 1)), 0.f);
        x1 = std::max(std::min(x1, (float)(img_w - 1)), 0.f);
        y1 = std::max(std::min(y1, (float)(img_h - 1)), 0.f);

        objects[i].rect.x = x0;
        objects[i].rect.y = y0;
        objects[i].rect.width = x1 - x0;
        objects[i].rect.height = y1 - y0;

        // 单眼测距
        float dis_inch = (focal_length * car_height) / (objects[i].rect.height - 2);
        float dis_cm = dis_inch * 2.54;

        objects[i].distance = (int) dis_cm / 100;
        // std::cout << "distance: " << objects[i].distance << std::endl;
    }

    return 0;
}
int Yolo::detect_v5(const cv::Mat& rgb, std::vector<Object>& objects)
{
    int img_w = rgb.cols;
    int img_h = rgb.rows;

    // pad to multiple of 64
    int w = img_w;
    int h = img_h;
    float scale = 1.f;
    if (w > h)
    {
        scale = net_w / (float)w;
        w = net_w;
        h = h * scale;
    }
    else
    {
        scale = net_h / (float)h;
        h = net_h;
        w = w * scale;
    }

    ncnn::Mat in = ncnn::Mat::from_pixels_resize(rgb.data, ncnn::Mat::PIXEL_RGB2BGR, img_w, img_h, w, h);

    // pad to net_h net_w rectangle
    int wpad = (w + max_stride - 1) / max_stride * max_stride - w;
    int hpad = (h + max_stride - 1) / max_stride * max_stride - h;

    ncnn::Mat in_pad;
    ncnn::copy_make_border(in, in_pad, hpad / 2, hpad - hpad / 2, wpad / 2, wpad - wpad / 2, ncnn::BORDER_CONSTANT,  114.f);
    const float norm_vals[3] = {1 / 255.f,1 / 255.f,1 / 255.f};
    in_pad.substract_mean_normalize(0, norm_vals);

    ncnn::Extractor ex = yolo.create_extractor();

    ex.input("in0", in_pad);

    std::vector<Object> proposals;


    {
            ncnn::Mat out;
            ex.extract("out0", out);

            ncnn::Mat anchors(6);
            anchors[0] = 10.f;
            anchors[1] = 13.f;
            anchors[2] = 16.f;
            anchors[3] = 30.f;
            anchors[4] = 33.f;
            anchors[5] = 23.f;

            std::vector<Object> objects8;
            generate_proposals_v5(anchors, 8, out, prob_threshold, objects8);

            proposals.insert(proposals.end(), objects8.begin(), objects8.end());
        }

        // stride 16
        {
            ncnn::Mat out;

            ex.extract("out1", out);

            ncnn::Mat anchors(6);
            anchors[0] = 30.f;
            anchors[1] = 61.f;
            anchors[2] = 62.f;
            anchors[3] = 45.f;
            anchors[4] = 59.f;
            anchors[5] = 119.f;

            std::vector<Object> objects16;
            generate_proposals_v5(anchors, 16, out, prob_threshold, objects16);

            proposals.insert(proposals.end(), objects16.begin(), objects16.end());
        }

        // stride 32
        {
            ncnn::Mat out;

            ex.extract("out2", out);

            ncnn::Mat anchors(6);
            anchors[0] = 116.f;
            anchors[1] = 90.f;
            anchors[2] = 156.f;
            anchors[3] = 198.f;
            anchors[4] = 373.f;
            anchors[5] = 326.f;

            std::vector<Object> objects32;
            generate_proposals_v5(anchors, 32, out, prob_threshold, objects32);

            proposals.insert(proposals.end(), objects32.begin(), objects32.end());
        }

        qsort_descent_inplace(proposals);

        // apply nms with nms_threshold
        std::vector<int> picked;
        nms_sorted_bboxes(proposals, picked, nms_threshold);

        int count = picked.size();

        objects.resize(count);
        for (int i = 0; i < count; i++)
        {
            objects[i] = proposals[picked[i]];

            // adjust offset to original unpadded
            float x0 = (objects[i].rect.x - (wpad / 2)) / scale;
            float y0 = (objects[i].rect.y - (hpad / 2)) / scale;
            float x1 = (objects[i].rect.x + objects[i].rect.width - (wpad / 2)) / scale;
            float y1 = (objects[i].rect.y + objects[i].rect.height - (hpad / 2)) / scale;

            // clip
            x0 = std::max(std::min(x0, (float)(img_w - 1)), 0.f);
            y0 = std::max(std::min(y0, (float)(img_h - 1)), 0.f);
            x1 = std::max(std::min(x1, (float)(img_w - 1)), 0.f);
            y1 = std::max(std::min(y1, (float)(img_h - 1)), 0.f);

            objects[i].rect.x = x0;
            objects[i].rect.y = y0;
            objects[i].rect.width = x1 - x0;
            objects[i].rect.height = y1 - y0;

            // 单眼测距
            float dis_inch = (focal_length * car_height) / (objects[i].rect.height - 2);
            float dis_cm = dis_inch * 2.54;

            objects[i].distance = (int) dis_cm / 100;
            // std::cout << "distance: " << objects[i].distance << std::endl;
        }


        return 0;
}

int Yolo::detect_v6lite(const cv::Mat &rgb, std::vector<Object> &objects)
{
    int width = rgb.cols;
    int height = rgb.rows;

    // pad to multiple of 64
    int w = width;
    int h = height;
    float scale = 1.f;
    if (w > h)
    {
        scale = net_w / (float)w;
        w = net_w;
        h = h * scale;
    }
    else
    {
        scale = net_h / (float)h;
        h = net_h;
        w = w * scale;
    }

    ncnn::Mat in = ncnn::Mat::from_pixels_resize(rgb.data, ncnn::Mat::PIXEL_RGB2BGR, width, height, w, h);

    // pad to net_h net_w rectangle
    int wpad = (w + max_stride_v6lite - 1) / max_stride_v6lite * max_stride_v6lite - w;
    int hpad = (h + max_stride_v6lite - 1) / max_stride_v6lite * max_stride_v6lite - h;
    ncnn::Mat in_pad;
    ncnn::copy_make_border(in, in_pad, hpad / 2, hpad - hpad / 2, wpad / 2, wpad - wpad / 2, ncnn::BORDER_CONSTANT,  114.f);
    const float norm_vals[3] = { 1 / 255.f, 1 / 255.f, 1 / 255.f };
    const float mean_vals[3] = { 0.f, 0.f, 0.f };
    in_pad.substract_mean_normalize(mean_vals, norm_vals);

    ncnn::Extractor ex = yolo.create_extractor();

    ex.input("in0", in_pad);

    std::vector<Object> proposals;

    // stride 8
    {
        ncnn::Mat out;
        ex.extract("out0", out);

        std::vector<Object> objects8;
        generate_proposals_v6lite(8, out, prob_threshold, objects8);

        proposals.insert(proposals.end(), objects8.begin(), objects8.end());
    }

    // stride 16
    {
        ncnn::Mat out;
        ex.extract("out1", out);

        std::vector<Object> objects16;
        generate_proposals_v6lite(16, out, prob_threshold, objects16);

        proposals.insert(proposals.end(), objects16.begin(), objects16.end());
    }

    // stride 32
    {
        ncnn::Mat out;
        ex.extract("out2", out);

        std::vector<Object> objects32;
        generate_proposals_v6lite(32, out, prob_threshold, objects32);

        proposals.insert(proposals.end(), objects32.begin(), objects32.end());
    }

    // stride 64
    {
        ncnn::Mat out;
        ex.extract("out3", out);

        std::vector<Object> objects64;
        generate_proposals_v6lite(64, out, prob_threshold, objects64);

        proposals.insert(proposals.end(), objects64.begin(), objects64.end());
    }

    // sort all proposals by score from highest to lowest
    qsort_descent_inplace(proposals);

    // apply nms with nms_threshold
    std::vector<int> picked;
    nms_sorted_bboxes(proposals, picked, nms_threshold);

    int count = picked.size();

    //    objects.resize(count);
    for (int i = 0; i < count; i++)
    {
        Object obj = proposals[picked[i]];

        // adjust offset to original unpadded
        float x0 = (obj.rect.x - (wpad / 2)) / scale;
        float y0 = (obj.rect.y - (hpad / 2)) / scale;
        float x1 = (obj.rect.x + obj.rect.width - (wpad / 2)) / scale;
        float y1 = (obj.rect.y + obj.rect.height - (hpad / 2)) / scale;

        // clip
        x0 = std::floor(std::max(std::min(x0, (float)(width - 1)), 1.f));
        y0 = std::floor(std::max(std::min(y0, (float)(height - 1)), 1.f));
        x1 = std::ceil(std::max(std::min(x1, (float)(width - 1)), 1.f));
        y1 = std::ceil(std::max(std::min(y1, (float)(height - 1)), 1.f));


        obj.rect.x = x0;
        obj.rect.y = y0;
        obj.rect.width = x1 - x0;
        obj.rect.height = y1 - y0;
        if (obj.rect.width > 10.f && obj.rect.height > 10.f) {
            // sigle eye test distance
            float dis_inch = (focal_length * car_height) / (obj.rect.height - 2);
            float dis_cm = dis_inch * 2.54;
            obj.distance = (int) dis_cm / 100;
            objects.push_back(obj);
        }
    }

    // sort objects by area
    struct
    {
        bool operator()(const Object& a, const Object& b) const
        {
            return a.rect.area() > b.rect.area();
        }
    } objects_area_greater;
    std::sort(objects.begin(), objects.end(), objects_area_greater);

    return 0;
}

int Yolo::draw(cv::Mat& image, const std::vector<Object>& objects, bool is_lowrisk)
{
    static const char* class_names[] = {"person", "car","tf_green", "tf_yellow", "tf_red", "tf_sign"};
    static const char* risk_names[] = {"low risk", "medium risk","high risk"};

    // cv::Mat image = bgr.clone();

    for (size_t i = 0; i < objects.size(); i++)
    {
        const Object& obj = objects[i];

        // fprintf(stderr, "%d = %.5f at %.2f %.2f %.2f x %.2f\n", obj.label, obj.prob,
        //     obj.rect.x, obj.rect.y, obj.rect.width, obj.rect.height);

        char text[256];
        // high risk red
        if (obj.distance < 10) {
            sprintf(text, "%s %.1f%% %s", class_names[obj.label], obj.prob * 100, risk_names[2]);
        }
        // medium risk
        else if (obj.distance >= 10 && obj.distance <= 30) {
            sprintf(text, "%s %.1f%% %s", class_names[obj.label], obj.prob * 100, risk_names[1]);
        }
        // low risk
        else if (obj.distance > 30 && is_lowrisk == true){
            sprintf(text, "%s %.1f%% %s", class_names[obj.label], obj.prob * 100, risk_names[0]);
        }
        cv::rectangle(image, obj.rect, cv::Scalar(255, 0, 0));
        int baseLine = 0;
        cv::Size label_size = cv::getTextSize(text, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);

        int x = obj.rect.x;
        int y = obj.rect.y - label_size.height - baseLine;
        if (y < 0)
            y = 0;
        if (x + label_size.width > image.cols)
            x = image.cols - label_size.width;

        // high risk
        if (obj.distance < 10) {
            cv::rectangle(image, cv::Rect(cv::Point(x, y), cv::Size(label_size.width, label_size.height + baseLine)),cv::Scalar(0, 0, 255), -1);
            cv::putText(image, text, cv::Point(x, y + label_size.height),cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
        // medium risk
        else if (obj.distance >= 10 && obj.distance <= 30) {
            cv::rectangle(image, cv::Rect(cv::Point(x, y), cv::Size(label_size.width, label_size.height + baseLine)),cv::Scalar(0, 69, 255), -1);
            cv::putText(image, text, cv::Point(x, y + label_size.height),cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
        // low risk
        else if (obj.distance > 30 && is_lowrisk == true){
            cv::rectangle(image, cv::Rect(cv::Point(x, y), cv::Size(label_size.width, label_size.height + baseLine)),cv::Scalar(0, 255, 0), -1);
            cv::putText(image, text, cv::Point(x, y + label_size.height),cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
    }
    return 0;
}
cv::Mat Yolo::resizeImage(const cv::Mat &image, int targetWidth, int targetHeight)
{
    cv::Mat resizedImage; cv::Size targetSize(targetWidth, targetHeight); // 计算缩放比例
    float scale = std::min((float)targetWidth / image.cols, (float)targetHeight / image.rows);
    cv::Size scaledSize(image.cols * scale, image.rows * scale); // 缩放图像
    cv::resize(image, resizedImage, scaledSize); // 计算填充大小
    int top = (targetHeight - resizedImage.rows) / 2;
    int bottom = targetHeight - resizedImage.rows - top;
    int left = (targetWidth - resizedImage.cols) / 2;
    int right = targetWidth - resizedImage.cols - left; // 填充黑边
    cv::Mat paddedImage; cv::copyMakeBorder(resizedImage, paddedImage, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(0));
    return paddedImage;
}

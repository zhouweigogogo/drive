// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef YOLO_H
#define YOLO_H

#include <opencv2/core/core.hpp>

#include <net.h>
#include <stdio.h>
#include <vector>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#define car_height 62.99

struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
    int distance;
};

class Yolo
{
public:
    Yolo();

    int load(char* modeltype, int *target_size, float prob_threshold,\
             float nms_threshold, float focalLength,bool use_gpu = false);
    int detect_v8(const cv::Mat& rgb, std::vector<Object>& objects);
    int detect_v6lite(const cv::Mat& rgb, std::vector<Object>& objects);
    int detect_v5(const cv::Mat& rgb, std::vector<Object>& objects);
    int draw(cv::Mat& rgb, const std::vector<Object>& objects, bool is_lowrisk);
    cv::Mat resizeImage(const cv::Mat &image, int targetWidth, int targetHeight);
private:
    ncnn::Net yolo;
    int net_h;
    int net_w;
    int max_stride_v6lite = 64;
    int max_stride = 32;
    float prob_threshold; // 0.25f
    float nms_threshold; // 0.45f
    float focal_length; // 1990.0
    ncnn::UnlockedPoolAllocator blob_pool_allocator;
    ncnn::PoolAllocator workspace_pool_allocator;
};

#endif // NANODET_H

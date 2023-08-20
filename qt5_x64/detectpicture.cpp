#include "detectpicture.h"
#include <QDebug>
detectPicture::detectPicture(QObject *parent) : QThread(parent)
{

}

void detectPicture::receiveImgUrl(QString imgpath,QString savepath,float prob_thresholds,float nms_thresholds,float focalLengths,int target_sizess[2],QString modeltypess,bool isv6s,int w,int h,bool res)
{
    //接受主线程传来的图片url
    imgurl=imgpath;
    saveurl=savepath;
    prob_threshold=prob_thresholds;
    nms_threshold=nms_thresholds;
    focalLength=focalLengths;
    target_sizes[0]=target_sizess[0];
    target_sizes[1]=target_sizess[1];
    modeltypes=modeltypess;
    isv6=isv6s;
    playerwidth=w;
    playerheight=h;
    removelowrisk=res;
}

void detectPicture::run()
{
    Yolo yolov6;
    cv::Mat m = cv::imread(imgurl.toLocal8Bit().toStdString(), 1);
    std::vector<Object> objects;
    yolov6.load(modeltypes.toLocal8Bit().data(),target_sizes,prob_threshold,nms_threshold,focalLength);
    if(modeltypes.indexOf("v6")!=-1){
        yolov6.detect_v6lite(m,objects);
    }else if(modeltypes.indexOf("v5")!=-1){
        yolov6.detect_v5(m, objects);
    }else if (modeltypes.indexOf("v8")!=-1) {
        yolov6.detect_v8(m,objects);
    }
    yolov6.draw(m, objects,!removelowrisk);
    m=yolov6.resizeImage(m,playerwidth,playerheight);
    emit finishUrl(m);
    this->exit();
}

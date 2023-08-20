#ifndef DETECTPICTURE_H
#define DETECTPICTURE_H
#include <QString>
#include <QObject>
#include <QThread>
#include<yolo.h>
#include <opencv4/opencv2/opencv.hpp>

class detectPicture : public QThread
{
    Q_OBJECT
public:
    explicit detectPicture(QObject *parent = nullptr);
    void receiveImgUrl(QString imgpath,QString savepath,float prob_threshold,float nms_threshold,float focalLength,int target_sizes[2],QString modeltypes,bool isv6,int w,int h,bool removelowrisk);

signals:
    void finishUrl(cv::Mat);
    //给ui返回生成结果的url或图片对象
protected:
    void run() override;
private:
    QString imgurl;
    QString saveurl;
    float prob_threshold = 0.25f;
    float nms_threshold = 0.45f;
    float focalLength = 1990.0;
    int target_sizes[2] = {320, 192};
    QString modeltypes;
    bool isv6;
    int playerwidth;
    int playerheight;
    int removelowrisk;
};

#endif // DETECTPICTURE_H

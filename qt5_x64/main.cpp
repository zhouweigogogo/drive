#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <opencv4/opencv2/opencv.hpp>
#include <QMetaType>
#include <QCoreApplication>
#include <registerwindow.h>
//#include "client.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qRegisterMetaType<cv::Mat>("cv::Mat");

//    car_initialize();
    //软件运行前的检查
    QString pwd=QCoreApplication::applicationDirPath();
    QString modelpath=pwd+"/models/model.ini";
    QString modelreadpath;
    QFileInfo f1(modelpath);
    //保证model.ini存在
    if(!f1.isFile()){
        QFile f1fp(modelpath);
        f1fp.open(QFile::WriteOnly|QFile::Text);
        QString writestr=pwd+"/models/yolov6lite_l1.ini";
        f1fp.write(writestr.toLocal8Bit());
        f1fp.close();
        modelreadpath=writestr;
    }else{
        //model.ini存在
        QFile f1fp(modelpath);
        f1fp.open(QFile::ReadOnly);
        modelreadpath=f1fp.readAll().replace("\n","");
        f1fp.close();
    }
    //默认ini正确
    QFileInfo f2(modelreadpath);
    if(!f1.isFile()){
        //v6ini不存在
        QFile f2fp(modelreadpath);
        f2fp.open(QFile::WriteOnly|QFile::Text);
        QString writestr=pwd+"/models/yolov6lite_l1.param\n"+pwd+"/models/yolov6lite_l1.param\n320,192\n0.25\n0.45\n1990.0";

        f2fp.write(writestr.toLocal8Bit());
        f2fp.close();
    }else{
        //v6ini存在
        //        qDebug()<<modelreadpath;
        QFile f2fp(modelreadpath);
        f2fp.open(QFile::ReadOnly);
        QString v6literead=f2fp.readAll();
        f2fp.close();

        QStringList v6list=v6literead.split("\n");

        if(v6list.size()<6){
            QFile f3fp(modelreadpath);
            f3fp.open(QFile::WriteOnly|QFile::Text);
            QString writestr=pwd+"/models/yolov6lite_l1.param\n"+pwd+"/models/yolov6lite_l1.param\n320,192\n0.25\n0.45\n1990.0";
            f3fp.write(writestr.toLocal8Bit());
            f3fp.close();
        }else{
            QString readparam=v6list.at(0);
            QString readbin=v6list.at(1);
            QFileInfo f3p(readparam);
            QFileInfo f3b(readbin);
            if(f3p.isFile()&&f3b.isFile()&&v6list.size()>=6){
                //文件没错
                //                qDebug()<<"v6文件没错,size="<<v6list.size()<<"v6list="<<v6list;
            }else{
                QFile f3fp(modelreadpath);
                f3fp.open(QFile::WriteOnly|QFile::Text);
                QString writestr=pwd+"/models/yolov6lite_l1.param\n"+pwd+"/models/yolov6lite_l1.param\n320,192\n0.25\n0.45\n1990.0";
                f3fp.write(writestr.toLocal8Bit());
                f3fp.close();
            }
        }
    }

    loginwindow login;
    login.show();


    //    QFile fs(":/qtcss/white.qss");
    //    fs.open(QFile::ReadOnly|QFile::Text);
    //    QString css=fs.readAll();
    //    QTextStream stream(&fs);
    //    QString qss = stream.readAll();
    //    fs.close();
    //    css.replace("\n","");
    //    qDebug()<<"css:"<<qss;
    //    qApp->setStyleSheet(css);
    //    qDebug()<<"shezhi:"<<qApp->styleSheet();

    return a.exec();
}

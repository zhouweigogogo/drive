#ifndef MODEL_CHOOSE_H
#define MODEL_CHOOSE_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <QFileInfo>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <yolo.h>

namespace Ui {
class model_choose;
}

class model_choose : public QMainWindow
{
    Q_OBJECT

public:
    explicit model_choose(QWidget *parent = nullptr);
    ~model_choose();
    void receive_risk(bool rem);

private slots:
    void on_pushButton_4_clicked();
    //保存配置
    void on_pushButton_3_clicked();
    //退出
    void on_search_model_clicked();
    //搜索模型
    void on_model_test_clicked();
    //模型测试
    void on_model_choose_box_currentTextChanged(const QString &currentcoose);
    void updateImage();




private:
    QMap<QString,QString> model_target;
    Ui::model_choose *ui;
    QString modelpath;
    QTimer theTimer;
    cv::VideoCapture videoCap;
    cv::Mat srcImage;
    int playerwidth;
    int playerheight;
    QString taskexits;
    bool isv6;
    bool removelowrisk;

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MODEL_CHOOSE_H

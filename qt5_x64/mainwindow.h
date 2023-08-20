#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <detectpicture.h>
#include <QMessageBox>
#include <QStatusBar>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QToolBar>
#include <theme.h>
#include <model_choose.h>
#include <user_manage.h>
#include <sqliteoperator.h>
#include <QFileInfo>
#include <QFile>
#include <QMediaPlayer>
#include <QMap>
#include <QAbstractItemView>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void to_pushbutton();
    void on_actionopen_triggered();

    void on_actionexit_triggered();

    void on_actionsave_triggered();
    void on_openvideo_clicked();
    void updateImage();
    void on_theme_change_clicked();

    void on_exit_clicked();

    void on_model_choose_clicked();

    void on_user_manage_clicked();

    void on_comboBox_currentIndexChanged(const QString &drivemode);

    void on_mainwindow_init();

    void on_checkBox_stateChanged(int choosen);

    void on_pushButton_2_clicked(QString playvoice);

    void receive_theme(QString thememode,QString imgpath);

    void barrage_animation();

signals:
    void startingDetect(QString,QString,float,float,float,int[2],QString,bool,int,int,bool);
    //开始检测,传递检测数据
    void send_theme(QString);
    void send_risk(bool);

private:
    bool thetimeropen=false;
    QTimer theTimer;
    cv::Mat srcImage;
    cv::VideoCapture videoCap;
    int playerwidth;
    int playerheight;
    Ui::MainWindow *ui;
    QString taskexits;
    float prob_threshold;
    float nms_threshold;
    float focalLength;
    int target_sizes[2];
    QString modeltypes;
    bool isv6;
    detectPicture *detector;

    bool removelowrisk;
    QMap<QString,QString> user_config;

    int currentTime=0;
    bool first=true;
    bool switchmode;

    int single_barrage_time;
    QTimer barrage_timer;
    QStringList barrage_contend;
    int barrage_contend_index=0;
    char* brakingwaring_key = "/brakingwaring";
    double brakingwaring_value = 1;
    char* speed_key = "/speed";
    double speed_value_S = 15;
    double speed_value_P = 1;
    double speed_value_D = 60;
    char* gear_key = "/gear";
    double gear_value_D = 3;
    double gear_value_N = 2;
    double gear_value_S = 4;
    double gear_value_P = 0;

protected:
    void paintEvent(QPaintEvent *e);

};
#endif // MAINWINDOW_H

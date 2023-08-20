#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <mylabel.h>
//#include "client.h"


extern sqlData userinfo;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    taskexits="None";
    ui->setupUi(this);

    ui->pushButton_2->setVisible(false);

    if(userinfo.userPermission!="1"){
        ui->groupBox->setVisible(false);
    }
    ui->label->show();
    connect(&theTimer,&QTimer::timeout,this,&MainWindow::updateImage);
    this->setWindowTitle("智能驾驶辅助系统");
    ui->user_avatar->setScaledContents(true);
    ui->label->setScaledContents(true);
    playerwidth=ui->label->width();
    playerheight=ui->label->height();
    if(userinfo.userConfigure=="None"){
        userinfo.userConfigure=QString("theme:white|drivemode:智能驾驶|removelowrisk:false");
        user_config.insert("theme","white");
        user_config.insert("drivemode","智能驾驶");
        user_config.insert("removelowrisk","false");
        //        qDebug() << "插入成功";
    }else{
        //用户首次登陆初始化配置
        QStringList temp=userinfo.userConfigure.split("|");
        for (int i=0;i<temp.size();i++) {
            QStringList k2v=temp.at(i).split(":");
            user_config.insert(k2v.at(0),k2v.at(1));
            //            qDebug() << k2v.at(0) << ":" << k2v.at(1);
        }
    }


    connect(&barrage_timer,&QTimer::timeout,this,&MainWindow::barrage_animation);
    barrage_timer.setInterval(25);

    //    setWindowFlags(Qt::FramelessWindowHint);
    //    setAttribute(Qt::WA_TranslucentBackground);

    //设置透明样式属性
    ui->comboBox->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->comboBox->view()->parentWidget()->setAttribute(Qt::WA_TranslucentBackground);
    ui->comboBox->view()->parentWidget()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    /*全透明窗口，子控件不透明*/
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置背景色透明（透明的部分，鼠标点击，鼠标信号会透传到z轴底层去）
    setAttribute(Qt::WA_TranslucentBackground,true);

    on_mainwindow_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(taskexits!="None"){
        int choice=QMessageBox::warning(this,"警告","当前检测任务进行中,是否中断？",QMessageBox::Yes,QMessageBox::No);
        if(choice==QMessageBox::Yes){
            thetimeropen=false;
            if(taskexits=="video"){
                theTimer.stop();
                taskexits="None";
                on_pushButton_clicked();
            }else if(taskexits=="image"){
                detector->exit();
                taskexits="None";
                on_mainwindow_init();
                on_pushButton_clicked();
            }else{
                QMessageBox::warning(this,"警告","当发生未知错误,当前为打开图片任务中断");
            }
        }
    }else{
        //        qDebug()<<"after main modetype:"<<modeltypes;
        //打开按钮被点击
        srcImage.release();
        srcImage=cv::Mat();
        this->update();
        //label未清空导致打开文件卡死
        QString imgurl;
        imgurl=QFileDialog::getOpenFileName(this,"open",".","images(*.png *.jpg *.jpeg *.bmp)");
        //获取文件目录
        if(imgurl==""){
            //未打开文件
            //            qDebug()<<"cancel";
        }else{
            //打开了文件
            //            qDebug()<<imgurl;
            detector=new detectPicture;
            connect(this,&MainWindow::startingDetect,detector,&detectPicture::receiveImgUrl);
            //先发送数据
            //            qDebug()<<"先发送数据";
            QString savepath;
            savepath=imgurl.section(".",0,0);
            //用.来分割字符串
            savepath=savepath+"_res.jpg";
            //            qDebug()<<"savepath is:"<<savepath;
            //            qDebug()<<"modeltype is:"<<modeltypes;
            emit startingDetect(imgurl,savepath,prob_threshold,nms_threshold,focalLength,target_sizes,modeltypes,isv6,playerwidth,playerheight,removelowrisk);
            //传递路径
            detector->start();
            taskexits="image";
            //子线程存在标志
            ui->label->setText("loading...");
            connect(detector,&detectPicture::finishUrl,this,[=](cv::Mat saveimg){
                //                qDebug()<<"img detect finished";
                srcImage=saveimg;
                //                qDebug()<<"srcimg received";
                this->update();
                taskexits="None";
            });
            //接收数据并贴图
        }

    }

}

void MainWindow::to_pushbutton()
{
    //    qDebug()<<"ok";
}


void MainWindow::on_actionopen_triggered()
{
    //打开目录被点击
    if(taskexits=="None"){
        MainWindow::on_pushButton_clicked();
    }else{
        QMessageBox::warning(this,"警告","当前检测进行中,请耐心等待!");
    }

}


void MainWindow::on_actionexit_triggered()
{
    //退出目录被点击
    if(taskexits!="None"){
        int choice=QMessageBox::warning(this,"警告","当前检测任务进行中,是否退出？",QMessageBox::Yes,QMessageBox::No);
        if(choice==QMessageBox::Yes){
            QStringList temps;
            QMapIterator<QString, QString> iterator(user_config);
            while (iterator.hasNext()) {
                iterator.next();
                temps.append(QString("%1:%2").arg(iterator.key() , iterator.value()));
            }
            QString tempconfig=temps.join("|");
            //            qDebug()<<tempconfig;
            this->deleteLater();
        }
    }else{
        QStringList temps;
        QMapIterator<QString, QString> iterator(user_config);
        while (iterator.hasNext()) {
            iterator.next();
            temps.append(QString("%1:%2").arg(iterator.key() , iterator.value()));
        }
        QString tempconfig=temps.join("|");
        //        qDebug()<<tempconfig;
        this->deleteLater();
    }

}


void MainWindow::on_actionsave_triggered()
{
    //保存目录被点击//去除
}


void MainWindow::on_openvideo_clicked()
{
    if(taskexits!="None"){
        int choice=QMessageBox::warning(this,"警告","当前检测任务进行中,是否中断？",QMessageBox::Yes,QMessageBox::No);
        if(choice==QMessageBox::Yes){
            thetimeropen=false;
            if(taskexits=="video"){
                theTimer.stop();
                srcImage.release();
                srcImage=cv::Mat();
                this->update();
                taskexits="None";
                on_openvideo_clicked();
            }else if(taskexits=="image"){
                theTimer.stop();
                srcImage.release();
                srcImage=cv::Mat();
                this->update();
                detector->exit();
                taskexits="None";

                on_openvideo_clicked();
            }else{
                QMessageBox::warning(this,"警告","当发生未知错误,当前为打开视频任务中断");
            }
        }
    }else{
        on_mainwindow_init();
        //打开视频被点击
        srcImage.release();
        srcImage=cv::Mat();
        this->update();
        QString videourl="";
        videourl=QFileDialog::getOpenFileName(this,"open",".","videos(*.mp4 *.avi *.wav *.mkv)");
        //获取文件目录
        if(videourl==""){
            //未打开文件
            //            qDebug()<<"cancel";
        }else{
            //打开了文件
            //            qDebug()<<videourl;
            if(videoCap.open(videourl.toStdString())){

                QMessageBox::information(this,"提示","车辆驾驶前，请您注意系好安全带哦~");

                /*client_set*/(speed_key,speed_value_D);
//                client_set(gear_key,gear_value_D);

                srcImage = cv::Mat::zeros(videoCap.get(cv::CAP_PROP_FRAME_HEIGHT), videoCap.get(cv::CAP_PROP_FRAME_WIDTH), CV_8UC3);
                double fps=videoCap.get(cv::CAP_PROP_FPS);
                //                qDebug()<<"该视频帧率为:"<<fps;
                int timeoutsec=int(1000/fps);
                //                qDebug()<<"modeltype is:"<<modeltypes;
                thetimeropen=true;
                theTimer.start(timeoutsec);
                taskexits="video";
            }else{
                //                qDebug()<<"打开视频文件失败!";
            }

        }
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{

    QImage image2 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(image2));
    ui->label->resize(image2.size());
    ui->label->show();
}
void MainWindow::updateImage()
{
    videoCap>>srcImage;
    if(srcImage.data)
    {
        double fps;
        double t = 0;
        Yolo yolo;
        t = (double)cv::getTickCount();
        std::vector<Object> objects;
        yolo.load(modeltypes.toLocal8Bit().data(),target_sizes,prob_threshold,nms_threshold,focalLength);
        if(modeltypes.indexOf("v6")!=-1){
            yolo.detect_v6lite(srcImage,objects);
        }else if(modeltypes.indexOf("v5")!=-1){
            yolo.detect_v5(srcImage, objects);
        }else if (modeltypes.indexOf("v8")!=-1) {
            yolo.detect_v8(srcImage,objects);
        }
        yolo.draw(srcImage,objects,!removelowrisk);
        srcImage=yolo.resizeImage(srcImage,playerwidth,playerheight);
        cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR

        // calculate fps
        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        fps = 1.0 / t;
        char text[32];
        sprintf(text, "FPS=%.2f", fps);

        int baseLine = 0;
        cv::Size label_size = cv::getTextSize(text, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);

        int y = 0;
        int x = srcImage.cols - label_size.width;

        cv::rectangle(srcImage, cv::Rect(cv::Point(x, y), cv::Size(label_size.width, label_size.height + baseLine)),
                      cv::Scalar(255, 255, 255), -1);

        cv::putText(srcImage, text, cv::Point(x, y + label_size.height),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

        this->update();  //发送刷新消息
        //start
        if(switchmode){
            currentTime++;
            // tip
            double videoFPS=videoCap.get(cv::CAP_PROP_FPS);
            if (first == true || (int)currentTime/videoFPS > 5){
                first = false;
                for (int i = 0; i < objects.size(); i++) {
                    // person distance < 10

                    if (objects[i].label == 0 && objects[i].distance < 10 ){
                        currentTime = 0;
//                        client_set(brakingwaring_key,brakingwaring_value);
//                        client_set(speed_key,speed_value_S);
//                        client_set(gear_key,gear_value_S);
                        //todo:名字
                        on_pushButton_2_clicked("前方行人_请立即避让.mp3");
                        if(barrage_contend.size()>3){
                            barrage_contend.removeAt(barrage_contend_index);
                        }
                        barrage_contend.insert(barrage_contend_index,"前方行人,请立即避让");
                        barrage_contend_index=(barrage_contend_index+1)%4;
                        //                        qDebug()<<"前方行人,请立即避让<<barrage_contend:"<<barrage_contend;
                        if(barrage_contend.size()>3){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                            ui->barrage_fourth->setText(barrage_contend.at(3));
                        }else if(barrage_contend.size()>2){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                        }else if(barrage_contend.size()>1){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                        }else if(barrage_contend.size()>0){
                            ui->barrage_first->setText(barrage_contend.at(0));
                        }
                        barrage_timer.start();

                        break;
                    }
                    // car distance < 10
                    else if (objects[i].label == 1 && objects[i].distance < 10) {
                        currentTime = 0;
//                        client_set(brakingwaring_key,brakingwaring_value);
//                        client_set(speed_key,speed_value_S);
//                        client_set(gear_key,gear_value_S);
                        on_pushButton_2_clicked("前方车辆_请立即减速.mp3");
                        if(barrage_contend.size()>3){
                            barrage_contend.removeAt(barrage_contend_index);
                        }
                        barrage_contend.insert(barrage_contend_index,"前方车辆,请立即减速");
                        barrage_contend_index=(barrage_contend_index+1)%4;
                        if(barrage_contend.size()>3){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                            ui->barrage_fourth->setText(barrage_contend.at(3));
                        }else if(barrage_contend.size()>2){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                        }else if(barrage_contend.size()>1){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                        }else if(barrage_contend.size()>0){
                            ui->barrage_first->setText(barrage_contend.at(0));
                        }
                        barrage_timer.start();
                        break;
                    }
                    // car 15 <= distance <= 30
                    else if (objects[i].label == 1 && (objects[i].distance >=10 && objects[i].distance <= 30)) {
                        printf("3\n");
                        currentTime = 0;
                        on_pushButton_2_clicked("前方车辆_请注意减速.mp3");
                        if(barrage_contend.size()>3){
                            barrage_contend.removeAt(barrage_contend_index);
                        }
                        barrage_contend.insert(barrage_contend_index,"前方车辆,请注意减速");
                        barrage_contend_index=(barrage_contend_index+1)%4;

                        if(barrage_contend.size()>3){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                            ui->barrage_fourth->setText(barrage_contend.at(3));
                        }else if(barrage_contend.size()>2){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                        }else if(barrage_contend.size()>1){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                        }else if(barrage_contend.size()>0){
                            ui->barrage_first->setText(barrage_contend.at(0));
                        }
                        barrage_timer.start();
                        break;
                    }
                    // tf_light
                    else if (objects[i].label == 2 || objects[i].label == 3 || objects[i].label == 4){
                        printf("4\n");
                        currentTime = 0;
                        on_pushButton_2_clicked("前方交通灯_请注意观察.mp3");
                        if(barrage_contend.size()>3){
                            barrage_contend.removeAt(barrage_contend_index);
                        }
                        barrage_contend.insert(barrage_contend_index,"前方交通灯,请注意观察");
                        barrage_contend_index=(barrage_contend_index+1)%4;
                        qDebug()<<"前方交通灯,请注意观察<<barrage_contend:"<<barrage_contend;
                        if(barrage_contend.size()>3){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                            ui->barrage_fourth->setText(barrage_contend.at(3));
                        }else if(barrage_contend.size()>2){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                        }else if(barrage_contend.size()>1){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                        }else if(barrage_contend.size()>0){
                            ui->barrage_first->setText(barrage_contend.at(0));
                        }
                        barrage_timer.start();
                        break;
                    }
                    // tf_sign
                    else if (objects[i].label == 4) {
                        printf("5\n");
                        currentTime = 0;
                        on_pushButton_2_clicked("前方交通标志_请注意观察.mp3");
                        if(barrage_contend.size()>3){
                            barrage_contend.removeAt(barrage_contend_index);
                        }
                        barrage_contend.insert(barrage_contend_index,"前方交通标志,请注意观察");
                        barrage_contend_index=(barrage_contend_index+1)%4;
                        qDebug()<<"前方交通标志,请注意观察<<barrage_contend:"<<barrage_contend;
                        if(barrage_contend.size()>3){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                            ui->barrage_fourth->setText(barrage_contend.at(3));
                        }else if(barrage_contend.size()>2){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                            ui->barrage_third->setText(barrage_contend.at(2));
                        }else if(barrage_contend.size()>1){
                            ui->barrage_first->setText(barrage_contend.at(0));
                            ui->barrage_second->setText(barrage_contend.at(1));
                        }else if(barrage_contend.size()>0){
                            ui->barrage_first->setText(barrage_contend.at(0));
                        }
                        barrage_timer.start();
                        break;
                    }
                }
            }
        }
    }else{
        theTimer.stop();
        taskexits="None";
        //        car_initialize();
//        client_set(speed_key,speed_value_P);
//        client_set(gear_key,gear_value_P);
        on_mainwindow_init();
    }

}


void MainWindow::on_theme_change_clicked()
{
    //更换主题
    theme *themes=new theme();
    themes->setAttribute(Qt::WA_DeleteOnClose);
    theTimer.stop();
    themes->show();
    //设置父子窗口的参考
    connect(this,&MainWindow::send_theme,themes,&theme::receive_theme);
    emit send_theme(user_config["theme"]);

    connect(themes,&theme::update_theme,this,&MainWindow::receive_theme);
    connect(themes,&MainWindow::destroyed,this,[=](){
        if(thetimeropen){
            theTimer.start();
        }
        on_mainwindow_init();
        this->setVisible(true);
    });
    this->setVisible(false);
}

void MainWindow::on_exit_clicked()
{
    //退出按钮被点击
    if(taskexits!="None"){
        int choice=QMessageBox::warning(this,"警告","当前检测任务进行中,是否退出？",QMessageBox::Yes,QMessageBox::No);
        if(choice==QMessageBox::Yes){
            QStringList temps;
            QMapIterator<QString, QString> iterator(user_config);
            while (iterator.hasNext()) {
                iterator.next();
                temps.append(QString("%1:%2").arg(iterator.key() , iterator.value()));

            }
            QString tempconfig=temps.join("|");
            //            qDebug()<<"tempconfig"<<tempconfig;
            SqliteOperator sqlop;
            userinfo.userConfigure=tempconfig;
            sqlop.modifyData(userinfo.userId,userinfo.userName,userinfo.userPassword,userinfo.userPermission,userinfo.userConfigure);
            //            car_initialize();
//            client_set(speed_key,speed_value_P);
//            client_set(gear_key,gear_value_P);
            this->deleteLater();
        }
    }else{
        QStringList temps;
        QMapIterator<QString, QString> iterator(user_config);
        while (iterator.hasNext()) {
            iterator.next();
            temps.append(QString("%1:%2").arg(iterator.key() , iterator.value()));
        }
        QString tempconfig=temps.join("|");
        //        qDebug()<<"tempconfig"<<tempconfig;
        SqliteOperator sqlop;
        userinfo.userConfigure=tempconfig;
        sqlop.modifyData(userinfo.userId,userinfo.userName,userinfo.userPassword,userinfo.userPermission,userinfo.userConfigure);
        //        car_initialize();
//        client_set(speed_key,speed_value_P);
//        client_set(gear_key,gear_value_P);
        this->deleteLater();
    }

}

void MainWindow::on_model_choose_clicked()
{
    //模型选择
    model_choose *chooser=new model_choose();
    theTimer.stop();
    chooser->show();
    emit send_risk(removelowrisk);
    chooser->setAttribute(Qt::WA_DeleteOnClose);
    //设置父子窗口的参考
    connect(chooser,&MainWindow::destroyed,this,[=](){
        if(thetimeropen){
            theTimer.start();
        }
        on_mainwindow_init();
        this->setVisible(true);
    });
    this->setVisible(false);
}

void MainWindow::on_user_manage_clicked()
{
    //用户管理
    user_manage *manager=new user_manage();
    theTimer.stop();
    manager->show();
    manager->setAttribute(Qt::WA_DeleteOnClose);
    //设置父子窗口的参考
    connect(manager,&MainWindow::destroyed,this,[=](){
        if(thetimeropen){
            theTimer.start();
        }
        on_mainwindow_init();
        this->setVisible(true);
    });
    this->setVisible(false);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &drivemode)
{
    //更新用户配置
    user_config.insert("drivemode",drivemode);
    if(drivemode=="智能驾驶"){
        switchmode=true;
        on_mainwindow_init();
        //        qDebug()<<"现在的驾驶模式为:"<<drivemode;
    }else if(drivemode=="普通驾驶"){
        switchmode=false;
        on_mainwindow_init();
        //        qDebug()<<"现在的驾驶模式为:"<<drivemode;
    }
}

void MainWindow::on_mainwindow_init()
{
    //mainwindow数据初始化



    //弹幕label初始化
    barrage_contend.clear();
    barrage_contend_index=0;
    single_barrage_time=0;
    ui->barrage_first->setGeometry(ui->barrage_first->x(),125,ui->barrage_first->width(),ui->barrage_first->height());
    ui->barrage_second->setGeometry(ui->barrage_second->x(),165,ui->barrage_second->width(),ui->barrage_second->height());
    ui->barrage_third->setGeometry(ui->barrage_third->x(),205,ui->barrage_third->width(),ui->barrage_third->height());
    ui->barrage_fourth->setGeometry(ui->barrage_fourth->x(),245,ui->barrage_fourth->width(),ui->barrage_fourth->height());


    //用户配置初始化(程序初始化数据库读取)主题、屏蔽低风险、驾驶模式...
    ui->comboBox->setCurrentText(user_config["drivemode"]);
    if(user_config["drivemode"]=="智能驾驶"){
        switchmode=true;
    }else{
        switchmode=false;
    }
    QString removerisk=user_config["removelowrisk"];
    if(removerisk=="true"){
        removelowrisk=true;
        ui->checkBox->setCheckState(Qt::CheckState::Checked);
        //        qDebug()<<"初始化屏蔽低风险:"<<removelowrisk;
    }else{
        removelowrisk=false;
        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
        //        qDebug()<<"初始化屏蔽低风险:"<<removelowrisk;
    }
    QString theme=user_config["theme"];
    //    qDebug()<<"mainwindow主题:"<<theme;
    if(theme.indexOf("diy")!=-1){
        //diy主题
        QFile fp(":/qtcss/diypre.qss");
        fp.open(QFile::ReadOnly|QFile::Text);
        QString pretext=fp.readAll();
        fp.close();
        //        qDebug()<<"theme.split:"<<theme.split("@");
        pretext.replace("userimageurl",theme.split("@")[1]);
        pretext.replace("\n","");
        qApp->setStyleSheet(pretext);
    }else{
        QString themepath=":/qtcss/"+theme+".qss";
        //todo:添加qss
        //    qDebug()<<"初始化主题文件路径:"<<themepath;
        QFile fs(themepath);
        fs.open(QFile::ReadOnly|QFile::Text);
        QString css=fs.readAll();
        css.replace("\n","");
        qApp->setStyleSheet(css);
    }
    //用户配置初始化结束
    //昵称初始化
    SqliteOperator sqlop;
    QStringList jk=sqlop.queryData(userinfo.userId);
    userinfo.userName=jk.at(0);
    //    qDebug()<<"in mainwindow init:"<<userinfo.userName;
    ui->username_label->setText(userinfo.userName);
    //读取模型信息
    QString pwd=QCoreApplication::applicationDirPath();
    QString modelsinitpath=pwd+"/models/model.ini";
    QString initial_modelapth=pwd+"/models/yolov6lite_l1.ini";
    //默认模型ini文件是否存在
    QFileInfo fp(modelsinitpath);
    if(fp.isFile()){
        //打开默认ini模型文件
        QFile fp(modelsinitpath);
        fp.open(QFile::ReadOnly);
        //读取默认模型的ini配置
        QString readmodel=QString(fp.readAll());
        fp.close();
        readmodel.replace("\n","");
        QString param=readmodel.split(".")[0]+".param";
        QString bin=readmodel.split(".")[0]+".bin";
        QFileInfo fs(readmodel);
        if(!fs.isFile()){
            //默认模型配置文件不存在
            QFile fp(modelsinitpath);
            fp.open(QFile::WriteOnly|QFile::Text);
            fp.write(initial_modelapth.toLocal8Bit());
            fp.close();
            readmodel=initial_modelapth;
            //            qDebug()<<readmodel;
        }
        QFile f(readmodel);
        f.open(QFile::ReadOnly);
        QString modelcontent=QString(f.readAll());
        QStringList modelparams=modelcontent.split("\n");
        //        modelparams.removeLast();
        //去除尾部空串
        prob_threshold=modelparams.at(3).toFloat();
        //        qDebug()<<"prob_threshold="<<prob_threshold;
        nms_threshold=modelparams.at(4).toFloat();
        //        qDebug()<<"nms_threshold="<<nms_threshold;
        focalLength=modelparams.at(5).toFloat();
        //        qDebug()<<"focalLength="<<focalLength;
        int w,h;
        w=modelparams.at(2).split(",").at(0).toInt();
        //        qDebug()<<"w="<<w;
        h=modelparams.at(2).split(",").at(1).toInt();
        //        qDebug()<<"h="<<h;
        target_sizes[0]=w;
        target_sizes[1]=h;
        QStringList ts=readmodel.split("/");
        readmodel=ts.at(ts.size()-1);
        modeltypes=readmodel.section(".",0,0);
        int v6=readmodel.indexOf("v6");
        if(v6==-1){
            isv6=false;
        }else{
            isv6=true;
        }
    }else{
        QMessageBox::warning(this,"警告","model.ini文件损坏");
    }
}




void MainWindow::on_checkBox_stateChanged(int choosen)
{
    //0为未选中2为选中，1为半选中这里不需要
    if(choosen==0){
        removelowrisk=false;
        user_config.insert("removelowrisk","false");
    }else{
        removelowrisk=true;
        user_config.insert("removelowrisk","true");
    }
}

void MainWindow::on_pushButton_2_clicked(QString playvoice)
{
    QMediaPlayer *player = new QMediaPlayer;
    QString pwd=QCoreApplication::applicationDirPath();
    QString path=pwd+"/voice/"+playvoice;
    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(50);
    player->play();
}

void MainWindow::receive_theme(QString thememode, QString imgpath)
{
    //接受主题更换的参数()//diy主题的图片路径
    if(thememode=="diy"){
        user_config.insert("theme",thememode+"@"+imgpath);
        //        qDebug()<<"接受主题："<<thememode+"@"+imgpath;
    }else{
        user_config.insert("theme",thememode);
        //        qDebug()<<"接受主题："<<thememode;
    }

}

void MainWindow::barrage_animation()
{
    //弹幕动画
    if(single_barrage_time<40){
        ui->barrage_first->setGeometry(ui->barrage_first->x(),ui->barrage_first->y()-1,ui->barrage_first->width(),ui->barrage_first->height());
        if(ui->barrage_first->y()<-29){
            ui->barrage_first->setGeometry(ui->barrage_first->x(),130,ui->barrage_first->width(),ui->barrage_first->height());
        }
        ui->barrage_second->setGeometry(ui->barrage_second->x(),ui->barrage_second->y()-1,ui->barrage_second->width(),ui->barrage_second->height());
        if(ui->barrage_second->y()<-29){
            ui->barrage_second->setGeometry(ui->barrage_second->x(),130,ui->barrage_second->width(),ui->barrage_second->height());
        }
        ui->barrage_third->setGeometry(ui->barrage_third->x(),ui->barrage_third->y()-1,ui->barrage_third->width(),ui->barrage_third->height());
        if(ui->barrage_third->y()<-29){
            ui->barrage_third->setGeometry(ui->barrage_third->x(),130,ui->barrage_third->width(),ui->barrage_third->height());
        }
        ui->barrage_fourth->setGeometry(ui->barrage_fourth->x(),ui->barrage_fourth->y()-1,ui->barrage_fourth->width(),ui->barrage_fourth->height());
        if(ui->barrage_fourth->y()<-29){
            ui->barrage_fourth->setGeometry(ui->barrage_fourth->x(),130,ui->barrage_fourth->width(),ui->barrage_fourth->height());
        }
        single_barrage_time+=1;
    }else{
        //动画完成
        single_barrage_time=0;

        barrage_timer.stop();
    }

}

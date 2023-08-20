#include "model_choose.h"
#include "ui_model_choose.h"

model_choose::model_choose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::model_choose)
{
    ui->setupUi(this);
    this->setWindowTitle("模型配置界面");
    QString pwd=QCoreApplication::applicationDirPath();
    QStringList temp;
    temp.append(pwd);
    temp.append(QString("models"));
    modelpath=temp.join("/");
    connect(&theTimer,&QTimer::timeout,this,&model_choose::updateImage);


    ui->label->setWordWrap(true);
    //设置无边框窗口
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置背景色透明（透明的部分，鼠标点击，鼠标信号会透传到z轴底层去）
    setAttribute(Qt::WA_TranslucentBackground,true);

    model_target.insert("yolov6lite_s","320,320");
    model_target.insert("yolov6lite-m","320,320");
    model_target.insert("yolov6lite-l0","320,320");
    model_target.insert("yolov6lite-l1","320,192");
    model_target.insert("yolov6lite-l2","224,128");
    //    qDebug()<<"model_target:"<<model_target["yolov8"];
    //结果为找不到的值返回为空
}

model_choose::~model_choose()
{
    delete ui;
}

void model_choose::receive_risk(bool rem)
{
    removelowrisk=rem;
}

void model_choose::on_pushButton_4_clicked()
{
    //退出
    if(ui->model_choose_box->count()>0){
        QString choosenModel=ui->model_choose_box->currentText();
        QString initstr=modelpath+"/"+choosenModel+".ini";
        QFileInfo fsave(initstr);
        if(fsave.isFile())
        {
            QString initpath=modelpath+"/model.ini";
            QFile fp(initpath);
            fp.open(QFile::WriteOnly|QFile::Text);
            fp.write(initstr.toLocal8Bit());
            fp.close();
            QMessageBox::information(this,"操作信息","模型选择已更新");
        }else{
            QMessageBox::information(this,"模型配置","模型文件不存在,选择未更新");
        }

    }

    this->deleteLater();
}

void model_choose::on_pushButton_3_clicked()
{
    //保存配置
    int comnum=ui->model_choose_box->count();
    if(comnum==0){
        QMessageBox::warning(this,"警告","当前无选中模型");
    }else{
        QString choosenmodel=ui->model_choose_box->currentText();
        QString currentpath=modelpath+"/"+choosenmodel+".ini";
//        qDebug()<<currentpath;
        if(ui->foclenth_edit->text().size()<=0 | ui->NSM_edit->text().size()<=0 | ui->confi_edit->text().size()<=0){
            QMessageBox::warning(this,"警告","模型参数不能为空");
        }else{
            QFile fp(currentpath);
            fp.open(QFile::WriteOnly|QFile::Text);
            QString writestr=modelpath+"/"+choosenmodel+".param\n";
            fp.write(writestr.toLocal8Bit());
            writestr=modelpath+"/"+choosenmodel+".bin\n";
            fp.write(writestr.toLocal8Bit());
            writestr=model_target.value(choosenmodel,"640,640\n");
            fp.write(writestr.toLocal8Bit());
            //            QString confi=QString(ui->foclenth_edit->text());
            //            confi=QString("%1").arg(confi.toFloat());
            //            qDebug()<<"conf="<<confi;
            writestr=QString("%1\n%2\n%3").arg(ui->confi_edit->text(),ui->NSM_edit->text(),ui->foclenth_edit->text());
            fp.write(writestr.toLocal8Bit());
            fp.close();
            QMessageBox::information(this,"操作信息","模型参数保存成功");
        }
    }
}



void model_choose::on_search_model_clicked()
{
    //搜索可用模型

    QDir* dirinfo = new QDir(modelpath);
    if (!dirinfo->exists()) {
        delete dirinfo,dirinfo = nullptr;
        return;
    }
//    qDebug()<<"model choose start";
    dirinfo->setNameFilters(QStringList("*.param"));
    QStringList fileList = dirinfo->entryList(QDir::Files);
//    qDebug()<<"fileList:"<<fileList;
    fileList.removeOne(".");
    fileList.removeOne("..");

    QStringList res;
    for (int i=0;i<fileList.size();i++) {
        QString bintemp=fileList.at(i);
        QStringList temppath=bintemp.split(".");
        temppath.removeLast();
        QString tp=temppath.join(".");//去除param后缀
        temppath.append("bin");
        bintemp=temppath.join(".");
        QString binpath=QString("%1/%2").arg(modelpath,bintemp);
        QFileInfo fj(binpath);
        if(fj.isFile()){
            //存在与之对应的bin文件则添加
            res.append(tp);
        }
    }
//    qDebug()<<"res:"<<res;
    ui->model_choose_box->clear();
    ui->model_choose_box->addItems(res);
    delete dirinfo,dirinfo = nullptr;
    return;

}

void model_choose::on_model_test_clicked()
{
    //模型测试
    if(ui->model_choose_box->count()==0){
        QMessageBox::information(this,"模型配置","当前无模型选中");
        return;
    }else if(ui->foclenth_edit->text()=="" || ui->confi_edit->text()=="" ||ui->NSM_edit->text()==""){
        QMessageBox::information(this,"模型配置","模型配置未加载");
        return;
    }
    if(taskexits!="None"){
        theTimer.stop();
        taskexits="None";
        on_model_test_clicked();
    }else{
        //模型检测被点击
        srcImage.release();
        srcImage=cv::Mat();
        this->update();
        QString videourl=modelpath+"/modelTest.mp4";
        //获取文件目录
        QFileInfo fp(videourl);
        if(!fp.isFile()){
            //未打开文件
            QMessageBox::information(this,"文件丢失","模型测试视频不存在");
        }else{
            //打开了文件
//            qDebug()<<videourl;
            if(videoCap.open(videourl.toStdString())){
                srcImage = cv::Mat::zeros(videoCap.get(cv::CAP_PROP_FRAME_HEIGHT), videoCap.get(cv::CAP_PROP_FRAME_WIDTH), CV_8UC3);
                double fps=videoCap.get(cv::CAP_PROP_FPS);;
                int timeoutsec=int(1000/fps);
                theTimer.start(timeoutsec);
                taskexits="video";
            }else{
//                qDebug()<<"打开模型测试视频文件失败!";
            }

        }
    }
}

void model_choose::on_model_choose_box_currentTextChanged(const QString &currentchoose)
{
//    qDebug()<<"model init";
    QString readmodel=modelpath+"/"+currentchoose+".ini";
    QFile f(readmodel);
    f.open(QFile::ReadOnly);
    QFileInfo fs(readmodel);
    if(fs.isFile()){
        QString modelcontent=QString(f.readAll());
//        qDebug()<<modelcontent;
        QStringList modelparams=modelcontent.split("\n");
        //    modelparams.removeLast();
        //去除尾部空串 无须去除
        QString p_threshold=modelparams.at(3);
        QString nms_threshold=modelparams.at(4);
        QString focalLength=modelparams.at(5);
        ui->foclenth_edit->setText(focalLength);
        ui->NSM_edit->setText(nms_threshold);
        ui->confi_edit->setText(p_threshold);
        int v6=currentchoose.indexOf("v6");
        if(v6==-1){
            isv6=false;
        }else{
            isv6=true;
        }
    }else{
        QMessageBox::information(this,"模型加载","模型加载失败");
        ui->confi_edit->setText("");
        ui->NSM_edit->setText("");
        ui->foclenth_edit->setText("");
//        qDebug()<<"文件不存在";
    }


}

void model_choose::updateImage()
{
    videoCap>>srcImage;
    if(srcImage.data)
    {
        double fps;
        double t = 0;
        Yolo yolo;
        t = (double)cv::getTickCount();
        std::vector<Object> objects;
        int target_sizes[2];
        playerwidth=ui->video_label->width();
        playerheight=ui->video_label->height();
//        qDebug()<<playerwidth<<playerheight;
        QString currentmodel=ui->model_choose_box->currentText();
        QStringList target=model_target.value(currentmodel,"640,640").split(",");
        target_sizes[0]=target[0].toInt();
        target_sizes[1]=target[1].toInt();
        //
        float prob_threshold=ui->confi_edit->text().toFloat();
        float nms_threshold=ui->NSM_edit->text().toFloat();
        float focalLength=ui->foclenth_edit->text().toFloat();
        yolo.load(currentmodel.toLocal8Bit().data(),target_sizes,prob_threshold,nms_threshold,focalLength);
        if(currentmodel.indexOf("v6")!=-1){
            yolo.detect_v6lite(srcImage,objects);
        }else if(currentmodel.indexOf("v5")!=-1){
            yolo.detect_v5(srcImage, objects);
        }else if (currentmodel.indexOf("v8")!=-1) {
            yolo.detect_v8(srcImage,objects);
        }

        yolo.draw(srcImage,objects,!removelowrisk);
//        qDebug()<<playerwidth<<playerheight;
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
    }else{
        theTimer.stop();
        taskexits="None";
    }

}
void model_choose::paintEvent(QPaintEvent *e)
{

    QImage image2 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    ui->video_label->setPixmap(QPixmap::fromImage(image2));
//    ui->video_label->resize(image2.size());
    ui->video_label->show();
}

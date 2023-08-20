#include "theme.h"
#include "ui_theme.h"

extern sqlData userinfo;
theme::theme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::theme)
{
    ui->setupUi(this);
    changed=false;
    //所有单选框加入按钮组进行管理
    QButtonGroup *choosen=new QButtonGroup(this);
    choosen->addButton(ui->radioButton);
    choosen->addButton(ui->radioButton_2);
    choosen->addButton(ui->radioButton_3);
    choosen->addButton(ui->radioButton_4);
    choosen->addButton(ui->radioButton_5);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置背景色透明（透明的部分，鼠标点击，鼠标信号会透传到z轴底层去）
    setAttribute(Qt::WA_TranslucentBackground,true);

}

theme::~theme()
{
    delete ui;
}

void theme::on_pushButton_clicked()
{
    //退出
    if(changed){
        int choice=QMessageBox::information(this,"提示","当前配置未保存,是否保存？",QMessageBox::Yes,QMessageBox::No);
        if(choice==QMessageBox::Yes){
            on_pushButton_2_clicked();
            this->deleteLater();
        }
    }

    this->deleteLater();
}

void theme::on_pushButton_2_clicked()
{
    changed=false;
    if(ui->radioButton->isChecked())
    {
        emit update_theme("white","");
        //white
    }else if(ui->radioButton_2->isChecked()){
        emit update_theme("gray","");
        //gray
    }else if(ui->radioButton_3->isChecked()){
        emit update_theme("pink","");
        //pink
    }else if(ui->radioButton_4->isChecked()){
        emit update_theme("blue","");
        //blue
    }else if(ui->radioButton_5->isChecked()){
        emit update_theme("diy",imgurl);
        //diy
    }
    QMessageBox::information(this,"主题","主题保存成功");
    //保存
}

void theme::on_radioButton_5_clicked()
{
    //自定义按钮
    imgurl=QFileDialog::getOpenFileName(this,"open",".","images(*.png *.jpg *.jpeg *.bmp)");

    if(imgurl!=""){
        changed=true;
        ui->radioButton_5->setChecked(true);
        //todo:绑定用户图片
        QStringList newimg=imgurl.split("/");
        newimg.removeLast();
        newimg.append(userinfo.userId);

        // 读取原始图片:生成透明图片
        cv::Mat image = cv::imread(imgurl.toLocal8Bit().data());
        // 创建一个与原始图片大小相同的透明图片
        cv::Mat transparent_image(image.size(), CV_8UC4);
        // 将原始图片复制到透明图片的RGB通道
        cv::cvtColor(image, transparent_image, cv::COLOR_BGR2BGRA);
        // 设置透明度
        int alpha = 128; // 透明度范围从0到255，数值越大越不透明
        cv::Mat alpha_channel(image.size(), CV_8UC1, cv::Scalar(alpha));
        cv::Mat channels[4];
        cv::split(transparent_image, channels);
        channels[3] = alpha_channel;
        cv::merge(channels, 4, transparent_image);
        // 保存透明图片
        imgurl=newimg.join("/")+".png";
        cv::imwrite(imgurl.toLocal8Bit().data(), transparent_image);
        if(ui->radioButton_5->parent()->parent()!=ui->current_theme)
        {
            //当前主题不是选中主题:diy仅交换位置，转移父容器，由于可能会改变图片，因此只要选中了图片就加载qss
            //获取交换主题的信息
            QWidget* clickparent=ui->radioButton_5->parentWidget();
            QRect clickcomponent=ui->radioButton_5->parentWidget()->geometry();
            QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
            QRect currentcomponent=currentwidget->geometry();
            //转移从属
            clickparent->setParent(ui->current_theme);
            clickparent->setGeometry(currentcomponent);
            currentwidget->setParent(ui->widget_7);
            currentwidget->setGeometry(clickcomponent);
            currentwidget->show();
            clickparent->show();

            //加载diyqss;
            QFile fp(":/qtcss/diypre.qss");
            fp.open(QFile::ReadOnly|QFile::Text);
            QString pretext=fp.readAll();
            fp.close();
            pretext=pretext.replace("userimageurl",imgurl);
            pretext=pretext.replace("\n","");
            qApp->setStyleSheet(pretext);
        }
    }else{
        //啥也不做
    }
}

void theme::receive_theme(QString themes)
{
    //接收主题并初始化（注意主窗口需在主题窗口创建后发送信号）
    usertheme=themes;
//    qDebug()<<"in theme is:"<<themes;
    if(usertheme=="white"){
        ui->radioButton->setChecked(true);
    }else if(usertheme=="gray"){
        ui->radioButton_2->setChecked(true);
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton_2->parentWidget();
        QRect clickcomponent=ui->radioButton_2->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();

    }else if(usertheme=="pink"){
        ui->radioButton_3->setChecked(true);
        QWidget* clickparent=ui->radioButton_3->parentWidget();
        QRect clickcomponent=ui->radioButton_3->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();
    }else if(usertheme=="blue"){
        ui->radioButton_4->setChecked(true);
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton_4->parentWidget();
        QRect clickcomponent=ui->radioButton_4->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();
    }else if(usertheme.indexOf("diy")!=-1){
        ui->radioButton_5->setChecked(true);
        ui->label_5->setText("");
        //diy
        //获取交换主题的信息在
        QWidget* clickparent=ui->radioButton_5->parentWidget();
        QRect clickcomponent=ui->radioButton_5->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();
    }else{
        QMessageBox::information(this,"信息","用户配置出错");
    }
    qApp->setStyleSheet(qApp->styleSheet());
}

void theme::on_radioButton_clicked()
{

    if(ui->radioButton->parent()->parent()!=ui->current_theme)
    {
        //当前主题不是选中主题:
        changed=true;
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton->parentWidget();
        QRect clickcomponent=ui->radioButton->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();

        //此页面更新qss,当前点击的是white
        QFile fp(":/qtcss/white.qss");
        fp.open(QFile::ReadOnly|QFile::Text);
        QString newstyle=fp.readAll();
        qApp->setStyleSheet(newstyle);
        fp.close();
    }
}

void theme::on_radioButton_2_clicked()
{
    //冷漠灰
    if(ui->radioButton_2->parent()->parent()!=ui->current_theme)
    {
        //当前主题不是选中主题:
        changed=true;
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton_2->parentWidget();
        QRect clickcomponent=ui->radioButton_2->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();

        //此页面更新qss,当前点击的是gray
        QFile fp(":/qtcss/gray.qss");
        fp.open(QFile::ReadOnly|QFile::Text);
        QString newstyle=fp.readAll();
        qApp->setStyleSheet(newstyle);
        fp.close();
    }
//    qDebug()<<"this->styleSheet"<<this->styleSheet();
}

void theme::on_radioButton_3_clicked()
{
    //甜心粉
    if(ui->radioButton_3->parent()->parent()!=ui->current_theme)
    {
        //当前主题不是选中主题:
        changed=true;
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton_3->parentWidget();
        QRect clickcomponent=ui->radioButton_3->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();
        //此页面更新qss,当前点击的是pink
        QFile fp(":/qtcss/pink.qss");
        fp.open(QFile::ReadOnly|QFile::Text);
        QString newstyle=fp.readAll();
        qApp->setStyleSheet(newstyle);
        fp.close();
    }

}

void theme::on_radioButton_4_clicked()
{
    //天空蓝
    if(ui->radioButton_4->parent()->parent()!=ui->current_theme)
    {
        //当前主题不是选中主题:
        changed=true;
        //获取交换主题的信息
        QWidget* clickparent=ui->radioButton_4->parentWidget();
        QRect clickcomponent=ui->radioButton_4->parentWidget()->geometry();
        QWidget* currentwidget=ui->current_theme->findChild<QWidget*>();
        QRect currentcomponent=currentwidget->geometry();
        //转移从属
        clickparent->setParent(ui->current_theme);
        clickparent->setGeometry(currentcomponent);
        currentwidget->setParent(ui->widget_7);
        currentwidget->setGeometry(clickcomponent);
        currentwidget->show();
        clickparent->show();

        //此页面更新qss,当前点击的是blue
        QFile fp(":/qtcss/blue.qss");
        fp.open(QFile::ReadOnly|QFile::Text);
        QString newstyle=fp.readAll();
        qApp->setStyleSheet(newstyle);
        fp.close();
    }
}

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"
#include "md5.h"

sqlData userinfo;

loginwindow::loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwindow)
{

    SqliteOperator sqloprator;
    QString str1 = QString("userInfo");
    if(!sqloprator.isTableExist(str1)){
        //数据库不存在
        sqloprator.createTable();
    }
    QStringList res;

    SqliteOperator sqlop= SqliteOperator();
    res=sqlop.queryData("rooter");
    if(res.at(0)=="NONE"){
        //不存在root用户
        md5 locker;
        QString temp=QString("rooter");
        string passwdstring=(const char*)temp.toLocal8Bit();
        QString passwd=QString::fromLocal8Bit(locker.encode(passwdstring).data());
        QString userid=QString("rooter");
        QString username=QString("管理员");
        sqlData insertroot;
        insertroot.userId=userid;
        insertroot.userName=username;
        insertroot.userPassword=passwd;
        insertroot.userPermission=QString("1");
        insertroot.userConfigure=QString("None");
//        qDebug()<<"rooter 初始化:"<<insertroot.userConfigure;
        sqlop.singleInsertData(insertroot);
    }
//    sqlop.queryTable();

    //创建数据表
    ui->setupUi(this);
    //设置控件提示
    ui->idLineedit->setToolTip("请输入6-50字符的数字或英文");

    ui->passwdLineedit->setToolTip("请输入6-50字符的数字或英文");
    this->setWindowTitle("智能驾驶辅助系统");

    QString pwd=QCoreApplication::applicationDirPath();
    QFile fs(pwd+"/qtcss/login.qss");
    fs.open(QFile::ReadOnly|QFile::Text);
    QString css=fs.readAll();

    fs.close();
    css=css.replace("\n","");
    css=css.replace("softwarepwd",pwd);
//    qDebug()<<pwd;
//    qDebug()<<"css:"<<css;
    this->setStyleSheet(css);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_loginButton_clicked()
{
    //登录按钮
    QString idstr=ui->idLineedit->text();
    QString passwd=ui->passwdLineedit->text();
    if(idstr.size()<6||idstr.size()>50||passwd.size()<6||passwd.size()>50)
    {
        //输入不合法
        QMessageBox::warning(this,"警告","输入不合法,请重新输入,鼠标悬停查看输入条件");
    }else{

        QStringList res;

        SqliteOperator sqlop= SqliteOperator();
        res=sqlop.queryData(idstr);

        if(res.at(0)!="NONE"){
            //存在此用户
            ui->passwdLineedit->setText("");
            QString passwdres=res.at(1);
            md5 locker;
            string passwdstring=(const char*)passwd.toLocal8Bit();
            passwd=QString::fromLocal8Bit(locker.encode(passwdstring).data());
            if(passwd==passwdres){
                //账号密码正确
                ui->idLineedit->setText("");
                userinfo.userId=idstr;
                userinfo.userName=res.at(0);
                userinfo.userPassword=res.at(1);
                userinfo.userPermission=res.at(2);
                userinfo.userConfigure=res.at(3);
                MainWindow *mainwins=new MainWindow(this);
                mainwins->show();
                //重置主窗口主题
                mainwins->setAttribute(Qt::WA_DeleteOnClose);
                //设置父子窗口的参考
                connect(mainwins,&MainWindow::destroyed,this,[=](){
                    this->setVisible(true);
                });
                this->setVisible(false);
            }else{
                //账号或者密码错误
                QMessageBox::warning(this,"警告","账号或者密码错误!");
            }
        }else{
            //不存在此用户
            ui->passwdLineedit->setText("");
            QMessageBox::warning(this,"警告","输入的账号不存在,请先注册!\n");
        }
    }
}


void loginwindow::on_registerButton_clicked()
{
    registerwindow *registor=new registerwindow(this);

    connect(registor,&registerwindow::destroyed,this,[=](){
        this->setVisible(true);
    });
    registor->show();
    this->setVisible(false);
}


void loginwindow::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}



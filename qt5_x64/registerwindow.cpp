#include "registerwindow.h"
#include "ui_registerwindow.h"

registerwindow::registerwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);

    ui->idLineedit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+$")));
    ui->passwdLineedit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+$")));
    ui->usernamelinedit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9\u4e00-\u9fa5]+$")));//数字英文和中文
    //设置输入框的正则


//    //开启鼠标悬停事件
    //设置控件提示
    ui->idLineedit->setToolTip("请输入6-50字符的数字或英文");
    ui->passwdLineedit->setToolTip("请输入6-50字符的数字或英文");
    ui->passwdLineedit_again->setToolTip("请输入6-50字符的数字或英文");
    ui->usernamelinedit->setToolTip("请输入3-50字符的数字、英文或中文");
    this->setWindowTitle("智能驾驶辅助系统");

    QString pwd=QCoreApplication::applicationDirPath();
    QFile fs(pwd+"/qtcss/register.qss");
    fs.open(QFile::ReadOnly|QFile::Text);
    QString css=fs.readAll();
    fs.close();
    css=css.replace("\n","");
    css=css.replace("softwarepwd",pwd);
//    qDebug()<<"css:"<<css;
    this->setStyleSheet(css);

}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_registerButton_clicked()
{
    //注册按钮
    QString idstr=ui->idLineedit->text();
    QString passwdstr=ui->passwdLineedit->text();
    QString username=ui->usernamelinedit->text();
    QString passwdAgain=ui->passwdLineedit_again->text();
    if(idstr.size()<6||idstr.size()>50||passwdstr.size()<6||passwdstr.size()>50||username.size()<3||username.size()>50||passwdAgain.size()<6||passwdAgain.size()>50)
    {
        QMessageBox::warning(this,"警告","输入不合法,请重新输入,鼠标悬停查看输入条件");
    }else{
        if(passwdAgain==passwdstr)
        {

        QStringList res;

        SqliteOperator sqlop=SqliteOperator();
        sqlop.queryTable();
        res=sqlop.queryData(idstr);
        bool notempty;
        if(res.at(0)!="NONE"){
            notempty=true;
        }else{
            //查无此人
            notempty=false;
        }
        if(notempty){
            QMessageBox::warning(this,"警告","账号已存在,请重试!");
        }else{
            md5 locker;
            string passwdstring=(const char*)passwdstr.toLocal8Bit();
            passwdstr=QString::fromLocal8Bit(locker.encode(passwdstring).data());

            sqlData insertdata;
            insertdata.userId=idstr;
            insertdata.userName=username;
            insertdata.userPermission=QString("0");
            insertdata.userPassword=passwdstr;
            insertdata.userConfigure=QString("None");
            bool success=sqlop.singleInsertData(insertdata);
            //插入数据


            if(success){
                QMessageBox::information(this,"注册信息","注册成功，确认自动返回登录");
                this->deleteLater();
            }else{
                QMessageBox::warning(this,"警告","未知错误,请反馈信息!");
            }
        }}else{
            //两次输入密码不等
            QMessageBox::warning(this,"警告","两次输入的密码不同");
        }
    }


}


void registerwindow::on_returnButton_clicked()
{

    this->deleteLater();
}


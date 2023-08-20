#include "user_manage.h"
#include "ui_user_manage.h"

user_manage::user_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_manage)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setWindowTitle("用户管理界面");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    on_update_data_clicked();
    ui->label->setWordWrap(true);
//    ui->tableWidget->selectRow(0);
    //隐藏列表头
    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);//去除选中后虚线
    ui->tableWidget->setShowGrid(false);//去除格子线
    ui->tableWidget->setFrameShape(QFrame::NoFrame);//去除边框
    //设置无边框窗口
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置背景色透明（透明的部分，鼠标点击，鼠标信号会透传到z轴底层去）
    setAttribute(Qt::WA_TranslucentBackground,true);
}

user_manage::~user_manage()
{
    delete ui;
}

void user_manage::on_pushButton_4_clicked()
{
    //退出
    this->deleteLater();
}

void user_manage::on_modify_passwd_clicked()
{
    //修改密码
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    if(!items.empty()){
        int currentrow=ui->tableWidget->currentRow();
        QString usrid=ui->tableWidget->item(currentrow,0)->text().replace(" ","");
        QString usrname=ui->tableWidget->item(currentrow,1)->text().replace(" ","");
        QString usrpermission=ui->tableWidget->item(currentrow,3)->text().replace(" ","");
        QString dlgTitle=QString("修改密码");//对话框标题
        QString txtLabel=QString("请输入用户%1新密码").arg(usrid);//对话框Label显示内容
        QString defaultInput=QStringLiteral("");//对话框内输入框的默认内容
        QLineEdit::EchoMode echoMode=QLineEdit::Normal;//输入框的文本内容为正常显示
//        QLineEdit::EchoMode echoMode=QLineEdit::Password;//输入框的文本内容为密码方式显示
        bool ok=false;
        QString text=QInputDialog::getText(this,dlgTitle,txtLabel,echoMode,defaultInput,&ok);
        if(ok && !text.isEmpty()){
            //若新老密码一样不用提示
            QString questions=QString("请确认密码是否为:%1").arg(text);
            int choice=QMessageBox::question(this,"确认密码",questions);
            if(choice==QMessageBox::Yes){
                md5 locker;
                string passwdstring=(const char*)text.toLocal8Bit();
                QString passwdstr=QString::fromLocal8Bit(locker.encode(passwdstring).data());
                SqliteOperator sqlop;
                bool success=sqlop.modifyData(usrid,usrname,passwdstr,usrpermission,"");
                if(success){
                    QMessageBox::information(this,"操作信息","成功修改密码,请刷新数据查看");
                }else{
                    QMessageBox::warning(this,"操作信息","出现未知错误,请联系工程师");
                }
            }
        }else{
            if(ok){
                QMessageBox::warning(this,"操作信息","未获取到值,请重新填写");
            }
        }
    }else{
        QMessageBox::warning(this,"警告","请先选择一行再进行操作");
    }

}

void user_manage::on_delete_user_clicked()
{
    //删除用户
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    if(!items.empty()){
        int currentrow=ui->tableWidget->currentRow();
        QString usrid=ui->tableWidget->item(currentrow,0)->text();
        if(usrid=="rooter"){
            QMessageBox::warning(this,"警告","rooter用户不可删除");
        }else{
            QString question=QString("您确定删除用户 %1 吗?").arg(usrid);
            int choice=QMessageBox::question(this,"确定删除？",question);
            if(choice==QMessageBox::Yes)
            {
                SqliteOperator sqlop;
                bool success=sqlop.deleteData(usrid);
                if(success){
                    QMessageBox::information(this,"操作信息","成功删除用户,请刷新数据查看");
                    on_update_data_clicked();
                }else{
                    QMessageBox::warning(this,"操作信息","出现未知错误,请联系工程师");
                }
            }else{
                qDebug()<<"操作取消";
            }
        }
    }else{
        QMessageBox::warning(this,"警告","请先选择一行再进行操作");
    }
}

void user_manage::on_update_data_clicked()
{
    //更新数据
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(1);
    QVector<sqlData> receive;
    SqliteOperator sqlop;
    receive=sqlop.queryTable();
    for (int i=0;i<receive.size();i++) {
        int iRow = ui->tableWidget->rowCount();
        if(iRow-2<=i)
        {
            ui->tableWidget->setRowCount(iRow + 1);
        }
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(receive[i].userId+"    "));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(receive[i].userName+"    "));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(receive[i].userPassword+"    "));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(receive[i].userPermission+"    "));
    }
}


void user_manage::on_modify_nickname_clicked()
{
    //修改昵称
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    if(!items.empty()){
        int currentrow=ui->tableWidget->currentRow();
        QString usrid=ui->tableWidget->item(currentrow,0)->text().replace(" ","");
        QString usrpasswd=ui->tableWidget->item(currentrow,2)->text().replace(" ","");
        QString usrpermission=ui->tableWidget->item(currentrow,3)->text().replace(" ","");
        QString dlgTitle=QString("修改昵称");//对话框标题
        QString txtLabel=QString("请输入用户%1新昵称").arg(usrid);//对话框Label显示内容
        QString defaultInput=QStringLiteral("");//对话框内输入框的默认内容
        QLineEdit::EchoMode echoMode=QLineEdit::Normal;//输入框的文本内容为正常显示
//        QLineEdit::EchoMode echoMode=QLineEdit::Password;//输入框的文本内容为密码方式显示
        bool ok=false;
        QString userconfig=QString("None");
        QString text=QInputDialog::getText(this,dlgTitle,txtLabel,echoMode,defaultInput,&ok);
        if(ok && !text.isEmpty()){
                SqliteOperator sqlop;
//                qDebug()<<"正在修改:"<<usrid<<text<<usrpasswd<<usrpermission<<userconfig;
                bool success=sqlop.modifyData(usrid,text,usrpasswd,usrpermission,userconfig);
                if(success){
                    QMessageBox::information(this,"操作信息","成功修改昵称,请刷新数据查看");
                }else{
                    QMessageBox::warning(this,"操作信息","出现未知错误,请联系工程师");
                }
        }else{
            if(ok){
                QMessageBox::warning(this,"操作信息","未获取到值,请重新填写");
            }
        }
    }else{
        QMessageBox::warning(this,"警告","请先选择一行再进行操作");
    }
}

#ifndef USER_MANAGE_H
#define USER_MANAGE_H

#include <QMainWindow>
#include <sqliteoperator.h>
#include <QMessageBox>
#include <md5.h>
#include <QInputDialog>
#include <QHeaderView>

namespace Ui {
class user_manage;
}

class user_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_manage(QWidget *parent = nullptr);
    ~user_manage();

private slots:
    void on_pushButton_4_clicked();

    void on_modify_passwd_clicked();

    void on_delete_user_clicked();

    void on_update_data_clicked();

    void on_modify_nickname_clicked();

private:
    Ui::user_manage *ui;
};

#endif // USER_MANAGE_H

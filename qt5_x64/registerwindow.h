#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <sqliteoperator.h>
#include <QDebug>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <md5.h>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui {
class registerwindow;
}
QT_END_NAMESPACE
class registerwindow : public QMainWindow
{
    Q_OBJECT

public:
    registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

private slots:
    void on_registerButton_clicked();

    void on_returnButton_clicked();


private:
    Ui::registerwindow *ui;


};

#endif // REGISTERWINDOW_H

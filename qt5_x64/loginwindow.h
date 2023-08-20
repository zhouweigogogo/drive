#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <sqliteoperator.h>
#include <QStyleOption>
#include <QPainter>
namespace Ui {
class loginwindow;
}

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private slots:

    void on_loginButton_clicked();

    void on_registerButton_clicked();


private:
    Ui::loginwindow *ui;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // LOGINWINDOW_H

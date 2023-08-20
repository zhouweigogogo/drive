#ifndef THEME_H
#define THEME_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QRect>
#include <QDebug>
#include <QButtonGroup>
#include <QFile>
#include <opencv2/opencv.hpp>
#include <sqliteoperator.h>
namespace Ui {
class theme;
}

class theme : public QMainWindow
{
    Q_OBJECT

public:
    explicit theme(QWidget *parent = nullptr);
    void receive_theme(QString themes);
    ~theme();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_5_clicked();


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

signals:
    void update_theme(QString theme,QString imgpath);
private:
    Ui::theme *ui;
    QString imgurl;
    bool changed;
    QString usertheme;
};

#endif // THEME_H

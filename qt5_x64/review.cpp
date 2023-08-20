#include "review.h"
#include "ui_review.h"

review::review(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::review)
{
    ui->setupUi(this);
}

review::~review()
{
    delete ui;
}

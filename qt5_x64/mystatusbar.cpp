#include "mystatusbar.h"

mystatusBar::mystatusBar(QWidget *parent)
    :QWidget{parent},m_time(this),m_Electricity(this),m_Signal(this)
{
    QHBoxLayout* Hlayout = new QHBoxLayout(this);
    //时间
    QDateTime currentTime = QDateTime::currentDateTime();
    m_time.setStyleSheet("color : black ;");
    m_time.setText(currentTime.toString("hh:mm"));

    QPixmap pix;
    pix = QPixmap("./img/user.png").scaled(30, 30);
    m_Signal.setPixmap(pix);
    m_Electricity.setText("周为");

    Hlayout->addWidget(&m_time);
    Hlayout->addStretch(); // 添加一个可伸缩的空间
    Hlayout->addWidget(&m_Signal);
    Hlayout->addWidget(&m_Electricity);
    Hlayout->setContentsMargins(5, 0, 5, 0);

    m_timer.start(30000);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(Timeout()));

}

void mystatusBar::Timeout()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    m_time.setText(currentTime.toString("hh:mm"));
}

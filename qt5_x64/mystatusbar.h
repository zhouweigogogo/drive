#ifndef MYSTATUSBAR_H
#define MYSTATUSBAR_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class mystatusBar : public QWidget
{
    Q_OBJECT

    QLabel m_time;
    QLabel m_Electricity;
    QLabel m_Signal;
    QTimer m_timer;

public:
    explicit mystatusBar(QWidget *parent = nullptr);

signals:

protected slots:
    void Timeout();

};

#endif // MYSTATUSBAR_H


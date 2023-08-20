#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);

signals:
    void doubleclick();
public slots:

protected:
    bool event(QEvent*e);
};

#endif // MYLABEL_H

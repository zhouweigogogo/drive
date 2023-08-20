/********************************************************************************
** Form generated from reading UI file 'review.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEW_H
#define UI_REVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_review
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *review)
    {
        if (review->objectName().isEmpty())
            review->setObjectName(QString::fromUtf8("review"));
        review->resize(800, 600);
        menubar = new QMenuBar(review);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        review->setMenuBar(menubar);
        centralwidget = new QWidget(review);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        review->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(review);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        review->setStatusBar(statusbar);

        retranslateUi(review);

        QMetaObject::connectSlotsByName(review);
    } // setupUi

    void retranslateUi(QMainWindow *review)
    {
        review->setWindowTitle(QApplication::translate("review", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class review: public Ui_review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H

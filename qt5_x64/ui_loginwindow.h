/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QWidget *login_widget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idLineedit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwdLineedit;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLabel *label_3;

    void setupUi(QWidget *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName(QString::fromUtf8("loginwindow"));
        loginwindow->resize(1080, 675);
        loginwindow->setStyleSheet(QString::fromUtf8(""));
        login_widget = new QWidget(loginwindow);
        login_widget->setObjectName(QString::fromUtf8("login_widget"));
        login_widget->setGeometry(QRect(280, 110, 491, 361));
        widget = new QWidget(login_widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 50, 361, 101));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        idLineedit = new QLineEdit(widget);
        idLineedit->setObjectName(QString::fromUtf8("idLineedit"));
        idLineedit->setFont(font);

        horizontalLayout->addWidget(idLineedit);

        widget_2 = new QWidget(login_widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(70, 150, 360, 100));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        passwdLineedit = new QLineEdit(widget_2);
        passwdLineedit->setObjectName(QString::fromUtf8("passwdLineedit"));
        passwdLineedit->setFont(font1);
        passwdLineedit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwdLineedit);

        registerButton = new QPushButton(login_widget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(70, 260, 150, 40));
        registerButton->setFont(font1);
        loginButton = new QPushButton(login_widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(280, 260, 150, 40));
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(login_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 20, 361, 51));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QWidget *loginwindow)
    {
        loginwindow->setWindowTitle(QApplication::translate("loginwindow", "Form", nullptr));
        loginwindow->setProperty("class", QVariant(QApplication::translate("loginwindow", "loginwindow", nullptr)));
        login_widget->setProperty("class", QVariant(QApplication::translate("loginwindow", "loginwidget", nullptr)));
        widget->setProperty("class", QVariant(QApplication::translate("loginwindow", "input-box", nullptr)));
        label->setText(QApplication::translate("loginwindow", "\350\264\246\345\217\267", nullptr));
        widget_2->setProperty("class", QVariant(QApplication::translate("loginwindow", "input-box", nullptr)));
        label_2->setText(QApplication::translate("loginwindow", "\345\257\206\347\240\201", nullptr));
        registerButton->setText(QApplication::translate("loginwindow", "\346\263\250\345\206\214", nullptr));
        registerButton->setProperty("class", QVariant(QApplication::translate("loginwindow", "btn", nullptr)));
        loginButton->setText(QApplication::translate("loginwindow", "\347\231\273\345\275\225", nullptr));
        loginButton->setProperty("class", QVariant(QApplication::translate("loginwindow", "btn", nullptr)));
        label_3->setText(QApplication::translate("loginwindow", "login", nullptr));
        label_3->setProperty("class", QVariant(QApplication::translate("loginwindow", "login-label", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

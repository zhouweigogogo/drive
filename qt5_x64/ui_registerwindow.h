/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerwindow
{
public:
    QWidget *widget_4;
    QPushButton *registerButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *idLineedit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *passwdLineedit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *usernamelinedit;
    QPushButton *returnButton;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *passwdLineedit_again;
    QLabel *label_3;

    void setupUi(QWidget *registerwindow)
    {
        if (registerwindow->objectName().isEmpty())
            registerwindow->setObjectName(QString::fromUtf8("registerwindow"));
        registerwindow->resize(1080, 640);
        widget_4 = new QWidget(registerwindow);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(280, 80, 520, 420));
        registerButton = new QPushButton(widget_4);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(280, 320, 160, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        registerButton->setFont(font);
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 130, 360, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        idLineedit = new QLineEdit(widget_2);
        idLineedit->setObjectName(QString::fromUtf8("idLineedit"));
        idLineedit->setFont(font);

        horizontalLayout_2->addWidget(idLineedit);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(80, 190, 360, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        passwdLineedit = new QLineEdit(widget_3);
        passwdLineedit->setObjectName(QString::fromUtf8("passwdLineedit"));
        passwdLineedit->setFont(font);
        passwdLineedit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(passwdLineedit);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(80, 70, 361, 51));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        usernamelinedit = new QLineEdit(widget_5);
        usernamelinedit->setObjectName(QString::fromUtf8("usernamelinedit"));
        usernamelinedit->setFont(font);

        horizontalLayout->addWidget(usernamelinedit);

        returnButton = new QPushButton(widget_4);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(80, 320, 160, 40));
        returnButton->setFont(font);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(80, 250, 360, 51));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        passwdLineedit_again = new QLineEdit(widget_6);
        passwdLineedit_again->setObjectName(QString::fromUtf8("passwdLineedit_again"));
        passwdLineedit_again->setFont(font);
        passwdLineedit_again->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(passwdLineedit_again);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 20, 360, 50));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(registerwindow);

        QMetaObject::connectSlotsByName(registerwindow);
    } // setupUi

    void retranslateUi(QWidget *registerwindow)
    {
        registerwindow->setWindowTitle(QApplication::translate("registerwindow", "Form", nullptr));
        registerwindow->setProperty("class", QVariant(QApplication::translate("registerwindow", "registerwindow", nullptr)));
        widget_4->setProperty("class", QVariant(QApplication::translate("registerwindow", "registerwidget", nullptr)));
        registerButton->setText(QApplication::translate("registerwindow", "\346\263\250\345\206\214", nullptr));
        registerButton->setProperty("class", QVariant(QApplication::translate("registerwindow", "btn", nullptr)));
        widget_2->setProperty("class", QVariant(QApplication::translate("registerwindow", "input-box", nullptr)));
        label->setText(QApplication::translate("registerwindow", "\350\264\246       \345\217\267", nullptr));
        widget_3->setProperty("class", QVariant(QApplication::translate("registerwindow", "input-box", nullptr)));
        label_2->setText(QApplication::translate("registerwindow", "\345\257\206       \347\240\201", nullptr));
        widget_5->setProperty("class", QVariant(QApplication::translate("registerwindow", "input-box", nullptr)));
        label_6->setText(QApplication::translate("registerwindow", "\346\230\265       \347\247\260", nullptr));
        returnButton->setText(QApplication::translate("registerwindow", "\350\277\224\345\233\236", nullptr));
        returnButton->setProperty("class", QVariant(QApplication::translate("registerwindow", "btn", nullptr)));
        widget_6->setProperty("class", QVariant(QApplication::translate("registerwindow", "input-box", nullptr)));
        label_5->setText(QApplication::translate("registerwindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("registerwindow", "register", nullptr));
        label_3->setProperty("class", QVariant(QApplication::translate("registerwindow", "register-label", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class registerwindow: public Ui_registerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

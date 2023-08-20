/********************************************************************************
** Form generated from reading UI file 'theme.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEME_H
#define UI_THEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_theme
{
public:
    QWidget *centralwidget;
    QWidget *widget_7;
    QWidget *current_theme;
    QWidget *widget_white;
    QLabel *label;
    QRadioButton *radioButton;
    QWidget *widget_singal;
    QLabel *label_2;
    QRadioButton *radioButton_2;
    QWidget *widget_diy;
    QLabel *label_5;
    QRadioButton *radioButton_5;
    QPushButton *pushButton;
    QWidget *widget_5;
    QLabel *label_4;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_2;
    QWidget *widget_pink;
    QLabel *label_3;
    QRadioButton *radioButton_3;

    void setupUi(QMainWindow *theme)
    {
        if (theme->objectName().isEmpty())
            theme->setObjectName(QString::fromUtf8("theme"));
        theme->resize(1080, 675);
        centralwidget = new QWidget(theme);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 10, 1070, 650));
        current_theme = new QWidget(widget_7);
        current_theme->setObjectName(QString::fromUtf8("current_theme"));
        current_theme->setGeometry(QRect(0, 0, 220, 650));
        widget_white = new QWidget(current_theme);
        widget_white->setObjectName(QString::fromUtf8("widget_white"));
        widget_white->setGeometry(QRect(10, 10, 200, 540));
        widget_white->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(widget_white);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 180, 480));
        label->setStyleSheet(QString::fromUtf8("background:rgb(255,255,255);\n"
"border:1px solid #000;\n"
"border-radius:10px;\n"
""));
        radioButton = new QRadioButton(widget_white);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 500, 100, 30));
        radioButton->setChecked(true);
        widget_singal = new QWidget(widget_7);
        widget_singal->setObjectName(QString::fromUtf8("widget_singal"));
        widget_singal->setGeometry(QRect(230, 10, 200, 540));
        label_2 = new QLabel(widget_singal);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 180, 480));
        label_2->setStyleSheet(QString::fromUtf8(""));
        radioButton_2 = new QRadioButton(widget_singal);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(50, 500, 100, 30));
        widget_diy = new QWidget(widget_7);
        widget_diy->setObjectName(QString::fromUtf8("widget_diy"));
        widget_diy->setGeometry(QRect(860, 10, 200, 540));
        widget_diy->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(widget_diy);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 180, 480));
        QFont font;
        font.setPointSize(150);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        radioButton_5 = new QRadioButton(widget_diy);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(50, 500, 100, 30));
        pushButton = new QPushButton(widget_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 570, 200, 50));
        widget_5 = new QWidget(widget_7);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(650, 10, 200, 540));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 180, 480));
        label_4->setStyleSheet(QString::fromUtf8(""));
        radioButton_4 = new QRadioButton(widget_5);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(50, 500, 100, 30));
        pushButton_2 = new QPushButton(widget_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(760, 570, 200, 50));
        widget_pink = new QWidget(widget_7);
        widget_pink->setObjectName(QString::fromUtf8("widget_pink"));
        widget_pink->setGeometry(QRect(440, 10, 200, 540));
        label_3 = new QLabel(widget_pink);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 180, 480));
        label_3->setStyleSheet(QString::fromUtf8(""));
        radioButton_3 = new QRadioButton(widget_pink);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(50, 500, 100, 30));
        theme->setCentralWidget(centralwidget);

        retranslateUi(theme);

        QMetaObject::connectSlotsByName(theme);
    } // setupUi

    void retranslateUi(QMainWindow *theme)
    {
        theme->setWindowTitle(QApplication::translate("theme", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        theme->setWhatsThis(QApplication::translate("theme", "theme-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        widget_7->setWhatsThis(QApplication::translate("theme", "theme-mainbox", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        current_theme->setWhatsThis(QApplication::translate("theme", "theme-operatebox", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        widget_white->setWhatsThis(QApplication::translate("theme", "singel-box-white", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("theme", "white-item", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QString());
#ifndef QT_NO_WHATSTHIS
        radioButton->setWhatsThis(QApplication::translate("theme", "white-label", nullptr));
#endif // QT_NO_WHATSTHIS
        radioButton->setText(QApplication::translate("theme", "\346\267\241\351\233\205\347\231\275", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_singal->setWhatsThis(QApplication::translate("theme", "singal-box-gray", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("theme", "gray-item", nullptr));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QString());
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("theme", "gray-label", nullptr));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("theme", "\345\206\267\346\274\240\347\201\260", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_diy->setWhatsThis(QApplication::translate("theme", "singal-box-diy", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("theme", "diy-item", nullptr));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("theme", "?", nullptr));
#ifndef QT_NO_WHATSTHIS
        radioButton_5->setWhatsThis(QApplication::translate("theme", "diy-label", nullptr));
#endif // QT_NO_WHATSTHIS
        radioButton_5->setText(QApplication::translate("theme", "\350\207\252\345\256\232\344\271\211", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("theme", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("theme", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_5->setWhatsThis(QApplication::translate("theme", "singal-box-blue", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_4->setWhatsThis(QApplication::translate("theme", "blue-item", nullptr));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QString());
#ifndef QT_NO_WHATSTHIS
        radioButton_4->setWhatsThis(QApplication::translate("theme", "blue-label", nullptr));
#endif // QT_NO_WHATSTHIS
        radioButton_4->setText(QApplication::translate("theme", "\345\244\251\347\251\272\350\223\235", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("theme", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("theme", "\351\205\215\347\275\256", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_pink->setWhatsThis(QApplication::translate("theme", "singal-box-pink", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("theme", "pink-item", nullptr));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QString());
#ifndef QT_NO_WHATSTHIS
        radioButton_3->setWhatsThis(QApplication::translate("theme", "pink-label", nullptr));
#endif // QT_NO_WHATSTHIS
        radioButton_3->setText(QApplication::translate("theme", "\347\224\234\345\277\203\347\262\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class theme: public Ui_theme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEME_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionexit;
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QPushButton *pushButton_2;
    QLabel *username_label;
    QPushButton *pushButton;
    QPushButton *openvideo;
    QComboBox *comboBox;
    QLabel *user_avatar;
    QLabel *label_3;
    QCheckBox *checkBox;
    QPushButton *theme_change;
    QPushButton *exit;
    QGroupBox *groupBox;
    QPushButton *model_choose;
    QPushButton *user_manage;
    QLabel *label_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *barrage_third;
    QLabel *barrage_second;
    QLabel *barrage_first;
    QLabel *barrage_fourth;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 675);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1080, 670));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 10, 840, 520));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 220, 670));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 400, 181, 31));
        QFont font;
        font.setPointSize(14);
        pushButton_2->setFont(font);
        username_label = new QLabel(widget_2);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(110, 10, 101, 50));
        QFont font1;
        font1.setPointSize(15);
        username_label->setFont(font1);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 160, 180, 50));
        pushButton->setFont(font);
        openvideo = new QPushButton(widget_2);
        openvideo->setObjectName(QString::fromUtf8("openvideo"));
        openvideo->setGeometry(QRect(20, 230, 180, 50));
        openvideo->setFont(font);
        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 70, 90, 30));
        comboBox->setStyleSheet(QString::fromUtf8(""));
        user_avatar = new QLabel(widget_2);
        user_avatar->setObjectName(QString::fromUtf8("user_avatar"));
        user_avatar->setGeometry(QRect(35, 10, 50, 50));
        user_avatar->setPixmap(QPixmap(QString::fromUtf8("img/user.png")));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 70, 80, 30));
        label_3->setFont(font);
        checkBox = new QCheckBox(widget_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 110, 181, 31));
        theme_change = new QPushButton(widget_2);
        theme_change->setObjectName(QString::fromUtf8("theme_change"));
        theme_change->setGeometry(QRect(20, 300, 180, 50));
        theme_change->setFont(font);
        exit = new QPushButton(widget_2);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(20, 370, 180, 50));
        exit->setFont(font);
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 430, 200, 180));
        groupBox->setFont(font);
        model_choose = new QPushButton(groupBox);
        model_choose->setObjectName(QString::fromUtf8("model_choose"));
        model_choose->setGeometry(QRect(10, 40, 180, 50));
        model_choose->setFont(font);
        user_manage = new QPushButton(groupBox);
        user_manage->setObjectName(QString::fromUtf8("user_manage"));
        user_manage->setGeometry(QRect(10, 110, 180, 50));
        user_manage->setFont(font);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 620, 200, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("URW Gothic"));
        font2.setPointSize(13);
        font2.setItalic(true);
        label_5->setFont(font2);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
""));
        label_5->setFrameShape(QFrame::Box);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(220, 540, 861, 130));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"	background: transparent;\n"
"}\n"
"QWidget#scrollAreaWidgetContents{\n"
"	background: transparent;\n"
"\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 859, 128));
        barrage_third = new QLabel(scrollAreaWidgetContents);
        barrage_third->setObjectName(QString::fromUtf8("barrage_third"));
        barrage_third->setGeometry(QRect(10, 5, 820, 30));
        barrage_third->setStyleSheet(QString::fromUtf8(""));
        barrage_third->setAlignment(Qt::AlignCenter);
        barrage_second = new QLabel(scrollAreaWidgetContents);
        barrage_second->setObjectName(QString::fromUtf8("barrage_second"));
        barrage_second->setGeometry(QRect(10, 45, 820, 30));
        barrage_second->setStyleSheet(QString::fromUtf8(""));
        barrage_second->setAlignment(Qt::AlignCenter);
        barrage_first = new QLabel(scrollAreaWidgetContents);
        barrage_first->setObjectName(QString::fromUtf8("barrage_first"));
        barrage_first->setGeometry(QRect(10, 85, 820, 30));
        barrage_first->setStyleSheet(QString::fromUtf8(""));
        barrage_first->setAlignment(Qt::AlignCenter);
        barrage_fourth = new QLabel(scrollAreaWidgetContents);
        barrage_fourth->setObjectName(QString::fromUtf8("barrage_fourth"));
        barrage_fourth->setGeometry(QRect(10, 125, 820, 30));
        barrage_fourth->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QApplication::translate("MainWindow", "mainwindow-box", nullptr));
#endif // QT_NO_WHATSTHIS
        actionopen->setText(QApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QApplication::translate("MainWindow", "save", nullptr));
        actionexit->setText(QApplication::translate("MainWindow", "exit", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget->setWhatsThis(QApplication::translate("MainWindow", "main-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("MainWindow", "video-label-play", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "formap", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_2->setWhatsThis(QApplication::translate("MainWindow", "operate-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\231\272\351\234\226\345\264\275\345\264\275\345\200\276\346\203\205\346\274\224\345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        username_label->setWhatsThis(QApplication::translate("MainWindow", "user-name", nullptr));
#endif // QT_NO_WHATSTHIS
        username_label->setText(QApplication::translate("MainWindow", "username", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\243\200\346\265\213", nullptr));
#ifndef QT_NO_WHATSTHIS
        openvideo->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        openvideo->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\346\243\200\346\265\213", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\346\231\272\350\203\275\351\251\276\351\251\266", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\346\231\256\351\200\232\351\251\276\351\251\266", nullptr));

#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("MainWindow", "drive-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        user_avatar->setWhatsThis(QApplication::translate("MainWindow", "user-head", nullptr));
#endif // QT_NO_WHATSTHIS
        user_avatar->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("MainWindow", "drive-label", nullptr));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("MainWindow", "\351\251\276\351\251\266\346\250\241\345\274\217:", nullptr));
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("MainWindow", "check-risk", nullptr));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("MainWindow", "\345\261\217\350\224\275\344\275\216\351\243\216\351\231\251\346\230\276\347\244\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        theme_change->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        theme_change->setText(QApplication::translate("MainWindow", "\346\233\264\346\215\242\344\270\273\351\242\230", nullptr));
#ifndef QT_NO_WHATSTHIS
        exit->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        exit->setText(QApplication::translate("MainWindow", "\351\200\200      \345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("MainWindow", "manager-box", nullptr));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\217\221\350\200\205\350\256\276\347\275\256\357\274\232", nullptr));
#ifndef QT_NO_WHATSTHIS
        model_choose->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        model_choose->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\213\351\205\215\347\275\256", nullptr));
#ifndef QT_NO_WHATSTHIS
        user_manage->setWhatsThis(QApplication::translate("MainWindow", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        user_manage->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("MainWindow", "version-label", nullptr));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("MainWindow", "version.1.0.0-rc", nullptr));
#ifndef QT_NO_WHATSTHIS
        scrollArea->setWhatsThis(QApplication::translate("MainWindow", "tip-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        barrage_third->setWhatsThis(QApplication::translate("MainWindow", "tip-label", nullptr));
#endif // QT_NO_WHATSTHIS
        barrage_third->setText(QApplication::translate("MainWindow", "\350\257\267\346\263\250\346\204\217\345\211\215\346\226\271\346\235\245\350\275\246", nullptr));
#ifndef QT_NO_WHATSTHIS
        barrage_second->setWhatsThis(QApplication::translate("MainWindow", "tip-label", nullptr));
#endif // QT_NO_WHATSTHIS
        barrage_second->setText(QApplication::translate("MainWindow", "\350\257\267\346\263\250\346\204\217\345\211\215\346\226\271\346\235\245\350\275\246", nullptr));
#ifndef QT_NO_WHATSTHIS
        barrage_first->setWhatsThis(QApplication::translate("MainWindow", "tip-label", nullptr));
#endif // QT_NO_WHATSTHIS
        barrage_first->setText(QApplication::translate("MainWindow", "\350\257\267\346\263\250\346\204\217\345\211\215\346\226\271\346\235\245\350\275\246", nullptr));
#ifndef QT_NO_WHATSTHIS
        barrage_fourth->setWhatsThis(QApplication::translate("MainWindow", "tip-label", nullptr));
#endif // QT_NO_WHATSTHIS
        barrage_fourth->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

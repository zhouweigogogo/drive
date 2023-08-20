/********************************************************************************
** Form generated from reading UI file 'user_manage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGE_H
#define UI_USER_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_manage
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QPushButton *delete_user;
    QPushButton *modify_passwd;
    QPushButton *update_data;
    QPushButton *pushButton_4;
    QPushButton *modify_nickname;
    QLabel *label;

    void setupUi(QMainWindow *user_manage)
    {
        if (user_manage->objectName().isEmpty())
            user_manage->setObjectName(QString::fromUtf8("user_manage"));
        user_manage->resize(1080, 675);
        centralwidget = new QWidget(user_manage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1040, 650));
        widget->setStyleSheet(QString::fromUtf8(""));
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(160, 0, 881, 651));
        QFont font;
        font.setPointSize(14);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 160, 650));
        delete_user = new QPushButton(groupBox);
        delete_user->setObjectName(QString::fromUtf8("delete_user"));
        delete_user->setGeometry(QRect(10, 100, 140, 50));
        modify_passwd = new QPushButton(groupBox);
        modify_passwd->setObjectName(QString::fromUtf8("modify_passwd"));
        modify_passwd->setGeometry(QRect(10, 170, 140, 50));
        update_data = new QPushButton(groupBox);
        update_data->setObjectName(QString::fromUtf8("update_data"));
        update_data->setGeometry(QRect(10, 30, 140, 50));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 310, 140, 50));
        modify_nickname = new QPushButton(groupBox);
        modify_nickname->setObjectName(QString::fromUtf8("modify_nickname"));
        modify_nickname->setGeometry(QRect(10, 240, 140, 50));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 410, 131, 221));
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        user_manage->setCentralWidget(centralwidget);

        retranslateUi(user_manage);

        QMetaObject::connectSlotsByName(user_manage);
    } // setupUi

    void retranslateUi(QMainWindow *user_manage)
    {
        user_manage->setWindowTitle(QApplication::translate("user_manage", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        user_manage->setWhatsThis(QApplication::translate("user_manage", "usermanager-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        widget->setWhatsThis(QApplication::translate("user_manage", "usermanager-main-box", nullptr));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("user_manage", "\347\224\250\346\210\267\350\264\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("user_manage", "\347\224\250\346\210\267\346\230\265\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("user_manage", "\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("user_manage", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("user_manage", "user-table", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("user_manage", "usermanager-oprater", nullptr));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QString());
#ifndef QT_NO_WHATSTHIS
        delete_user->setWhatsThis(QApplication::translate("user_manage", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        delete_user->setText(QApplication::translate("user_manage", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
#ifndef QT_NO_WHATSTHIS
        modify_passwd->setWhatsThis(QApplication::translate("user_manage", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        modify_passwd->setText(QApplication::translate("user_manage", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#ifndef QT_NO_WHATSTHIS
        update_data->setWhatsThis(QApplication::translate("user_manage", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        update_data->setText(QApplication::translate("user_manage", "\346\233\264\346\226\260\346\225\260\346\215\256", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("user_manage", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("user_manage", "\351\200\200        \345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        modify_nickname->setWhatsThis(QApplication::translate("user_manage", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        modify_nickname->setText(QApplication::translate("user_manage", "\344\277\256\346\224\271\346\230\265\347\247\260", nullptr));
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("user_manage", "attention-label", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("user_manage", "\346\263\250\346\204\217\344\272\213\351\241\271\357\274\232\347\224\250\346\210\267\345\257\206\347\240\201\346\230\276\347\244\272\344\270\272\345\212\240\345\257\206\345\220\216\347\232\204\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_manage: public Ui_user_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGE_H

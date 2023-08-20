/********************************************************************************
** Form generated from reading UI file 'model_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_CHOOSE_H
#define UI_MODEL_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_model_choose
{
public:
    QWidget *centralwidget;
    QWidget *widget_6;
    QLabel *video_label;
    QWidget *widget_5;
    QPushButton *search_model;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *model_choose_box;
    QPushButton *pushButton_4;
    QPushButton *model_test;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *NSM_edit;
    QPushButton *pushButton_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *confi_edit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *foclenth_edit;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *model_choose)
    {
        if (model_choose->objectName().isEmpty())
            model_choose->setObjectName(QString::fromUtf8("model_choose"));
        model_choose->resize(1080, 675);
        centralwidget = new QWidget(model_choose);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 0, 1060, 621));
        video_label = new QLabel(widget_6);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setGeometry(QRect(220, 0, 840, 520));
        video_label->setStyleSheet(QString::fromUtf8(""));
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 220, 620));
        search_model = new QPushButton(widget_5);
        search_model->setObjectName(QString::fromUtf8("search_model"));
        search_model->setGeometry(QRect(19, 310, 181, 50));
        QFont font;
        font.setPointSize(14);
        search_model->setFont(font);
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 230, 221, 50));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        model_choose_box = new QComboBox(widget_4);
        model_choose_box->setObjectName(QString::fromUtf8("model_choose_box"));
        model_choose_box->setFont(font);

        horizontalLayout_4->addWidget(model_choose_box);

        pushButton_4 = new QPushButton(widget_5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(19, 550, 181, 50));
        pushButton_4->setFont(font);
        model_test = new QPushButton(widget_5);
        model_test->setObjectName(QString::fromUtf8("model_test"));
        model_test->setGeometry(QRect(19, 390, 181, 50));
        model_test->setFont(font);
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 90, 221, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        NSM_edit = new QLineEdit(widget_2);
        NSM_edit->setObjectName(QString::fromUtf8("NSM_edit"));
        NSM_edit->setFont(font);

        horizontalLayout_2->addWidget(NSM_edit);

        pushButton_3 = new QPushButton(widget_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(19, 470, 181, 50));
        pushButton_3->setFont(font);
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 160, 221, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        confi_edit = new QLineEdit(widget_3);
        confi_edit->setObjectName(QString::fromUtf8("confi_edit"));
        confi_edit->setFont(font);

        horizontalLayout_3->addWidget(confi_edit);

        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 20, 221, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        foclenth_edit = new QLineEdit(widget);
        foclenth_edit->setObjectName(QString::fromUtf8("foclenth_edit"));
        foclenth_edit->setFont(font);

        horizontalLayout->addWidget(foclenth_edit);

        label = new QLabel(widget_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 520, 840, 100));
        label->setFont(font);
        model_choose->setCentralWidget(centralwidget);
        menubar = new QMenuBar(model_choose);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 28));
        model_choose->setMenuBar(menubar);

        retranslateUi(model_choose);

        QMetaObject::connectSlotsByName(model_choose);
    } // setupUi

    void retranslateUi(QMainWindow *model_choose)
    {
        model_choose->setWindowTitle(QApplication::translate("model_choose", "model-choose-mainwindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_6->setWhatsThis(QApplication::translate("model_choose", "model-choose-box", nullptr));
#endif // QT_NO_WHATSTHIS
        video_label->setText(QApplication::translate("model_choose", "TextLabel", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_5->setWhatsThis(QApplication::translate("model_choose", "model-choose-oprate", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        search_model->setWhatsThis(QApplication::translate("model_choose", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        search_model->setText(QApplication::translate("model_choose", "\346\220\234\347\264\242\345\217\257\347\224\250\346\250\241\345\236\213", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_4->setWhatsThis(QApplication::translate("model_choose", "choose-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("model_choose", "label-model", nullptr));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("model_choose", "\346\250\241 \345\236\213 \351\200\211 \346\213\251\357\274\232", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("model_choose", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("model_choose", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        model_test->setWhatsThis(QApplication::translate("model_choose", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        model_test->setText(QApplication::translate("model_choose", "\346\250\241\345\236\213\346\265\213\350\257\225", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_2->setWhatsThis(QApplication::translate("model_choose", "input-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("model_choose", "label-NMS", nullptr));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("model_choose", "NMS \351\230\210  \345\200\274\357\274\232", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("model_choose", "btn", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("model_choose", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget_3->setWhatsThis(QApplication::translate("model_choose", "input-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_4->setWhatsThis(QApplication::translate("model_choose", "label-threshod", nullptr));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("model_choose", "\347\275\256\344\277\241\345\272\246\351\230\210\345\200\274:", nullptr));
#ifndef QT_NO_WHATSTHIS
        widget->setWhatsThis(QApplication::translate("model_choose", "input-box", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("model_choose", "label-foclenth", nullptr));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("model_choose", "\347\204\246\350\267\235  (MM)\357\274\232", nullptr));
#ifndef QT_NO_WHATSTHIS
        foclenth_edit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("model_choose", "attention-label", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("model_choose", "\346\263\250\346\204\217\344\272\213\351\241\271:\346\221\204\345\203\217\345\244\264\347\204\246\350\267\235\351\234\200\350\246\201\345\260\275\345\217\257\350\203\275\346\216\245\350\277\221\347\234\237\345\256\236\345\217\202\346\225\260\343\200\201\346\250\241\345\236\213\345\217\202\346\225\260\350\260\203\346\225\264\344\271\213\345\220\216\351\234\200\350\246\201\344\277\235\345\255\230\351\205\215\347\275\256\346\211\215\350\203\275\345\234\250\347\263\273\347\273\237\347\224\237\346\225\210\343\200\201\346\250\241\345\236\213\346\265\213\350\257\225\344\273\205\344\273\205\346\217\220\344\276\233\346\225\210\346\236\234\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class model_choose: public Ui_model_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_CHOOSE_H

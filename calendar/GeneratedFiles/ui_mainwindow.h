/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "cxlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Form_MainWindow
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_13;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QWidget *widget_8;
    QGridLayout *gridLayout_11;
    QWidget *widget_9;
    QGridLayout *gridLayout_2;
    QLabel *lbl_path_2;
    QWidget *widget;
    QWidget *widget_11;
    QGridLayout *gridLayout_3;
    QToolButton *tb_refresh;
    QWidget *widget_14;
    QWidget *w_available;
    QGridLayout *gridLayout_12;
    CxListWidget *lw_1;
    QWidget *widget_6;
    QGridLayout *gridLayout_8;
    QWidget *widget_5;
    QGridLayout *gridLayout_6;
    QWidget *widget_10;
    QLabel *lb_path_hint;
    QWidget *widget_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    QToolButton *tb_choose;
    QWidget *w_control;
    QGridLayout *gridLayout_13;
    QToolButton *tb_add;
    QWidget *widget_7;
    QGridLayout *gridLayout_9;
    QToolButton *tb_unprotect;
    QToolButton *tb_protect;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_12;
    QWidget *widget_15;

    void setupUi(QWidget *Form_MainWindow)
    {
        if (Form_MainWindow->objectName().isEmpty())
            Form_MainWindow->setObjectName(QStringLiteral("Form_MainWindow"));
        Form_MainWindow->resize(523, 540);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/icon/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form_MainWindow->setWindowIcon(icon);
        Form_MainWindow->setStyleSheet(QStringLiteral("background-color:#F9F9F9;"));
        gridLayout = new QGridLayout(Form_MainWindow);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_13 = new QWidget(Form_MainWindow);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setMinimumSize(QSize(0, 20));
        widget_13->setMaximumSize(QSize(16777215, 20));
        widget_13->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#C3C3C3;\n"
"}"));

        gridLayout->addWidget(widget_13, 2, 0, 1, 1);

        widget_3 = new QWidget(Form_MainWindow);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 50));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(20);
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background:#7F7F7F;\n"
"color:black;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);

        widget_8 = new QWidget(Form_MainWindow);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 50));
        widget_8->setMaximumSize(QSize(16777215, 50));
        widget_8->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:transparent;\n"
"}"));
        gridLayout_11 = new QGridLayout(widget_8);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(10, 0, 10, 0);
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 50));
        gridLayout_2 = new QGridLayout(widget_9);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_path_2 = new QLabel(widget_9);
        lbl_path_2->setObjectName(QStringLiteral("lbl_path_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_path_2->sizePolicy().hasHeightForWidth());
        lbl_path_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Impact"));
        font1.setPointSize(16);
        lbl_path_2->setFont(font1);
        lbl_path_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#545454;\n"
"}"));
        lbl_path_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lbl_path_2, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_9, 0, 1, 1, 1);

        widget = new QWidget(widget_8);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(70, 16777215));

        gridLayout_11->addWidget(widget, 0, 0, 1, 1);

        widget_11 = new QWidget(widget_8);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 50));
        widget_11->setMaximumSize(QSize(70, 16777215));
        gridLayout_3 = new QGridLayout(widget_11);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tb_refresh = new QToolButton(widget_11);
        tb_refresh->setObjectName(QStringLiteral("tb_refresh"));
        tb_refresh->setMinimumSize(QSize(40, 40));
        tb_refresh->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/icon/Reload-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_refresh->setIcon(icon1);
        tb_refresh->setIconSize(QSize(40, 40));

        gridLayout_3->addWidget(tb_refresh, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_11, 0, 2, 1, 1);


        gridLayout->addWidget(widget_8, 5, 0, 1, 1);

        widget_14 = new QWidget(Form_MainWindow);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(0, 10));
        widget_14->setMaximumSize(QSize(16777215, 10));
        widget_14->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#C3C3C3;\n"
"}"));

        gridLayout->addWidget(widget_14, 7, 0, 1, 1);

        w_available = new QWidget(Form_MainWindow);
        w_available->setObjectName(QStringLiteral("w_available"));
        w_available->setMinimumSize(QSize(0, 160));
        w_available->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:transparent;\n"
"}"));
        gridLayout_12 = new QGridLayout(w_available);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 5, 0, 5);
        lw_1 = new CxListWidget(w_available);
        lw_1->setObjectName(QStringLiteral("lw_1"));
        lw_1->setMinimumSize(QSize(0, 150));
        lw_1->setMaximumSize(QSize(300, 16777215));

        gridLayout_12->addWidget(lw_1, 0, 0, 1, 1);


        gridLayout->addWidget(w_available, 6, 0, 1, 1);

        widget_6 = new QWidget(Form_MainWindow);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 50));
        widget_6->setMaximumSize(QSize(16777215, 50));
        widget_6->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:transparent;\n"
"}"));
        gridLayout_8 = new QGridLayout(widget_6);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 50));
        widget_5->setMaximumSize(QSize(16777215, 50));
        gridLayout_6 = new QGridLayout(widget_5);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 10, 0);
        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QStringLiteral("widget_10"));

        gridLayout_6->addWidget(widget_10, 0, 0, 1, 1);

        lb_path_hint = new QLabel(widget_5);
        lb_path_hint->setObjectName(QStringLiteral("lb_path_hint"));
        lb_path_hint->setMinimumSize(QSize(40, 40));
        lb_path_hint->setMaximumSize(QSize(40, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Impact"));
        font2.setPointSize(18);
        lb_path_hint->setFont(font2);
        lb_path_hint->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background:#7F7F7F;\n"
"}"));
        lb_path_hint->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lb_path_hint, 0, 1, 1, 1);


        gridLayout_8->addWidget(widget_5, 0, 2, 1, 1);

        widget_2 = new QWidget(widget_6);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 50));
        widget_2->setMaximumSize(QSize(16777215, 50));

        gridLayout_8->addWidget(widget_2, 0, 0, 1, 1);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(180, 50));
        widget_4->setMaximumSize(QSize(180, 50));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tb_choose = new QToolButton(widget_4);
        tb_choose->setObjectName(QStringLiteral("tb_choose"));
        tb_choose->setMinimumSize(QSize(150, 40));
        tb_choose->setMaximumSize(QSize(150, 40));
        tb_choose->setFont(font1);

        gridLayout_5->addWidget(tb_choose, 0, 0, 1, 1);

        tb_choose->raise();
        tb_choose->raise();

        gridLayout_8->addWidget(widget_4, 0, 1, 1, 1);


        gridLayout->addWidget(widget_6, 1, 0, 1, 1);

        w_control = new QWidget(Form_MainWindow);
        w_control->setObjectName(QStringLiteral("w_control"));
        w_control->setMinimumSize(QSize(0, 100));
        w_control->setMaximumSize(QSize(16777215, 100));
        w_control->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:transparent;\n"
"}"));
        gridLayout_13 = new QGridLayout(w_control);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(10, 3, 10, 3);
        tb_add = new QToolButton(w_control);
        tb_add->setObjectName(QStringLiteral("tb_add"));
        tb_add->setMinimumSize(QSize(200, 40));
        tb_add->setMaximumSize(QSize(200, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Impact"));
        font3.setPointSize(24);
        tb_add->setFont(font3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/icon/Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_add->setIcon(icon2);
        tb_add->setIconSize(QSize(40, 40));
        tb_add->setToolButtonStyle(Qt::ToolButtonTextOnly);

        gridLayout_13->addWidget(tb_add, 0, 0, 1, 1);


        gridLayout->addWidget(w_control, 8, 0, 1, 1);

        widget_7 = new QWidget(Form_MainWindow);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 50));
        widget_7->setMaximumSize(QSize(16777215, 50));
        widget_7->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:transparent;\n"
"}"));
        gridLayout_9 = new QGridLayout(widget_7);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        tb_unprotect = new QToolButton(widget_7);
        tb_unprotect->setObjectName(QStringLiteral("tb_unprotect"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_unprotect->sizePolicy().hasHeightForWidth());
        tb_unprotect->setSizePolicy(sizePolicy1);
        tb_unprotect->setMinimumSize(QSize(0, 40));
        tb_unprotect->setMaximumSize(QSize(11111, 40));
        tb_unprotect->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/icon/unlock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_unprotect->setIcon(icon3);
        tb_unprotect->setIconSize(QSize(50, 50));
        tb_unprotect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_9->addWidget(tb_unprotect, 0, 2, 1, 1);

        tb_protect = new QToolButton(widget_7);
        tb_protect->setObjectName(QStringLiteral("tb_protect"));
        sizePolicy1.setHeightForWidth(tb_protect->sizePolicy().hasHeightForWidth());
        tb_protect->setSizePolicy(sizePolicy1);
        tb_protect->setMinimumSize(QSize(0, 40));
        tb_protect->setMaximumSize(QSize(111111, 40));
        tb_protect->setFont(font1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/res/icon/lock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_protect->setIcon(icon4);
        tb_protect->setIconSize(QSize(50, 50));
        tb_protect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_9->addWidget(tb_protect, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 3, 1, 1);


        gridLayout->addWidget(widget_7, 3, 0, 1, 1);

        widget_12 = new QWidget(Form_MainWindow);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 20));
        widget_12->setMaximumSize(QSize(16777215, 20));
        widget_12->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#C3C3C3;\n"
"}"));

        gridLayout->addWidget(widget_12, 4, 0, 1, 1);

        widget_15 = new QWidget(Form_MainWindow);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMinimumSize(QSize(0, 30));
        widget_15->setMaximumSize(QSize(16777215, 30));
        widget_15->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#C3C3C3;\n"
"}"));

        gridLayout->addWidget(widget_15, 9, 0, 1, 1);


        retranslateUi(Form_MainWindow);

        QMetaObject::connectSlotsByName(Form_MainWindow);
    } // setupUi

    void retranslateUi(QWidget *Form_MainWindow)
    {
        Form_MainWindow->setWindowTitle(QApplication::translate("Form_MainWindow", "Protect Stick", 0));
        label_3->setText(QApplication::translate("Form_MainWindow", "USB-DATA-PROTECT", 0));
        lbl_path_2->setText(QApplication::translate("Form_MainWindow", "Available USB Sticks", 0));
        tb_refresh->setText(QApplication::translate("Form_MainWindow", "-", 0));
        lb_path_hint->setText(QApplication::translate("Form_MainWindow", "?", 0));
        tb_choose->setText(QApplication::translate("Form_MainWindow", "CHOOSE DATA", 0));
        tb_add->setText(QApplication::translate("Form_MainWindow", "+COMPILE", 0));
        tb_unprotect->setText(QApplication::translate("Form_MainWindow", "UnProtect", 0));
        tb_protect->setText(QApplication::translate("Form_MainWindow", "Protect", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_MainWindow: public Ui_Form_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

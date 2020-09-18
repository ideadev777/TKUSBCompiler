/********************************************************************************
** Form generated from reading UI file 'tkprotect.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TKPROTECT_H
#define UI_TKPROTECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TKProtectClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *TKProtectClass)
    {
        if (TKProtectClass->objectName().isEmpty())
            TKProtectClass->setObjectName(QStringLiteral("TKProtectClass"));
        TKProtectClass->resize(619, 51);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/icon/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        TKProtectClass->setWindowIcon(icon);
        centralWidget = new QWidget(TKProtectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 10));
        progressBar->setMaximumSize(QSize(16777215, 10));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);

        TKProtectClass->setCentralWidget(centralWidget);

        retranslateUi(TKProtectClass);

        QMetaObject::connectSlotsByName(TKProtectClass);
    } // setupUi

    void retranslateUi(QMainWindow *TKProtectClass)
    {
        TKProtectClass->setWindowTitle(QApplication::translate("TKProtectClass", "Protected Software", 0));
        label->setText(QApplication::translate("TKProtectClass", "Checking...", 0));
    } // retranslateUi

};

namespace Ui {
    class TKProtectClass: public Ui_TKProtectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TKPROTECT_H

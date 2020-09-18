/********************************************************************************
** Form generated from reading UI file 'w_list_piece.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_LIST_PIECE_H
#define UI_W_LIST_PIECE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_PieceWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lbl_pix;
    QLabel *lbl_txt;
    QLabel *lbl_drive;

    void setupUi(QWidget *Form_PieceWidget)
    {
        if (Form_PieceWidget->objectName().isEmpty())
            Form_PieceWidget->setObjectName(QStringLiteral("Form_PieceWidget"));
        Form_PieceWidget->resize(400, 40);
        Form_PieceWidget->setMinimumSize(QSize(0, 40));
        Form_PieceWidget->setMaximumSize(QSize(16777215, 40));
        gridLayout = new QGridLayout(Form_PieceWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 2, 0, 2);
        lbl_pix = new QLabel(Form_PieceWidget);
        lbl_pix->setObjectName(QStringLiteral("lbl_pix"));
        lbl_pix->setMinimumSize(QSize(40, 0));
        lbl_pix->setMaximumSize(QSize(40, 16777215));
        lbl_pix->setScaledContents(true);

        gridLayout->addWidget(lbl_pix, 0, 2, 1, 1);

        lbl_txt = new QLabel(Form_PieceWidget);
        lbl_txt->setObjectName(QStringLiteral("lbl_txt"));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(16);
        lbl_txt->setFont(font);

        gridLayout->addWidget(lbl_txt, 0, 1, 1, 1);

        lbl_drive = new QLabel(Form_PieceWidget);
        lbl_drive->setObjectName(QStringLiteral("lbl_drive"));
        lbl_drive->setMinimumSize(QSize(40, 0));
        lbl_drive->setMaximumSize(QSize(40, 16777215));
        lbl_drive->setFont(font);
        lbl_drive->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl_drive, 0, 0, 1, 1);


        retranslateUi(Form_PieceWidget);

        QMetaObject::connectSlotsByName(Form_PieceWidget);
    } // setupUi

    void retranslateUi(QWidget *Form_PieceWidget)
    {
        Form_PieceWidget->setWindowTitle(QApplication::translate("Form_PieceWidget", "Form", 0));
        lbl_pix->setText(QString());
        lbl_txt->setText(QApplication::translate("Form_PieceWidget", "SERIAL NUMBER", 0));
        lbl_drive->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_PieceWidget: public Ui_Form_PieceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_LIST_PIECE_H

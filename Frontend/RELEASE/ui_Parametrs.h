/********************************************************************************
** Form generated from reading UI file 'Parametrs.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRS_H
#define UI_PARAMETRS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CParametrs
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLineEdit *name_tourchTakeOff;
    QWidget *edit_imageFile;
    QHBoxLayout *horizontalLayout;
    QLineEdit *text_imageFile;
    QPushButton *icon_imageFile;
    QLineEdit *edit_name_paintMmPerSquareMeter;
    QLineEdit *name_imageFile;
    QLineEdit *edit_standardSizeMillimeters;
    QLineEdit *name_paintMmPerSquareMeter;
    QLineEdit *name_costPerLiter;
    QSpacerItem *verticalSpacer;
    QLineEdit *name_torchWidthMillimeters;
    QLineEdit *name_standardSizeMillimeters;
    QLineEdit *edit_costPerLiter;
    QLineEdit *name_standardDetail;
    QLineEdit *edit_torchWidthMillimeters;
    QLineEdit *edit_tourchTakeOff;
    QComboBox *cmb_standardDetail;

    void setupUi(QWidget *CParametrs)
    {
        if (CParametrs->objectName().isEmpty())
            CParametrs->setObjectName(QString::fromUtf8("CParametrs"));
        CParametrs->resize(370, 290);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CParametrs->sizePolicy().hasHeightForWidth());
        CParametrs->setSizePolicy(sizePolicy);
        CParametrs->setMinimumSize(QSize(370, 290));
        CParametrs->setAutoFillBackground(false);
        CParametrs->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        gridLayout = new QGridLayout(CParametrs);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(9);
        gridLayout->setContentsMargins(0, 9, 0, 9);
        widget = new QWidget(CParametrs);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8("background:rgb(43, 45, 49)"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        name_tourchTakeOff = new QLineEdit(widget);
        name_tourchTakeOff->setObjectName(QString::fromUtf8("name_tourchTakeOff"));
        name_tourchTakeOff->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(name_tourchTakeOff->sizePolicy().hasHeightForWidth());
        name_tourchTakeOff->setSizePolicy(sizePolicy2);
        name_tourchTakeOff->setMinimumSize(QSize(220, 0));
        name_tourchTakeOff->setFont(font);
        name_tourchTakeOff->setContextMenuPolicy(Qt::DefaultContextMenu);
        name_tourchTakeOff->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_tourchTakeOff->setMaxLength(32765);
        name_tourchTakeOff->setFrame(false);
        name_tourchTakeOff->setAlignment(Qt::AlignCenter);
        name_tourchTakeOff->setDragEnabled(false);
        name_tourchTakeOff->setReadOnly(true);
        name_tourchTakeOff->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_tourchTakeOff, 4, 0, 1, 1);

        edit_imageFile = new QWidget(widget);
        edit_imageFile->setObjectName(QString::fromUtf8("edit_imageFile"));
        horizontalLayout = new QHBoxLayout(edit_imageFile);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        text_imageFile = new QLineEdit(edit_imageFile);
        text_imageFile->setObjectName(QString::fromUtf8("text_imageFile"));
        text_imageFile->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(text_imageFile->sizePolicy().hasHeightForWidth());
        text_imageFile->setSizePolicy(sizePolicy3);
        text_imageFile->setFont(font);
        text_imageFile->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(88, 88, 88)"));

        horizontalLayout->addWidget(text_imageFile);

        icon_imageFile = new QPushButton(edit_imageFile);
        icon_imageFile->setObjectName(QString::fromUtf8("icon_imageFile"));
        icon_imageFile->setMinimumSize(QSize(40, 24));
        icon_imageFile->setMaximumSize(QSize(40, 24));
        icon_imageFile->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon_imageFile->setIcon(icon);
        icon_imageFile->setIconSize(QSize(24, 24));
        icon_imageFile->setFlat(true);

        horizontalLayout->addWidget(icon_imageFile);


        gridLayout_2->addWidget(edit_imageFile, 0, 2, 1, 1);

        edit_name_paintMmPerSquareMeter = new QLineEdit(widget);
        edit_name_paintMmPerSquareMeter->setObjectName(QString::fromUtf8("edit_name_paintMmPerSquareMeter"));
        sizePolicy3.setHeightForWidth(edit_name_paintMmPerSquareMeter->sizePolicy().hasHeightForWidth());
        edit_name_paintMmPerSquareMeter->setSizePolicy(sizePolicy3);
        edit_name_paintMmPerSquareMeter->setFont(font);
        edit_name_paintMmPerSquareMeter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(edit_name_paintMmPerSquareMeter, 8, 2, 1, 1);

        name_imageFile = new QLineEdit(widget);
        name_imageFile->setObjectName(QString::fromUtf8("name_imageFile"));
        name_imageFile->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_imageFile->sizePolicy().hasHeightForWidth());
        name_imageFile->setSizePolicy(sizePolicy2);
        name_imageFile->setMinimumSize(QSize(220, 0));
        name_imageFile->setFont(font);
        name_imageFile->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_imageFile->setMaxLength(32765);
        name_imageFile->setFrame(false);
        name_imageFile->setAlignment(Qt::AlignCenter);
        name_imageFile->setDragEnabled(false);
        name_imageFile->setReadOnly(true);
        name_imageFile->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_imageFile, 0, 0, 1, 1);

        edit_standardSizeMillimeters = new QLineEdit(widget);
        edit_standardSizeMillimeters->setObjectName(QString::fromUtf8("edit_standardSizeMillimeters"));
        sizePolicy3.setHeightForWidth(edit_standardSizeMillimeters->sizePolicy().hasHeightForWidth());
        edit_standardSizeMillimeters->setSizePolicy(sizePolicy3);
        edit_standardSizeMillimeters->setFont(font);
        edit_standardSizeMillimeters->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(edit_standardSizeMillimeters, 1, 2, 1, 1);

        name_paintMmPerSquareMeter = new QLineEdit(widget);
        name_paintMmPerSquareMeter->setObjectName(QString::fromUtf8("name_paintMmPerSquareMeter"));
        name_paintMmPerSquareMeter->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_paintMmPerSquareMeter->sizePolicy().hasHeightForWidth());
        name_paintMmPerSquareMeter->setSizePolicy(sizePolicy2);
        name_paintMmPerSquareMeter->setMinimumSize(QSize(220, 0));
        name_paintMmPerSquareMeter->setFont(font);
        name_paintMmPerSquareMeter->setAutoFillBackground(false);
        name_paintMmPerSquareMeter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_paintMmPerSquareMeter->setMaxLength(32765);
        name_paintMmPerSquareMeter->setFrame(false);
        name_paintMmPerSquareMeter->setAlignment(Qt::AlignCenter);
        name_paintMmPerSquareMeter->setDragEnabled(false);
        name_paintMmPerSquareMeter->setReadOnly(true);
        name_paintMmPerSquareMeter->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_paintMmPerSquareMeter, 8, 0, 1, 1);

        name_costPerLiter = new QLineEdit(widget);
        name_costPerLiter->setObjectName(QString::fromUtf8("name_costPerLiter"));
        name_costPerLiter->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_costPerLiter->sizePolicy().hasHeightForWidth());
        name_costPerLiter->setSizePolicy(sizePolicy2);
        name_costPerLiter->setMinimumSize(QSize(220, 0));
        name_costPerLiter->setFont(font);
        name_costPerLiter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_costPerLiter->setMaxLength(32765);
        name_costPerLiter->setFrame(false);
        name_costPerLiter->setAlignment(Qt::AlignCenter);
        name_costPerLiter->setDragEnabled(false);
        name_costPerLiter->setReadOnly(true);
        name_costPerLiter->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_costPerLiter, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 0, 1, 1);

        name_torchWidthMillimeters = new QLineEdit(widget);
        name_torchWidthMillimeters->setObjectName(QString::fromUtf8("name_torchWidthMillimeters"));
        name_torchWidthMillimeters->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_torchWidthMillimeters->sizePolicy().hasHeightForWidth());
        name_torchWidthMillimeters->setSizePolicy(sizePolicy2);
        name_torchWidthMillimeters->setMinimumSize(QSize(220, 0));
        name_torchWidthMillimeters->setFont(font);
        name_torchWidthMillimeters->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_torchWidthMillimeters->setMaxLength(32765);
        name_torchWidthMillimeters->setFrame(false);
        name_torchWidthMillimeters->setAlignment(Qt::AlignCenter);
        name_torchWidthMillimeters->setDragEnabled(false);
        name_torchWidthMillimeters->setReadOnly(true);
        name_torchWidthMillimeters->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_torchWidthMillimeters, 3, 0, 1, 1);

        name_standardSizeMillimeters = new QLineEdit(widget);
        name_standardSizeMillimeters->setObjectName(QString::fromUtf8("name_standardSizeMillimeters"));
        name_standardSizeMillimeters->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_standardSizeMillimeters->sizePolicy().hasHeightForWidth());
        name_standardSizeMillimeters->setSizePolicy(sizePolicy2);
        name_standardSizeMillimeters->setMinimumSize(QSize(220, 0));
        name_standardSizeMillimeters->setFont(font);
        name_standardSizeMillimeters->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_standardSizeMillimeters->setMaxLength(32765);
        name_standardSizeMillimeters->setFrame(false);
        name_standardSizeMillimeters->setAlignment(Qt::AlignCenter);
        name_standardSizeMillimeters->setDragEnabled(false);
        name_standardSizeMillimeters->setReadOnly(true);
        name_standardSizeMillimeters->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_standardSizeMillimeters, 1, 0, 1, 1);

        edit_costPerLiter = new QLineEdit(widget);
        edit_costPerLiter->setObjectName(QString::fromUtf8("edit_costPerLiter"));
        sizePolicy3.setHeightForWidth(edit_costPerLiter->sizePolicy().hasHeightForWidth());
        edit_costPerLiter->setSizePolicy(sizePolicy3);
        edit_costPerLiter->setFont(font);
        edit_costPerLiter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(edit_costPerLiter, 7, 2, 1, 1);

        name_standardDetail = new QLineEdit(widget);
        name_standardDetail->setObjectName(QString::fromUtf8("name_standardDetail"));
        name_standardDetail->setEnabled(true);
        sizePolicy2.setHeightForWidth(name_standardDetail->sizePolicy().hasHeightForWidth());
        name_standardDetail->setSizePolicy(sizePolicy2);
        name_standardDetail->setMinimumSize(QSize(220, 0));
        name_standardDetail->setFont(font);
        name_standardDetail->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        name_standardDetail->setMaxLength(32765);
        name_standardDetail->setFrame(false);
        name_standardDetail->setAlignment(Qt::AlignCenter);
        name_standardDetail->setDragEnabled(false);
        name_standardDetail->setReadOnly(true);
        name_standardDetail->setClearButtonEnabled(false);

        gridLayout_2->addWidget(name_standardDetail, 2, 0, 1, 1);

        edit_torchWidthMillimeters = new QLineEdit(widget);
        edit_torchWidthMillimeters->setObjectName(QString::fromUtf8("edit_torchWidthMillimeters"));
        sizePolicy3.setHeightForWidth(edit_torchWidthMillimeters->sizePolicy().hasHeightForWidth());
        edit_torchWidthMillimeters->setSizePolicy(sizePolicy3);
        edit_torchWidthMillimeters->setFont(font);
        edit_torchWidthMillimeters->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(edit_torchWidthMillimeters, 3, 2, 1, 1);

        edit_tourchTakeOff = new QLineEdit(widget);
        edit_tourchTakeOff->setObjectName(QString::fromUtf8("edit_tourchTakeOff"));
        sizePolicy3.setHeightForWidth(edit_tourchTakeOff->sizePolicy().hasHeightForWidth());
        edit_tourchTakeOff->setSizePolicy(sizePolicy3);
        edit_tourchTakeOff->setFont(font);
        edit_tourchTakeOff->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(edit_tourchTakeOff, 4, 2, 1, 1);

        cmb_standardDetail = new QComboBox(widget);
        cmb_standardDetail->setObjectName(QString::fromUtf8("cmb_standardDetail"));
        cmb_standardDetail->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout_2->addWidget(cmb_standardDetail, 2, 2, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(CParametrs);

        QMetaObject::connectSlotsByName(CParametrs);
    } // setupUi

    void retranslateUi(QWidget *CParametrs)
    {
        CParametrs->setWindowTitle(QCoreApplication::translate("CParametrs", "Form", nullptr));
        name_tourchTakeOff->setText(QCoreApplication::translate("CParametrs", "Tourch Take Off Mm", nullptr));
        icon_imageFile->setText(QString());
        name_imageFile->setText(QCoreApplication::translate("CParametrs", "Image file", nullptr));
        name_paintMmPerSquareMeter->setText(QCoreApplication::translate("CParametrs", "Paint Mm per square Meter", nullptr));
        name_costPerLiter->setText(QCoreApplication::translate("CParametrs", "Cost per liter Mm", nullptr));
        name_torchWidthMillimeters->setText(QCoreApplication::translate("CParametrs", "Torch Width Millimeters", nullptr));
        name_standardSizeMillimeters->setText(QCoreApplication::translate("CParametrs", "Standard Size Millimeters", nullptr));
        name_standardDetail->setText(QCoreApplication::translate("CParametrs", "Standard Detail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CParametrs: public Ui_CParametrs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRS_H

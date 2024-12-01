/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImageScene.h"
#include "Parametrs.h"
#include "RecognizeObjects.h"

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_save;
    QPushButton *btn_load;
    QSpacerItem *horizontalSpacer;
    QLabel *lbl_login;
    QLabel *edit_login;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_params;
    QVBoxLayout *verticalLayout_2;
    CParametrs *params;
    QWidget *widget_btnParams;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_calc;
    QWidget *widget_imageScene;
    QGridLayout *gridLayout;
    CImageScene *imageScene;
    QVBoxLayout *verticalLayout_3;
    CRecognizeObjects *widget_objects;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QString::fromUtf8("CMainWindow"));
        CMainWindow->resize(1028, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CMainWindow->sizePolicy().hasHeightForWidth());
        CMainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(CMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background: rgb(49, 51, 56)"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 6, 0);
        btn_save = new QPushButton(widget_2);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(btn_save);

        btn_load = new QPushButton(widget_2);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        btn_load->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(btn_load);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lbl_login = new QLabel(widget_2);
        lbl_login->setObjectName(QString::fromUtf8("lbl_login"));
        lbl_login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(lbl_login);

        edit_login = new QLabel(widget_2);
        edit_login->setObjectName(QString::fromUtf8("edit_login"));
        edit_login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(edit_login);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_params = new QWidget(widget);
        widget_params->setObjectName(QString::fromUtf8("widget_params"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_params->sizePolicy().hasHeightForWidth());
        widget_params->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(widget_params);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 6);
        params = new CParametrs(widget_params);
        params->setObjectName(QString::fromUtf8("params"));
        sizePolicy3.setHeightForWidth(params->sizePolicy().hasHeightForWidth());
        params->setSizePolicy(sizePolicy3);
        params->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));

        verticalLayout_2->addWidget(params);

        widget_btnParams = new QWidget(widget_params);
        widget_btnParams->setObjectName(QString::fromUtf8("widget_btnParams"));
        sizePolicy2.setHeightForWidth(widget_btnParams->sizePolicy().hasHeightForWidth());
        widget_btnParams->setSizePolicy(sizePolicy2);
        widget_btnParams->setMaximumSize(QSize(16777215, 24));
        widget_btnParams->setStyleSheet(QString::fromUtf8(" background:rgb(255, 255, 255)"));
        horizontalLayout_2 = new QHBoxLayout(widget_btnParams);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_calc = new QPushButton(widget_btnParams);
        btn_calc->setObjectName(QString::fromUtf8("btn_calc"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_calc->sizePolicy().hasHeightForWidth());
        btn_calc->setSizePolicy(sizePolicy4);
        btn_calc->setFlat(false);

        horizontalLayout_2->addWidget(btn_calc);


        verticalLayout_2->addWidget(widget_btnParams);


        horizontalLayout->addWidget(widget_params);

        widget_imageScene = new QWidget(widget);
        widget_imageScene->setObjectName(QString::fromUtf8("widget_imageScene"));
        sizePolicy2.setHeightForWidth(widget_imageScene->sizePolicy().hasHeightForWidth());
        widget_imageScene->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(widget_imageScene);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        imageScene = new CImageScene(widget_imageScene);
        imageScene->setObjectName(QString::fromUtf8("imageScene"));
        sizePolicy2.setHeightForWidth(imageScene->sizePolicy().hasHeightForWidth());
        imageScene->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(imageScene);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        gridLayout->addWidget(imageScene, 0, 1, 1, 1);


        horizontalLayout->addWidget(widget_imageScene);

        widget_objects = new CRecognizeObjects(widget);
        widget_objects->setObjectName(QString::fromUtf8("widget_objects"));
        sizePolicy3.setHeightForWidth(widget_objects->sizePolicy().hasHeightForWidth());
        widget_objects->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(widget_objects);


        verticalLayout->addWidget(widget);

        CMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1028, 21));
        CMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CMainWindow->setStatusBar(statusbar);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QCoreApplication::translate("CMainWindow", "CMainWindow", nullptr));
        btn_save->setText(QCoreApplication::translate("CMainWindow", "Save", nullptr));
        btn_load->setText(QCoreApplication::translate("CMainWindow", "Load", nullptr));
        lbl_login->setText(QCoreApplication::translate("CMainWindow", "Login", nullptr));
        edit_login->setText(QString());
        btn_calc->setText(QCoreApplication::translate("CMainWindow", "Calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'Authorization.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAuthorization
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *edit_password;
    QLabel *lbl_login;
    QLineEdit *edit_login;
    QLabel *lbl_password;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_authorization;

    void setupUi(QWidget *CAuthorization)
    {
        if (CAuthorization->objectName().isEmpty())
            CAuthorization->setObjectName(QString::fromUtf8("CAuthorization"));
        CAuthorization->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAuthorization->sizePolicy().hasHeightForWidth());
        CAuthorization->setSizePolicy(sizePolicy);
        CAuthorization->setMinimumSize(QSize(400, 300));
        CAuthorization->setMaximumSize(QSize(400, 300));
        CAuthorization->setStyleSheet(QString::fromUtf8("background: rgb(49, 51, 56)"));
        verticalLayout = new QVBoxLayout(CAuthorization);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(CAuthorization);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        edit_password = new QLineEdit(widget);
        edit_password->setObjectName(QString::fromUtf8("edit_password"));
        edit_password->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout->addWidget(edit_password, 2, 1, 1, 1);

        lbl_login = new QLabel(widget);
        lbl_login->setObjectName(QString::fromUtf8("lbl_login"));
        lbl_login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout->addWidget(lbl_login, 1, 0, 1, 1);

        edit_login = new QLineEdit(widget);
        edit_login->setObjectName(QString::fromUtf8("edit_login"));
        edit_login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout->addWidget(edit_login, 1, 1, 1, 1);

        lbl_password = new QLabel(widget);
        lbl_password->setObjectName(QString::fromUtf8("lbl_password"));
        lbl_password->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        gridLayout->addWidget(lbl_password, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(CAuthorization);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_authorization = new QPushButton(widget_2);
        btn_authorization->setObjectName(QString::fromUtf8("btn_authorization"));
        btn_authorization->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        horizontalLayout->addWidget(btn_authorization);


        verticalLayout->addWidget(widget_2);


        retranslateUi(CAuthorization);

        QMetaObject::connectSlotsByName(CAuthorization);
    } // setupUi

    void retranslateUi(QWidget *CAuthorization)
    {
        CAuthorization->setWindowTitle(QCoreApplication::translate("CAuthorization", "Form", nullptr));
        lbl_login->setText(QCoreApplication::translate("CAuthorization", "Login", nullptr));
        lbl_password->setText(QCoreApplication::translate("CAuthorization", "Password", nullptr));
        btn_authorization->setText(QCoreApplication::translate("CAuthorization", "Authorization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAuthorization: public Ui_CAuthorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H

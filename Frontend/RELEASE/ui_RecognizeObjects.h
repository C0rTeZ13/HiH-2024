/********************************************************************************
** Form generated from reading UI file 'RecognizeObjects.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNIZEOBJECTS_H
#define UI_RECOGNIZEOBJECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRecognizeObjects
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_objTree;

    void setupUi(QWidget *CRecognizeObjects)
    {
        if (CRecognizeObjects->objectName().isEmpty())
            CRecognizeObjects->setObjectName(QString::fromUtf8("CRecognizeObjects"));
        CRecognizeObjects->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CRecognizeObjects->sizePolicy().hasHeightForWidth());
        CRecognizeObjects->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CRecognizeObjects);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 9, 0, 9);
        widget_objTree = new QWidget(CRecognizeObjects);
        widget_objTree->setObjectName(QString::fromUtf8("widget_objTree"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_objTree->sizePolicy().hasHeightForWidth());
        widget_objTree->setSizePolicy(sizePolicy1);
        widget_objTree->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));

        verticalLayout->addWidget(widget_objTree);


        retranslateUi(CRecognizeObjects);

        QMetaObject::connectSlotsByName(CRecognizeObjects);
    } // setupUi

    void retranslateUi(QWidget *CRecognizeObjects)
    {
        CRecognizeObjects->setWindowTitle(QCoreApplication::translate("CRecognizeObjects", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRecognizeObjects: public Ui_CRecognizeObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNIZEOBJECTS_H

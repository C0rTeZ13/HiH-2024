#include "Parametrs.h"
#include "ui_Parametrs.h"

#include <QDebug>
#include <QString>
#include <QFile>
#include <QFileDialog>

CParametrs::CParametrs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CParametrs)
{
    ui->setupUi(this);
}

CParametrs::~CParametrs()
{
    delete ui;
}

QString CParametrs::getImage()
{
    return m_fileName;
}

StructSize* CParametrs::getStandartSize()
{
    return &m_standartSize;
}

int CParametrs::getTorchWidth()
{
    return m_torchWidth;
}

int CParametrs::getTorchTakeOff()
{
    return m_torchTakeOff;
}

int CParametrs::getCostPerLiter()
{
    return m_costPerLiter;
}

int CParametrs::getPaintMmPerSquareMeter()
{
    return m_paintMmPerSquareMeter;
}

void CParametrs::on_text_imageFile_textEdited(const QString &arg1)
{
    m_fileName = arg1;
    qDebug() << m_fileName;
}

void CParametrs::on_edit_frontDoor_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_standartSize.m_frontDoor = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_bonnet_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_standartSize.m_bonnet = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_trunkLink_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_standartSize.m_trunkLid = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_tourchWidth_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_torchWidth = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_tourchTakeOff_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_torchTakeOff = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_costPerLiter_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_costPerLiter = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_edit_name_paintMmPerSquareMeter_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_paintMmPerSquareMeter = number;
    }
    else
    {
        //emit error
    }
}

void CParametrs::on_icon_imageFile_clicked()
{
    QString str = QFileDialog::getOpenFileName(nullptr, tr("Load Image"), m_fileName, tr("Imsges (*.png *.jpg)"));

    ui->text_imageFile->setText(str);
    on_text_imageFile_textEdited(str);
}
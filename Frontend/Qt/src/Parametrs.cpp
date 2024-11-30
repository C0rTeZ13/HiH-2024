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

    m_cmbMap =
    {
        {EDetail::FrontDoor, "FrontDoor"},
        {EDetail::Bonnet, "Bonnet"},
        {EDetail::TrunkLid, "TrunkLid"},
    };

    for (QString str : m_cmbMap)
    {
        ui->cmb_standardDetail->addItem(str);
    }

}

CParametrs::~CParametrs()
{
    delete ui;
}

QString CParametrs::getImage()
{
    return m_fileName;
}

StructParams *CParametrs::getParams()
{
    return &m_params;
}

void CParametrs::on_text_imageFile_textEdited(const QString &arg1)
{
    m_fileName = arg1;

    emit sig_imageChanged(m_fileName);
}

void CParametrs::on_icon_imageFile_clicked()
{
    QString str = QFileDialog::getOpenFileName(nullptr, tr("Load Image"), m_fileName, tr("Imsges (*.png *.jpg)"));

    ui->text_imageFile->setText(str);
    on_text_imageFile_textEdited(str);
}

void CParametrs::on_edit_standardSizeMillimeters_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_params.m_standardSizeMillimeters = number;
    }
    else
    {
        //emit error
    }
}


void CParametrs::on_edit_torchWidthMillimeters_textEdited(const QString &arg1)
{
    if (auto number = arg1.toInt())
    {
        m_params.m_torchWidthMillimeters = number;
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
        m_params.m_torchTakeoffMillimeters = number;
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
        m_params.m_coastPerLiter = number;
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
        m_params.m_paintMillilitersPerSquareMeter = number;
    }
    else
    {
        //emit error
    }
}


void CParametrs::on_cmb_standardDetail_currentIndexChanged(int index)
{
    m_params.standardDetail = m_cmbMap[index];
}


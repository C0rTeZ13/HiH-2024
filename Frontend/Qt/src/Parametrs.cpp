#include "Parametrs.h"
#include "ui_Parametrs.h"

#include <QDebug>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>

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

void CParametrs::save()
{
    QString str = QFileDialog::getSaveFileName(this, tr("Save File As"), "", tr("Files (*.json)"));

    QVariantMap map;

    map.insert("standardSizeMillimeters", m_params.m_standardSizeMillimeters);
    map.insert("standardDetail", m_params.standardDetail);
    map.insert("torchWidthMillimeters", m_params.m_torchWidthMillimeters);
    map.insert("torchTakeoffMillimeters", m_params.m_torchTakeoffMillimeters);
    map.insert("coastPerLiter", m_params.m_coastPerLiter);
    map.insert("paintMillilitersPerSquareMeter", m_params.m_paintMillilitersPerSquareMeter);

    QJsonObject object = QJsonObject::fromVariantMap(map);

    QJsonDocument document;
    document.setObject(object);

    QFile jsonFile(str);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

void CParametrs::load()
{
    QString str = QFileDialog::getOpenFileName(nullptr, tr("Load File"), "", tr("Files (*.json)"));

    QFile jsonFile(str);
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument document = QJsonDocument().fromJson(jsonFile.readAll());

    QJsonObject json = document.object();

    ui->text_imageFile->setText(json["fileName"].toString());
    ui->edit_standardSizeMillimeters->setText(QString::number(json["standardSizeMillimeters"].toInt()));
    ui->edit_torchWidthMillimeters->setText(QString::number(json["torchWidthMillimeters"].toInt()));
    ui->edit_tourchTakeOff->setText(QString::number(json["torchTakeoffMillimeters"].toInt()));
    ui->edit_costPerLiter->setText(QString::number(json["coastPerLiter"].toInt()));
    ui->edit_name_paintMmPerSquareMeter->setText(QString::number(json["paintMillilitersPerSquareMeter"].toInt()));

    int index = 0;

    for (int i = 0; i < m_cmbMap.size(); i++)
    {
        if (m_cmbMap[i] == json["standardDetail"].toString())
        {
            index = i;
        }
    }

    ui->cmb_standardDetail->setCurrentIndex(index);
}

void CParametrs::on_text_imageFile_textChanged(const QString &arg1)
{
    m_fileName = arg1;

    emit sig_imageChanged(m_fileName);
}

void CParametrs::on_icon_imageFile_clicked()
{
    QString str = QFileDialog::getOpenFileName(nullptr, tr("Load Image"), m_fileName, tr("Imsges (*.png *.jpg)"));

    ui->text_imageFile->setText(str);
}


void CParametrs::on_cmb_standardDetail_currentIndexChanged(int index)
{
    m_params.standardDetail = m_cmbMap[index];
}

void CParametrs::on_edit_standardSizeMillimeters_textChanged(const QString &arg1)
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


void CParametrs::on_edit_torchWidthMillimeters_textChanged(const QString &arg1)
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


void CParametrs::on_edit_tourchTakeOff_textChanged(const QString &arg1)
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


void CParametrs::on_edit_costPerLiter_textChanged(const QString &arg1)
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


void CParametrs::on_edit_name_paintMmPerSquareMeter_textChanged(const QString &arg1)
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

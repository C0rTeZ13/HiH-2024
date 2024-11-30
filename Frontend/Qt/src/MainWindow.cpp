#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <Parametrs.h>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QJsonArray>
#include <QBuffer>
#include <QDebug>

#include <Authorization.h>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    // to fix taskbar minimize feature
    //setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    connect(ui->params, &CParametrs::sig_imageChanged, this, &CMainWindow::setScene);

}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::on_btn_calc_clicked()
{
    QString imageName = ui->params->getImage();
    QImage image(imageName);

    StructParams params = *ui->params->getParams();

    //auto size = ui->params->getStandartSize();
    int standartSizeMillimeters = params.m_standardSizeMillimeters;
    QString standardDetail = params.standardDetail;
    int torchWidth = params.m_torchWidthMillimeters;
    int torchTakeOff = params.m_paintMillilitersPerSquareMeter;
    int costPerLiter = params.m_coastPerLiter;
    int paintMmPerSquareMeter = params.m_paintMillilitersPerSquareMeter;

    QNetworkAccessManager *manager = new QNetworkAccessManager ();
    QUrl url("http://94.103.84.36:5086/");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //QJsonArray sizeArray = {size->m_bonnet, size->m_frontDoor, size->m_trunkLid};
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG");
    QByteArray base64Data = byteArray.toBase64();

    QJsonObject json;

    json["image"] = QString::fromLatin1(base64Data);
    //json["size"] = sizeArray;
    json["standardSizeMillimeters"] = standartSizeMillimeters;
    json["standardDetail"] = standardDetail;
    json["torchWidthMillimeters"] = torchWidth;
    json["torchTakeoffMillimeters"] = torchTakeOff;
    json["coastPerLiter"] = costPerLiter;
    json["paintMillilitersPerSquareMeter"] = paintMmPerSquareMeter;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = manager->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Ответ сервера: " << reply->readAll();
        } else {
            qDebug() << "Ошибка: " << reply->errorString();
        }
    });
}

void CMainWindow::setScene(QString filepath)
{
    QImage* img = new QImage(filepath);

    ui->imageScene->setScene(img);
}

void CMainWindow::setAuthorize(QString login)
{
    ui->edit_login->setText(login);
}

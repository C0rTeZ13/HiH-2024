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

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    // to fix taskbar minimize feature
    //setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::on_btn_calc_clicked()
{
    QString imageName = ui->params->getImage();
    QImage image(imageName);
    auto size = ui->params->getStandartSize();
    int torchWidth = ui->params->getTorchWidth();
    int torchTakeOff = ui->params->getTorchTakeOff();
    int costPerLiter = ui->params->getCostPerLiter();
    int paintMmPerSquareMeter = ui->params->getPaintMmPerSquareMeter();

    QNetworkAccessManager *manager = new QNetworkAccessManager ();
    QUrl url("Your awesome url");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonArray sizeArray = {size->m_bonnet, size->m_frontDoor, size->m_trunkLid};
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG");
    QByteArray base64Data = byteArray.toBase64();

    QJsonObject json;

    json["image"] = QString::fromLatin1(base64Data);
    json["size"] = sizeArray;
    json["torchWidth"] = torchWidth;
    json["torchTakeOff"] = torchTakeOff;
    json["costPerLiter"] = costPerLiter;
    json["paintMmPerSquareMeter"] = paintMmPerSquareMeter;

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

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
#include <QHttpPart>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    _url = QString("http://94.103.84.36:5086/");
    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    // to fix taskbar minimize feature
    //setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    connect(ui->params, &CParametrs::sig_imageChanged, this, &CMainWindow::setScene);

}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::sendImageToServer(const QImage &image)
{
    // Сохранение изображения в байтовый массив
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "JPG"); // Сохраняем изображение в формате JPG
    buffer.close();

    // Создание multipart-запроса
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // Создание части запроса для файла
    QHttpPart filePart;
    QString filename = "filename=" + QFileInfo(ui->params->getImage()).fileName();
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"file\"; " + filename));
    filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
    filePart.setBody(byteArray.toBase64());
    multiPart->append(filePart);

    QUrl url(_url + "Image/UploadImage");
    QNetworkRequest request(url);
    QByteArray encodedCredentials = (_login + ":" + _password).toUtf8().toBase64();
    QString authHeader = "Bearer " + _token;
    request.setRawHeader("Authorization", authHeader.toUtf8());

    QNetworkAccessManager *imageManager = new QNetworkAccessManager(this);
    QNetworkReply *imageReply = imageManager->post(request, multiPart);


    multiPart->setParent(imageReply);

    connect(imageReply, &QNetworkReply::finished, this, &CMainWindow::onImageUpload);
}

void CMainWindow::sendDataToServer(QJsonObject json)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QUrl lUrl(_url + "DrawEstimates/CreateEstimates");
    QNetworkRequest request(lUrl);
    QByteArray encodedCredentials = (_login + ":" + _password).toUtf8().toBase64();
    QString authHeader = "Bearer " + _token;
    request.setRawHeader(QByteArray("Authorization"), QByteArray(authHeader.toUtf8()));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();
    auto dataReply = manager->post(request, jsonData);

    connect(dataReply, &QNetworkReply::finished, this, &CMainWindow::onDataUpload);
}

void CMainWindow::onImageUpload()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        StructParams params = *ui->params->getParams();
        int idImage = QJsonDocument::fromJson(reply->readAll())["id"].toInt();
        int standartSizeMillimeters = params.m_standardSizeMillimeters;
        QString standardDetail = params.standardDetail;
        int torchWidth = params.m_torchWidthMillimeters;
        int torchTakeOff = params.m_paintMillilitersPerSquareMeter;
        int costPerLiter = params.m_coastPerLiter;
        int paintMmPerSquareMeter = params.m_paintMillilitersPerSquareMeter;

        QJsonObject json;
        json["originImageId"] = idImage;
        json["standardSizeMillimeters"] = standartSizeMillimeters;
        json["standardDetail"] = standardDetail;
        json["torchWidthMillimeters"] = torchWidth;
        json["torchTakeoffMillimeters"] = torchTakeOff;
        json["coastPerLiter"] = costPerLiter;
        json["paintMillilitersPerSquareMeter"] = paintMmPerSquareMeter;
        sendDataToServer(json);
    } else {
        qDebug() << "Error in uploading image to the server:" << reply->errorString();
    }

    reply->deleteLater();
}

void CMainWindow::onDataUpload()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray responsedData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responsedData);
        if (!jsonDoc.isObject()) {
            qDebug() << "Invalid JSON respons";
            return;
        }
        QJsonObject responseObject = jsonDoc.object();
        QString image = responseObject["imageFile"].toString();
        qDebug() << "Image data: " << image;
        QByteArray imageData = QByteArray::fromBase64(image.toUtf8());
        QFile imageFile("testRecievedImage.jpg");
        if (imageFile.open(QIODevice::WriteOnly)) {
            imageFile.write(imageData);
            imageFile.close();
            qDebug() << "Image recieved and saved";
        } else {
            qDebug() << "Failed to save image";
        }
    } else {
        qDebug() << "Error in data uploading" << reply->errorString();
    }
    reply->deleteLater();
}

void CMainWindow::on_btn_calc_clicked()
{
    QString imageName = ui->params->getImage();
    QImage image(imageName);
    sendImageToServer(image);
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

void CMainWindow::setUser(QString login, QString password)
{
    _login = login;
    _password = password;
}

void CMainWindow::setToken(QString token)
{
    _token = token;
}

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
#include <QSaveFile>


CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    _url = QString("http://89.110.93.9:5086/");
    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    // to fix taskbar minimize feature
    //setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    connect(ui->params, &CParametrs::sig_imageChanged, this, &CMainWindow::setScene);
    connect(ui->params, &CParametrs::sig_imageChanged, ui->widget_objects, &CRecognizeObjects::hideRecognizeObj);

    ui->imageScene->setParent(ui->widget_imageScene);

}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::sendImageToServer(const QImage &image)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "JPG");
    buffer.close();

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // Создание части запроса для файла
    QHttpPart filePart;
    QString filename = "filename=\"" + QFileInfo(ui->params->getImage()).fileName() + "\"";
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"file\"; " + filename));
    filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpg"));

    filePart.setBody(byteArray.toBase64());
    multiPart->append(filePart);

    QUrl url(_url + "Image/UploadImage");
    QNetworkRequest request(url);
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
        qDebug() << idImage;
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
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
        if (!jsonDoc.isObject()) {
            qDebug() << "Invalid JSON response";
            return;
        }
        QString image = jsonDoc["imageFile"].toString();
        QJsonArray detailsEstimates = jsonDoc["detailsEstimates"].toArray(); // Массив рассчитанных площадей элементов

        //QMap<QString,QVector<QString>>

        QMap<int,QString> mapDetails =
        {
            {EParts::back_bumper, "Back Bumper"},
            {EParts::back_door, "Back Door"},
            {EParts::back_wing, "Back Wing"},
            {EParts::bonnet, "Bonnet"},
            {EParts::front_bumper, "Front Bumper"},
            {EParts::front_door, "Front Door"},
            {EParts::front_wing, "Front Wing"},
            {EParts::roof, "roof"},
        };

        QMap<QString,QVector<QString>> recObjs;

        for (const QJsonValue &value : detailsEstimates) {
            QJsonObject estimate = value.toObject();

            int id = estimate["id"].toInt();
            int squareMm = estimate["squareMillimeters"].toInt();
            int paintRateMl = estimate["paintRateMilliliters"].toInt();
            int coast = estimate["coast"].toInt();
            // Все поля, на данный момент получаемые от сервера

            recObjs.insert(mapDetails[id],  {
                                            "squareMm:    " + QString::number(squareMm),
                                            "paintRateMl: " + QString::number(paintRateMl),
                                            "cost:       " + QString::number(coast)
                                            });
        }

        ui->widget_objects->showRecognizeObj(recObjs);

        QByteArray imageData = QByteArray::fromBase64(image.toUtf8());
        QImage terecievedImage;
        terecievedImage.loadFromData(imageData);

        ui->imageScene->setScene(terecievedImage);

        QFile imageFile("testRecievedImage.jpg"); // Тут захардкодил куда сейвится изображение
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
    QImage img(filepath);

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
void CMainWindow::on_btn_save_clicked()
{
    ui->params->save();
}


void CMainWindow::on_btn_load_clicked()
{
    ui->params->load();
}

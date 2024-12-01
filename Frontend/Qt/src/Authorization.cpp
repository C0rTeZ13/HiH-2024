#include "Authorization.h"
#include "ui_Authorization.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


CAuthorization::CAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CAuthorization)
{
    ui->setupUi(this);
    _url = QString("http://89.110.93.9:5086/");
}

CAuthorization::~CAuthorization()
{
    delete ui;
}

void CAuthorization::startMain()
{
    w.show();
}

void CAuthorization::authorize()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QJsonObject json;

    json["userName"] = m_login;
    json["password"] = m_password;
    QJsonDocument jsonDoc(json);

    QByteArray requestData = jsonDoc.toJson();

    QNetworkRequest request(_url + "Login");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, requestData);

    connect(reply, &QNetworkReply::finished, this, &CAuthorization::authorizeResponse);
}

void CAuthorization::authorizeResponse()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);

        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            if (jsonObj.contains("token") && jsonObj["token"].isString()) {
                QString token = jsonObj["token"].toString();
                qDebug() << "Авторизация успешна. Токен:" << token;
                w.setToken(jsonObj["token"].toString());
                w.setUser(m_login, m_password);
            }
        }

        w.setAuthorize(m_login);
        startMain();

        this->hide();
    } else {
        qDebug() << QString::fromUtf8(reply->readAll());
        qDebug() << "Ошибка запроса авторизации: " << reply->errorString();
    }

    reply->deleteLater();
}

void CAuthorization::on_btn_authorization_clicked()
{
    m_login = ui->edit_login->text();
    m_password = ui->edit_password->text();

    if (m_login.isEmpty() || m_password.isEmpty())
    {
        return;
    }
    authorize();
}


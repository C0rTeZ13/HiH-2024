#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

    void setAuthorize(QString login);

    void setToken(QString token);
    void setUser(QString login, QString password);

private slots:
    void on_btn_calc_clicked();

    void setScene(QString filepath);

private:
    Ui::CMainWindow *ui;
    QString _token;
    QString _login;
    QString _password;
    QString _adminToken = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1laWRlbnRpZmllciI6IjRmYmZiOGJmLWFkMTgtNDg0Ni04ZDM4LTJjNTE5Nzc5YmM3OSIsImh0dHA6Ly9zY2hlbWFzLnhtbHNvYXAub3JnL3dzLzIwMDUvMDUvaWRlbnRpdHkvY2xhaW1zL25hbWUiOiJhZG1pbiIsImh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwOC8wNi9pZGVudGl0eS9jbGFpbXMvcm9sZSI6IkFkbWluaXN0cmF0b3IiLCJleHAiOjE3MzU1Nzk4MTB9.L2Je6Yy_xdIQxIQSe7IciqSuEUAX-OuEaius9HybbcI";
    QString _url;
    void sendImageToServer(const QImage &image);
    void sendDataToServer(QJsonObject json);
    void onImageUpload();
    void onDataUpload();
    void sendRequest();

};
#endif // CMAINWINDOW_H

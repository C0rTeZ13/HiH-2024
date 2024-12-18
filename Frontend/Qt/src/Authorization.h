#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

#include "MainWindow.h"

namespace Ui {
class CAuthorization;
}

class CAuthorization : public QWidget
{
    Q_OBJECT

public:
    explicit CAuthorization(QWidget *parent = nullptr);
    ~CAuthorization();

private slots:
    void on_btn_authorization_clicked();

private:
    void startMain();
    void authorize();
    void authorizeResponse();
private:
    // Params
    QString m_login;
    QString m_password;
    QString _url;

    //
    CMainWindow w;
    Ui::CAuthorization *ui;
};

#endif // AUTHORIZATION_H

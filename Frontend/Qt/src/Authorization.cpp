#include "Authorization.h"
#include "ui_Authorization.h"

CAuthorization::CAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CAuthorization)
{
    ui->setupUi(this);
}

CAuthorization::~CAuthorization()
{
    delete ui;
}

void CAuthorization::startMain()
{
    w.show();
}

void CAuthorization::on_btn_authorization_clicked()
{
    m_login = ui->edit_login->text();
    m_password = ui->edit_password->text();

    if (m_login.isEmpty() || m_password.isEmpty())
    {
        return;
    }

    w.setAuthorize(m_login);
    startMain();

    this->hide();
}


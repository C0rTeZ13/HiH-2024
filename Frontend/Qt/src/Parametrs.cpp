#include "Parametrs.h"
#include "ui_Parametrs.h"

CParametrs::CParametrs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CParametrs)
{
    ui->setupUi(this);
}

CParametrs::~CParametrs()
{
    delete ui;
}

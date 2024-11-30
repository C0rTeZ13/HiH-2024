#include "RecognizeObjects.h"
#include "ui_RecognizeObjects.h"

CRecognizeObjects::CRecognizeObjects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRecognizeObjects)
{
    ui->setupUi(this);
}

CRecognizeObjects::~CRecognizeObjects()
{
    delete ui;
}

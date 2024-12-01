#include "ImageScene.h"

#include <QPainter>
#include <QLayout>
#include <QLabel>

CImageScene::CImageScene(QWidget *parent)
    : QWidget{parent}
{
    this->setLayout(new QVBoxLayout());

    m_scceneLabel = new QLabel(this);
    QPixmap pixmap = QPixmap(":/resources/no_Image.jpg");

    if(pixmap.isNull())return;
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding);

    m_scceneLabel->setPixmap(pixmap);
    this->layout()->addWidget(m_scceneLabel);
}

void CImageScene::setScene(const QImage &img)
{
    m_scene = img;

    QPixmap pixmap = QPixmap::fromImage(img);

    if(pixmap.isNull())return;
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding);

    m_scceneLabel->setPixmap(pixmap);
}

#include "ImageScene.h"

#include <QPainter>
#include <QLayout>
#include <QLabel>

CImageScene::CImageScene(QWidget *parent)
    : QWidget{parent}
{
    this->setLayout(new QVBoxLayout());

    m_scceneLabel = new QLabel(this);
    QPixmap pixmap = QPixmap(":/resources/no_Image.jpg"); //sticker.gif

    if(pixmap.isNull())return;
    pixmap = pixmap.scaled(parent->size(), Qt::KeepAspectRatioByExpanding);


    m_scceneLabel->setScaledContents(true);
    m_scceneLabel->setPixmap(pixmap);
    this->layout()->addWidget(m_scceneLabel);
}

void CImageScene::setScene(const QImage &img)
{
    QImage scene(":/resources/no_Image.jpg");

    if (!img.isNull())
    {
        scene = img;
    }

    pixmap = QPixmap::fromImage(scene);

    if (pixmap.isNull())
    {
        return;
    }

    //this->setMaximumSize(scene.size());
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);

    m_scceneLabel->setPixmap(pixmap);
}

void CImageScene::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

#include "ImageScene.h"

CImageScene::CImageScene(QWidget *parent)
    : QWidget{parent}
{

}

void CImageScene::setScene(QImage *img)
{
    scene = img;
}

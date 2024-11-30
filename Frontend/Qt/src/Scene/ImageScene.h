#ifndef CIMAGESCENE_H
#define CIMAGESCENE_H

#include <QWidget>
#include <QImage>

class CImageScene : public QWidget
{
    Q_OBJECT
public:
    explicit CImageScene(QWidget *parent = nullptr);

    void setScene(QImage* img);

private:
    QImage* scene;

};

#endif // CIMAGESCENE_H

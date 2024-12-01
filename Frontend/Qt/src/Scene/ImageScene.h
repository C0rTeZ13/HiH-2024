#ifndef CIMAGESCENE_H
#define CIMAGESCENE_H

#include <QWidget>
#include <QImage>

#include <QLabel>

class CImageScene : public QWidget
{
    Q_OBJECT
public:
    explicit CImageScene(QWidget *parent = nullptr);

    void setScene(const QImage& img);

private:
    QImage m_scene;
    QLabel* m_scceneLabel;

};

#endif // CIMAGESCENE_H

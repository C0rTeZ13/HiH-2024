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

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

private:
    QLabel* m_scceneLabel;

    QPixmap pixmap;

};

#endif // CIMAGESCENE_H

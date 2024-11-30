#ifndef RECOGNIZEOBJECTS_H
#define RECOGNIZEOBJECTS_H

#include <QWidget>

namespace Ui {
class CRecognizeObjects;
}

class CRecognizeObjects : public QWidget
{
    Q_OBJECT

public:
    explicit CRecognizeObjects(QWidget *parent = nullptr);
    ~CRecognizeObjects();

private:
    Ui::CRecognizeObjects *ui;
};

#endif // RECOGNIZEOBJECTS_H

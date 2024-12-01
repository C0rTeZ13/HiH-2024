#ifndef RECOGNIZEOBJECTS_H
#define RECOGNIZEOBJECTS_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QApplication>
#include <QTreeView>
#include <QStandardItemModel>

namespace Ui {
class CRecognizeObjects;
}

class CRecognizeObjects : public QWidget
{
    Q_OBJECT

public:
    explicit CRecognizeObjects(QWidget *parent = nullptr);
    ~CRecognizeObjects();

    void showRecognizeObj(QMap<QString, QVector<QString>> recObjs);

public slots:
    void hideRecognizeObj();

private:
    Ui::CRecognizeObjects *ui;
};

#endif // RECOGNIZEOBJECTS_H

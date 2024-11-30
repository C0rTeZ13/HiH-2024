#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>

namespace Ui {
class CParametrs;
}

class CParametrs : public QWidget
{
    Q_OBJECT

public:
    explicit CParametrs(QWidget *parent = nullptr);
    ~CParametrs();

private:
    Ui::CParametrs *ui;
};

#endif // PARAMETRS_H

#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>
#include <QString>
#include <Qimage>

struct StructSize
{
    int m_frontDoor = 0;
    int m_bonnet = 0;
    int m_trunkLid = 0;
};

namespace Ui {
class CParametrs;
}

class CParametrs : public QWidget
{
    Q_OBJECT

public:
    explicit CParametrs(QWidget *parent = nullptr);
    ~CParametrs();
    QString getImage();
    StructSize* getStandartSize();
    int getTorchWidth();
    int getTorchTakeOff();
    int getCostPerLiter();
    int getPaintMmPerSquareMeter();

private slots:
    void on_text_imageFile_textEdited(const QString &arg1);
    void on_edit_frontDoor_textEdited(const QString &arg1);
    void on_edit_bonnet_textEdited(const QString &arg1);
    void on_edit_trunkLink_textEdited(const QString &arg1);
    void on_edit_tourchWidth_textEdited(const QString &arg1);
    void on_edit_tourchTakeOff_textEdited(const QString &arg1);
    void on_edit_costPerLiter_textEdited(const QString &arg1);
    void on_edit_name_paintMmPerSquareMeter_textEdited(const QString &arg1);

    void on_icon_imageFile_clicked();

private:
    //Params
    QString m_fileName;
    StructSize m_standartSize;
    int m_torchWidth;
    int m_torchTakeOff;
    int m_costPerLiter;
    int m_paintMmPerSquareMeter;

    //
    Ui::CParametrs *ui;
};

#endif // PARAMETRS_H

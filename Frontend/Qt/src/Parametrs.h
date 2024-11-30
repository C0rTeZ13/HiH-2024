#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>
#include <QString>
#include <QImage>
#include <QMap>

struct StructParams
{
    int m_standardSizeMillimeters = 0;
    QString standardDetail = "";
    int m_torchWidthMillimeters = 0;
    int m_torchTakeoffMillimeters = 0;
    int m_coastPerLiter = 0;
    int m_paintMillilitersPerSquareMeter = 0;
};

enum EDetail
{
    FrontDoor,
    Bonnet,
    TrunkLid
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
    StructParams* getParams();

signals:
    void sig_imageChanged(QString filepath);

private slots:
    void on_text_imageFile_textEdited(const QString &arg1);
    void on_icon_imageFile_clicked();
    void on_edit_standardSizeMillimeters_textEdited(const QString &arg1);
    void on_edit_torchWidthMillimeters_textEdited(const QString &arg1);
    void on_edit_tourchTakeOff_textEdited(const QString &arg1);
    void on_edit_costPerLiter_textEdited(const QString &arg1);
    void on_edit_name_paintMmPerSquareMeter_textEdited(const QString &arg1);

    void on_cmb_standardDetail_currentIndexChanged(int index);

private:
    //Params
    QString m_fileName;
    StructParams m_params;

    //
    QMap<int, QString> m_cmbMap;
    Ui::CParametrs *ui;
};

#endif // PARAMETRS_H

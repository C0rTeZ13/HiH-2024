#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

    void setAuthorize(QString login);

private slots:
    void on_btn_calc_clicked();

    void setScene(QString filepath);

    void on_btn_save_clicked();

    void on_btn_load_clicked();

private:
    Ui::CMainWindow *ui;
};
#endif // CMAINWINDOW_H

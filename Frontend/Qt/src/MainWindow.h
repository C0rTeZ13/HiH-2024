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

private:
    Ui::CMainWindow *ui;
};
#endif // CMAINWINDOW_H

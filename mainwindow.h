#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BCcalc_clicked();

    void on_BLcalc_clicked();

    void on_BCclear_clicked();

    void on_BLclear_clicked();

    void on_BBcalc_clicked();

private:
    float val_t;

    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H

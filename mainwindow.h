#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


#include <history.h>
#include <currency.h>

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

    void on_BMcalc_clicked();

    void on_BBclear_clicked();

    void on_BMclear_clicked();

    void on_BHcalc_clicked();

    void on_BHclear_clicked();

    void on_BTcalc_clicked();

    void on_BTclear_clicked();

    void on_cBCoil_activated(const QString &arg1);

    void on_action_h_triggered();

    void on_action_val_triggered();

private:
    float val_t;
    Ui::MainWindow *ui;
    History *sWindow;
    Currency *vWindow;

};
#endif // MAINWINDOW_H

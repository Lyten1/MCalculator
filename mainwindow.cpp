#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vehicle.h>
#include <car.h>
#include <lorry.h>
#include <bus.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BCcalc_clicked()
{
//    float cina;
//    QString irt;
//    Car Obj;
//    cina = ui->ECprice->text().toFloat();
//    cina += 1;

//    Obj.getData(cina);

//    //    irt = QString::number(cina);
//    //ui->ECvolume->setText(irt);

//   ui->ECmuto->setText(QString::number(Obj.muto));   // вивід мито через з сласу легковихІ



}
void MainWindow::on_BCclear_clicked()
{
    ui->ECprice->clear();
    ui->ECvolume->clear();
    ui->ECyear->clear();
    ui->ECmuto->clear();
    ui->ECacc->clear();
    ui->ECpdv->clear();
    ui->ECresult->clear();
    ui->ECgrn->clear();
    ui->cBCeur_1->setChecked(0);
}


void MainWindow::on_BLcalc_clicked()
{

    Lorry Obj;


            // -------------- Валюти ---------------------
    //QString val_tex = ui->cBLval->currentText();
    //if (val_tex == "eur") val_t = eur;  // перевірка вибраної валюти
    //else if (val_tex == "usd") val_t = usd;  // перевірка вибраної валюти
    //else if (val_tex == "zlt") val_t = zlt;  // перевірка вибраної валюти
    //else if (val_tex == "chf") val_t = chf;  // перевірка вибраної валюти
    val_t = 31;

    if (ui->cBLtyp->currentText() == "Нові") ui->ELyear->setText(0);

    Obj.getData(ui->ELprice->text().toFloat(),val_t,ui->ELvolume->text().toInt(),ui->cBLoil->currentText(),ui->ELweight->text().toInt(),ui->ELyear->text().toInt(),ui->cBLeur_1->isChecked());
    Obj.Calculate();
    ui->ELmuto->setText(QString::number(Obj.muto));
    ui->ELacc->setText(QString::number(Obj.acc));
    ui->ELpdv->setText(QString::number(Obj.pdv));
    ui->ELresult->setText(QString::number(Obj.result_clear));
    ui->ELgrn->setText(QString::number(Obj.res_grn));


}

void MainWindow::on_BLclear_clicked()
{
    ui->ELprice->clear();
    ui->ELvolume->clear();
    ui->ELweight->clear();
    ui->ELyear->clear();
    ui->ELmuto->clear();
    ui->ELacc->clear();
    ui->ELpdv->clear();
    ui->ELresult->clear();
    ui->ELgrn->clear();
    ui->cBLeur_1->setChecked(0);
}

void MainWindow::on_BBcalc_clicked()
{

    Bus Obj;
            // -------------- Валюти ---------------------
    //QString val_tex = ui->cBLval->currentText();
    //if (val_tex == "eur") val_t = eur;  // перевірка вибраної валюти
    //else if (val_tex == "usd") val_t = usd;  // перевірка вибраної валюти
    //else if (val_tex == "zlt") val_t = zlt;  // перевірка вибраної валюти
    //else if (val_tex == "chf") val_t = chf;  // перевірка вибраної валюти
    val_t = 31;

    if (ui->cBLtyp->currentText() == "Нові") ui->ELyear->setText(0);

      Obj.getData(ui->ELprice->text().toFloat(),val_t,ui->ELvolume->text().toInt(),ui->cBLoil->currentText(),ui->ELyear->text().toInt(),ui->cBLeur_1->isChecked());
      Obj.Calculate();
      ui->ELmuto->setText(QString::number(Obj.st_muto));
//    ui->ELacc->setText(QString::number(Obj.acc));
//    ui->ELpdv->setText(QString::number(Obj.pdv));
//    ui->ELresult->setText(QString::number(Obj.result_clear));
//    ui->ELgrn->setText(QString::number(Obj.res_grn));


}

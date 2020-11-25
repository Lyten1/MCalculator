#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vehicle.h>
#include <car.h>
#include <lorry.h>
#include <bus.h>
#include <motocycle.h>
#include <hauler.h>
#include <trailer.h>

#include <history.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cBCoil_2->setHidden(true);
    ui->LCel->setHidden(true);

    db = new DataBase();
    db->connectToDataBase();

    sWindow = new History();
    vWindow = new Currency();

    val_t = 33.4353;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BCcalc_clicked()
{
    Car Obj;



    Obj.getData(ui->ECprice->text().toFloat(), val_t, ui->ECvolume->text().toFloat(), ui->cBCoil->currentText(), ui->cBCoil_2->currentText(), ui->ECyear->text().toInt(), ui->ECyear_2->text().toInt(), ui->cBCeur_1->isChecked());
    Obj.Calculate();
    ui->Emuto->setText(QString::number(Obj.muto));
    ui->Eacc->setText(QString::number(Obj.acc));
    ui->Epdv->setText(QString::number(Obj.pdv));
    ui->Eresult->setText(QString::number(Obj.result_clear));
    ui->Egrn->setText(QString::number(Obj.res_grn));


    // --------- History ----------

    QVariantList data;
            data.append("Легковий");
            data.append(ui->ECprice->text());
            data.append(ui->ECvolume->text());
            data.append("None");
            data.append(ui->ECyear->text());
            data.append(ui->cBCoil->currentText());
            data.append(ui->Eresult->text());
            data.append(ui->Eeur->text());

            // Вставляем данные в БД
            db->inserIntoTable(data);


}



void MainWindow::on_BCclear_clicked()
{
    ui->ECprice->clear();
    ui->ECvolume->clear();
    ui->ECyear->clear();
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


    if (ui->cBLtyp->currentText() == "Нові") ui->ELyear->setText(0);

    Obj.getData(ui->ELprice->text().toFloat(),val_t,ui->ELvolume->text().toFloat(),ui->cBLoil->currentText(),ui->ELweight->text().toFloat(),ui->ELyear->text().toInt(),ui->cBLeur_1->isChecked());
    Obj.Calculate();
    ui->Emuto->setText(QString::number(Obj.muto));
    ui->Eacc->setText(QString::number(Obj.acc));
    ui->Epdv->setText(QString::number(Obj.pdv));
    ui->Eresult->setText(QString::number(Obj.result_clear));
    ui->Egrn->setText(QString::number(Obj.res_grn));


    // --------- History ----------

    QVariantList data;
            data.append("Вантажний");
            data.append(ui->ELprice->text());
            data.append(ui->ELvolume->text());
            data.append(ui->ELweight->text());
            data.append(ui->ELyear->text());
            data.append(ui->cBLoil->currentText());
            data.append(ui->Eresult->text());
            data.append(ui->Eeur->text());

            // Вставляем данные в БД
            db->inserIntoTable(data);

}

void MainWindow::on_BLclear_clicked()
{
    ui->ELprice->clear();
    ui->ELvolume->clear();
    ui->ELweight->clear();
    ui->ELyear->clear();
    ui->cBLeur_1->setChecked(0);
}

void MainWindow::on_BBcalc_clicked()
{

    Bus Obj;



      if (ui->cBBtyp->currentText() == "Нові") ui->EByear->setText(0);

      Obj.getData(ui->EBprice->text().toFloat(),val_t,ui->EBvolume->text().toFloat(),ui->cBBoil->currentText(),ui->EByear->text().toInt(),ui->cBBeur_1->isChecked());
      Obj.Calculate();
      ui->Emuto->setText(QString::number(Obj.muto));
      ui->Eacc->setText(QString::number(Obj.acc));
      ui->Epdv->setText(QString::number(Obj.pdv));
      ui->Eresult->setText(QString::number(Obj.result_clear));
      ui->Egrn->setText(QString::number(Obj.res_grn));


      // --------- History ----------

      QVariantList data;
              data.append("Автобус");
              data.append(ui->EBprice->text());
              data.append(ui->EBvolume->text());
              data.append("None");
              data.append(ui->EByear->text());
              data.append(ui->cBBoil->currentText());
              data.append(ui->Eresult->text());
              data.append(ui->Eeur->text());

              // Вставляем данные в БД
              db->inserIntoTable(data);

}

void MainWindow::on_BBclear_clicked()
{
    ui->EBprice->clear();
    ui->EBvolume->clear();
    ui->EByear->clear();
    ui->cBLeur_1->setChecked(0);
}

void MainWindow::on_BMcalc_clicked()
{
    Motocycle Obj;



      if (ui->cBBtyp->currentText() == "Нові") ui->EByear->setText(0);

      Obj.getData(ui->EMprice->text().toFloat(),val_t,ui->EMvolume->text().toFloat(),ui->cBMoil->currentText(),ui->cBMeur_1->isChecked());
      Obj.Calculate();
      ui->Emuto->setText(QString::number(Obj.muto));
      ui->Eacc->setText(QString::number(Obj.acc));
      ui->Epdv->setText(QString::number(Obj.pdv));
      ui->Eresult->setText(QString::number(Obj.result_clear));
      ui->Egrn->setText(QString::number(Obj.res_grn));


      // --------- History ----------

      QVariantList data;
              data.append("Мотоцикл");
              data.append(ui->EMprice->text());
              data.append(ui->EMvolume->text());
              data.append("None");
              data.append("None");
              data.append(ui->cBMoil->currentText());
              data.append(ui->Eresult->text());
              data.append(ui->Eeur->text());

              // Вставляем данные в БД
              db->inserIntoTable(data);
}

void MainWindow::on_BMclear_clicked()
{
    ui->EMprice->clear();
    ui->EMvolume->clear();
    ui->cBMeur_1->setChecked(0);
}

void MainWindow::on_BHcalc_clicked()
{
    Hauler Obj;



      if (ui->cBBtyp->currentText() == "Нові") ui->EByear->setText(0);

      Obj.getData(ui->EHprice->text().toFloat(),val_t,ui->cBHuse->currentText(),ui->cBHeur_1->isChecked());
      Obj.Calculate();
      ui->Emuto->setText(QString::number(Obj.muto));
      ui->Eacc->setText(QString::number(Obj.acc));
      ui->Epdv->setText(QString::number(Obj.pdv));
      ui->Eresult->setText(QString::number(Obj.result_clear));
      ui->Egrn->setText(QString::number(Obj.res_grn));


      // --------- History ----------

      QVariantList data;
              data.append("Тягач");
              data.append(ui->EHprice->text());
              data.append("None");
              data.append("None");
              data.append("None");
              data.append("None");
              data.append(ui->Eresult->text());
              data.append(ui->Eeur->text());

              // Вставляем данные в БД
              db->inserIntoTable(data);
}

void MainWindow::on_BHclear_clicked()
{
    ui->EHprice->clear();
    ui->cBHeur_1->setChecked(0);
}

void MainWindow::on_BTcalc_clicked()
{
    Trailer Obj;



      if (ui->cBBtyp->currentText() == "Нові") ui->EByear->setText(0);

      Obj.getData(ui->ETprice->text().toFloat(),val_t,ui->ETweight->text().toFloat(),ui->cBTeur_1->isChecked(),ui->cBTtyp->currentText());
      Obj.Calculate();
      ui->Emuto->setText(QString::number(Obj.muto));
      ui->Eacc->setText(QString::number(Obj.acc));
      ui->Epdv->setText(QString::number(Obj.pdv));
      ui->Eresult->setText(QString::number(Obj.result_clear));
      ui->Egrn->setText(QString::number(Obj.res_grn));

      // --------- History ----------

      QVariantList data;
              data.append("Причіп");
              data.append(ui->ETprice->text());
              data.append("None");
              data.append(ui->ETweight->text());
              data.append("None");
              data.append("None");
              data.append(ui->Eresult->text());
              data.append(ui->Eeur->text());

              // Вставляем данные в БД
              db->inserIntoTable(data);
}

void MainWindow::on_BTclear_clicked()
{
    ui->ETprice->clear();
    ui->ETweight->clear();
    ui->cBTeur_1->setChecked(0);
}

void MainWindow::on_cBCoil_activated(const QString &arg1)
{
    if (arg1 == "Гібрид") ui->cBCoil_2->setHidden(false);
    else ui->cBCoil_2->setHidden(true);

    if (arg1 == "Електричний") ui->LCel->setHidden(false);
    else ui->LCel->setHidden(true);
}



void MainWindow::on_action_h_triggered()
{
    sWindow->Update();
    sWindow->show();
}

void MainWindow::on_action_val_triggered()
{
    vWindow->show();
}

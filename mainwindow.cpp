#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    cWindow = new convertor();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BCcalc_clicked()
{
    Car Obj;
    Obj.setData(ui->ECprice->text().toFloat(), ui->cBCval->currentText(), ui->ECvolume->text().toFloat(), ui->cBCoil->currentText(), ui->cBCoil_2->currentText(), ui->ECyear->text().toInt(), ui->ECyear_2->text().toInt(), ui->cBCeur_1->isChecked());
    Obj.Calculate();

    this->Output_data(&Obj);


    // --------- History ----------

    QVariantList data;
    data.append("Легковий");
    data.append(ui->ECprice->text());
    data.append(ui->ECvolume->text());
    data.append(ui->ECyear->text());
    data.append(ui->cBCoil->currentText());
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);


}



void MainWindow::on_BCclear_clicked()
{
    ui->ECprice->clear();
    ui->ECvolume->clear();
    ui->ECyear->clear();
    ui->ECyear_2->clear();
    ui->cBCeur_1->setChecked(0);
}


void MainWindow::on_BLcalc_clicked()
{

    Lorry Obj;


    if (ui->cBLtyp->currentText() == "Нові") ui->ELyear->setText(0); //зробити для всіх

    Obj.setData(ui->ELprice->text().toFloat(), ui->cBLval->currentText(),ui->ELvolume->text().toFloat(),ui->cBLoil->currentText(),ui->ELweight->text().toFloat(),ui->ELyear->text().toInt(),ui->cBLeur_1->isChecked());
    Obj.Calculate();

    this->Output_data(&Obj);




    // --------- History ----------

    QVariantList data;
    data.append("Вантажний");
    data.append(ui->ELprice->text());
    data.append(ui->ELvolume->text());
    data.append(ui->ELyear->text());
    data.append(ui->cBLoil->currentText());
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);

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

    Obj.setData(ui->EBprice->text().toFloat(), ui->cBBval->currentText(),ui->EBvolume->text().toFloat(),ui->cBBoil->currentText(),ui->EByear->text().toInt(),ui->cBBeur_1->isChecked());
    Obj.Calculate();
    this->Output_data(&Obj);


    // --------- History ----------

    QVariantList data;
    data.append("Автобус");
    data.append(ui->EBprice->text());
    data.append(ui->EBvolume->text());
    data.append(ui->EByear->text());
    data.append(ui->cBBoil->currentText());
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);

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

    Obj.setData(ui->EMprice->text().toFloat(), ui->cBMval->currentText(),ui->EMvolume->text().toFloat(),ui->cBMoil->currentText(),ui->cBMeur_1->isChecked());
    Obj.Calculate();
    this->Output_data(&Obj);



    // --------- History ----------

    QVariantList data;
    data.append("Мотоцикл");
    data.append(ui->EMprice->text());
    data.append(ui->EMvolume->text());
    data.append("None");
    data.append(ui->cBMoil->currentText());
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);
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

    Obj.setData(ui->EHprice->text().toFloat(), ui->cBHval->currentText(),ui->cBHuse->currentText(),ui->cBHeur_1->isChecked());
    Obj.Calculate();
    this->Output_data(&Obj);



    // --------- History ----------

    QVariantList data;
    data.append("Тягач");
    data.append(ui->EHprice->text());
    data.append("None");
    data.append("None");
    data.append("None");
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);
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

    Obj.setData(ui->ETprice->text().toFloat(), ui->cBTval->currentText(),ui->ETweight->text().toFloat(),ui->cBTeur_1->isChecked(),ui->cBTtyp->currentText());
    Obj.Calculate();
    this->Output_data(&Obj);


    // --------- History ----------

    QVariantList data;
    data.append("Причіп");
    data.append(ui->ETprice->text());
    data.append("None");
    data.append("None");
    data.append("None");
    data.append(ui->Eresult->text());
    data.append(ui->Eeur->text());

    // Вставляем данные в БД
    db->inserIntoTable_H(data);
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
    vWindow->Update();
    vWindow->show();
}

void MainWindow::Output_data(Vehicle *Obj)
{
    ui->Emuto->setText(QString::number(Obj->getMuto()));
    ui->Eacc->setText(QString::number(Obj->getAcc()));
    ui->Epdv->setText(QString::number(Obj->getpdv()));
    ui->Eresult->setText(QString::number(Obj->getResult()));
    ui->Eeur->setText(QString::number(Obj->getResult_Eur()));
    ui->Eusd->setText(QString::number(Obj->getResult_Usd()));
}

void MainWindow::on_action_convert_triggered()
{
    cWindow->show();
}

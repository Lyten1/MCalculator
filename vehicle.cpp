#include "vehicle.h"
#include <QDate>

float Vehicle::val_eur = 0;
float Vehicle::val_usd = 0;
float Vehicle::val_pln = 0;
float Vehicle::val_chf = 0;


Vehicle::Vehicle()
{
    cina = NULL;
    cina_g = NULL;
    main_val = NULL;
    st_muto = NULL;
    st_acc = NULL;
    muto = NULL;
    acc = NULL;
    pdv = NULL;
    result_clear = NULL;
    res_usd = NULL;
    res_eur = NULL;

}

void Vehicle::setData(float _cina, QString _val, float _year)
{
    cina = _cina;
    val = _val;
    year = _year;
    checkVal();
    cina_g = cina * main_val; // замість валюти поточна вибрана
}

void Vehicle::setAge(){
    QDate date = QDate::currentDate();
    year = date.year() - year;
}

void Vehicle::setCurs(float temp_eur, float temp_usd, float temp_pln, float temp_chf)
{
    Vehicle::val_eur = temp_eur;
    Vehicle::val_usd = temp_usd;
    Vehicle::val_pln = temp_pln;
    Vehicle::val_chf = temp_chf;
}

void Vehicle::checkVal()
{
    if (val == "eur") main_val = Vehicle::val_eur;
    else if (val == "usd") main_val = Vehicle::val_usd;
    else if (val == "pln") main_val = Vehicle::val_pln;
    else if (val == "chf") main_val = Vehicle::val_chf;
}

float Vehicle::getMuto()
{
    return muto;
}

float Vehicle::getAcc()
{
    return acc;
}

float Vehicle::getpdv()
{
    return pdv;
}

float Vehicle::getResult()
{
    return result_clear;
}

float Vehicle::getResult_Eur()
{
    return res_eur;
}

float Vehicle::getResult_Usd()
{
    return res_usd;
}







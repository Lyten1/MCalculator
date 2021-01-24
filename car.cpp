#include "car.h"


Car::Car()
{

}

void Car::setData(float _cina, QString _val, float _volume, QString _typ_oil, QString _typ_oil_elec, float _date_first_reg, float _dateOfCreate, bool _eur_1)
{
    Vehicle::setData(_cina,_val,NULL);
    volume = _volume;
    typ_oil = _typ_oil;
    date_first_reg = _date_first_reg;
    dateOfCreate = _dateOfCreate;
    eur_1 = _eur_1;
    typ_oil_elec = _typ_oil_elec;
    Car::setAge();
}

void Car::setAge()
{
    QDate date = QDate::currentDate();
    date_first_reg = date.year() - date_first_reg;


    date = QDate::currentDate();
    koef = date.year() - dateOfCreate - 1;
    if (koef < 1) koef = 1;
    if (koef > 15) koef = 15;

}
void Car::Calculate()
{

    // ------------- Ставка мито ---------------
    if (typ_oil == "Бензиновий") {
        st_muto = 0.1;
        if (eur_1 == 1){
            if (volume < 1000){

                if (date_first_reg == 0) {
                    st_muto = 0.038;
                }
                else st_muto = 0.055;
            }
            else if (volume < 1500){
                st_muto = 0.055;
            }
            else if (volume <= 3000){
                if (volume <= 2200) st_muto = 0.055;
                else st_muto = 0.038;
            }
            else{
                if (date_first_reg == 0) st_muto = 0.034;
                else st_muto = 0.055;
            }
        }
        if (volume > 3000) st_acc = 100;
        else st_acc = 50;
    }
    else if (typ_oil == "Дизельний"){
        st_muto = 0.1;
        if(eur_1 == 1){
            if (volume < 2500) st_muto = 0.055;
            else {
                if (date_first_reg == 0) st_muto = 0.038;
                else st_muto = 0.055;
            }
        }
        if (volume > 3500) st_acc = 150;
        else st_acc = 75;
    }
    else if (typ_oil == "Електричний"){
        st_muto = 0;
        st_acc = 1;
    }
    else if (typ_oil == "Інший"){
        if(eur_1 == 1){
            st_muto = 0.038;
        }
        else st_muto = 1;
    }
    else if (typ_oil == "Гібрид" && typ_oil_elec == "Бен/Елек гібрид"){
        st_muto = 0.1;
        if (eur_1 == 1){
            if (date_first_reg == 0){
                if(volume > 3000){
                    st_muto = 0.034;
                    st_acc = 100;
                }
                else{
                    st_muto = 0.038;
                    st_acc = 50;
                }
            }
            else {
                st_muto = 0.055;
                if (volume <= 3000) {
                    st_acc = 50;
                }
                else st_acc = 100;
            }
        }
    }
    else if (typ_oil == "Гібрид" && typ_oil_elec == "Диз/Елек гібрид"){
        st_muto = 0.1;
        if (eur_1 == 1){
            st_muto = 0.055;
            if (volume <= 3500){
                st_acc = 75;
            }
            else st_acc = 100;
        }
    }
    else if (typ_oil == "Гібрид" && typ_oil_elec == "Елек з д.в.з. для генератора"){
        st_muto = 0.1;
        if (eur_1 == 1){
            st_muto = 0.038;
            st_acc = 1;
        }
    }


    // --------------- Розрахунки ---------------

    muto = cina_g * st_muto;

    if (typ_oil == "Електричний"){
        acc = volume * st_acc * val_eur;
    }
    else if ((typ_oil == "Гібрид" && typ_oil_elec == "Елек з д.в.з. для генератора") || typ_oil == "Інший"){
        acc = 100 * val_eur;
    }
    else acc = volume/1000 * st_acc * koef * val_eur;

    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_eur = result_clear / val_eur;
    res_usd = result_clear / val_usd;
}

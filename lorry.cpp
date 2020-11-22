#include "lorry.h"


Lorry::Lorry()
{

}

void Lorry::getData(float _cina, float _val, float _volume, QString _typ_oil, float _weight, int _year, bool _eur_1)
{
    Vehicle::getData(_cina,_val,_year);
    volume = _volume;
    typ_oil = _typ_oil;
    weight = _weight;
    eur_1 = _eur_1;

}

void Lorry::Calculate()
{
     Vehicle::getYear();

    // ------------- Ставка мито ---------------
    if (typ_oil == "Бензиновий") {
        if (weight >= 5000){
            if(eur_1 == 1) st_muto = 0.038;
            else st_muto = 0.1;
        }
        else if (weight > 0){
            if (eur_1 == 1) st_muto = 0.019;
            else st_muto = 0.05;
        }
    }
    else {
        if(eur_1 == 1) st_muto = 0.038;
        else st_muto = 0.1;
    }

    // ------------- Ставка акцизу --------------

    if (typ_oil == "Бензиновий" || typ_oil == "Дизельний"){
        if (weight <= 5000){
            if(year == 0) st_acc = 0.01;
            else if (year < 5) st_acc = 0.02;
            else if (year < 8) st_acc = 0.02 * 40;
            else if (year > 8) st_acc = 0.02 * 50;
        }
        else if (weight > 5000){
            if (weight > 20000 && typ_oil == "Дизельне"){
                if(year == 0) st_acc = 0.016;
                else if (year < 5) st_acc = 0.033;
                else if (year < 8) st_acc = 0.033 * 40;
                else if (year > 8) st_acc = 0.033 * 50;
            }
            if(year == 0) st_acc = 0.013;
            else if (year < 5) st_acc = 0.026;
            else if (year < 8) st_acc = 0.026 * 40;
            else if (year > 8) st_acc = 0.026 * 50;
        }
    }
    else st_acc = 0;




    // --------------- Розрахунки ---------------
    cina_g = cina * val;
    muto = cina * st_muto;
    acc = volume * st_acc * val;
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_grn = result_clear + cina_g;
}

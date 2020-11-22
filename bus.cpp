#include "bus.h"


Bus::Bus()
{

}

void Bus::getData(float _cina, float _val, float _volume, QString _typ_oil, int _year, bool _eur_1)
{
    Vehicle::getData(_cina,_val,_year);
    volume = _volume;
    typ_oil = _typ_oil;
    eur_1 = _eur_1;
}

void Bus::Calculate()
{
    Vehicle::getYear();

    // ------------- Ставка мито ---------------
    if (typ_oil == "Електро"){
        if (eur_1 == 1)  st_muto = 0.0056;
        else st_muto = 0.15;
    }
    else if (typ_oil == "Інші"){
        if (eur_1 == 1)  st_muto = 0.0038;
        else st_muto = 0.1;
    }
    else {
        if (volume <= 5000){
                    if (eur_1 == 1){
                        st_muto = 0.0038;
                    }
                    else st_muto = 0.1;
                }
        else if (volume > 5000){
                    if (eur_1 == 1){
                        st_muto = 0.0075;
                     }
                    else st_muto = 0.2;
                }
    }

    // ------------- Ставка акцизу -------------
    if (typ_oil == "Дизель"){
        if(year == 0) st_acc = 0.003;
        if(volume <= 2500){
            if(year > 8) st_acc = 0.35;
            else if (year <= 8) st_acc = 0.007;
        }
        else if(volume > 2500){
            if (volume <= 5000){
                if (year <= 8) st_acc = 0.003;
                else st_acc = 0.15;
            }
            else if (volume > 5000){
                if (year <= 8) st_acc = 0.007;
                else st_acc = 0.35;
            }
        }
    }
    else if (typ_oil == "Дизель/електро"){
        if (volume > 2500){
            if(volume <= 5000) st_acc = 0.003;
            else if (volume > 5000) st_acc = 0.007;
        }
        else if(volume < 2500){
            if (year == 0) st_acc = 0.003;
            else if (year <= 8) st_acc = 0.007;
            else st_acc = 0.35;
        }
    }
    else if (typ_oil == "Бензин" || typ_oil == "Бензин/електро"){
            if (year == 0) st_acc = 0.003;
            else if (year <= 8) st_acc = 0.007;
            else if (year > 8) st_acc = 0.35;
    }
    else st_acc = 0;



    cina_g = cina * val; // замість валюти поточна вибрана
    muto = cina_g * st_muto;
    acc = volume * st_acc * val; // замість валюти євро
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_grn = result_clear + cina_g;


}

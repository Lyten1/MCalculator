#include "bus.h"


Bus::Bus()
{

}

void Bus::getData(float _cina, float _val, int _volume, QString _typ_oil, int _year, bool _eur_1)
{
    Vehicle::getData(_cina,_val);
    volume = _volume;
    typ_oil = _typ_oil;
    year = _year;
    eur_1 = _eur_1;
}

void Bus::Calculate()
{
    // ------------- Ставка мито ---------------
    if (typ_oil == "Електро"){
        if (eur_1 == 1)  st_muto = 0.056;
        else st_muto = 0.15;
    }
    else if (typ_oil == "Інші"){
        if (eur_1 == 1)  st_muto = 0.038;
        else st_muto = 0.1;
    }
    else {
        if (volume <= 5000){
                    if (eur_1 == 1){
                        st_muto = 0.038;
                    }
                    else st_muto = 0.1;
                }
                else if (volume > 5000){
                    if (eur_1 == 1){
                        st_muto = 0.075;
                     }
                    else st_muto = 0.2;
                }
    }

    // ------------- Ставка акцизу -------------


    muto = cina_g * val * st_muto;


}

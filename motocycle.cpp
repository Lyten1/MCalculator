#include "motocycle.h"

Motocycle::Motocycle()
{

}

void Motocycle::getData(float _cina, float _val, float _volume, QString _typ_oil, bool _eur_1)
{
    Vehicle::getData(_cina,_val,NULL);
    volume = _volume;
    typ_oil = _typ_oil;
    eur_1 = _eur_1;
}

void Motocycle::Calculate()
{
    // ------------- Ставка мито ---------------
    if (eur_1 == 1) st_muto = 0;
    else st_muto = 0.1;

    // ------------- Ставка акцизу -------------
    if (volume <= 500) st_acc = 0.062;
    else if (volume <= 800) st_acc = 0.443;
    else st_acc = 0.447;


    // --------------- Розрахунки ---------------
    cina_g = cina * val;
    muto = cina_g * st_muto;

    if (typ_oil == "Бензиновий") acc = volume * st_acc;
    else acc = 22 * val;

    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_grn = result_clear + cina_g;
}



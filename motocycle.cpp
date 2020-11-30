#include "motocycle.h"

Motocycle::Motocycle()
{

}

void Motocycle::setData(float _cina, QString _val, float _volume, QString _typ_oil, bool _eur_1)
{
    Vehicle::setData(_cina,_val,NULL);
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

    muto = cina_g * st_muto;

    if (typ_oil == "Бензиновий") acc = volume * st_acc;
    else acc = 22 * val_eur;

    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_eur = result_clear / val_eur;
    res_usd = result_clear / val_usd;
}



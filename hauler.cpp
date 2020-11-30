#include "hauler.h"

Hauler::Hauler()
{

}

void Hauler::setData(float _cina, QString _val, QString _use, bool _eur_1)
{
    Vehicle::setData(_cina,_val,NULL);
    eur_1 = _eur_1;
    use = _use;
}

void Hauler::Calculate()
{

    // ------------- Ставка мито ---------------
    if (use == "Новий") st_muto = 0;
    else {
        if (eur_1 == 1) st_muto = 0;
        else st_muto = 0.1;
    }
    // --------------- Розрахунки ---------------

    muto = cina_g * st_muto;
    acc = 0;
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_eur = result_clear / val_eur;
    res_usd = result_clear / val_usd;

}

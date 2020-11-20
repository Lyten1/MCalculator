#include "hauler.h"

Hauler::Hauler()
{

}

void Hauler::getData(float _cina, float _val, QString _use, bool _eur_1)
{
    Vehicle::getData(_cina,_val,NULL);
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

    cina_g = cina * val;
    muto = cina_g * st_muto;
    acc = 0;
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_grn = result_clear + cina_g;

}

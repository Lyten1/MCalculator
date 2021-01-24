#include "trailer.h"

Trailer::Trailer()
{

}

void Trailer::setData(float _cina, QString _val, float _weight, bool _eur_1, QString _typ)
{
    Vehicle::setData(_cina,_val,NULL);
    weight = _weight;
    eur_1 = _eur_1;
    typ = _typ;
}

void Trailer::Calculate()
{
    // ------------- Ставка мито --------------

    if (eur_1 == 1) st_muto = 0;
    else st_muto  = 0.1;


    // --------------- Розрахунки ---------------

    muto = cina_g * st_muto;
    if (typ == "Житловики" && weight > 1600){
        acc = 109 * val_eur;
    }
    else acc = 0;
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_eur = result_clear / val_eur;
    res_usd = result_clear / val_usd;
}

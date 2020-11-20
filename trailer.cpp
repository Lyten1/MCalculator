#include "trailer.h"

Trailer::Trailer()
{

}

void Trailer::getData(float _cina, float _val, float _weight, bool _eur_1, QString _typ)
{
    Vehicle::getData(_cina,_val,NULL);
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

    cina_g = cina * val;
    muto = cina_g * st_muto;
    if (typ == "Житловики" && weight > 1600){
        acc = 109 * val;
    }
    else acc = 0;
    pdv = (cina_g + muto + acc) * 0.2;
    result_clear = muto + acc + pdv;
    res_grn = result_clear + cina_g;
}

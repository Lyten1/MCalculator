#ifndef LORRY_H
#define LORRY_H
#include <vehicle.h>


class Lorry: public Vehicle
{
protected:
    float volume;
    float weight;
    QString typ_oil;
    bool eur_1;
public:
    Lorry();
    void setData(float _cina, QString _val, float _volume, QString _typ_oil, float _weight, float _year, bool _eur_1);

    void Calculate();
};

#endif // LORRY_H

#ifndef MOTOCYCLE_H
#define MOTOCYCLE_H
#include <vehicle.h>


class Motocycle: public Vehicle
{
    int volume;
    QString typ_oil;
    bool eur_1;
public:
    Motocycle();
    void getData(float _cina, float _val, int _volume, QString _typ_oil, bool _eur_1);
    void Calculate();
};

#endif // MOTOCYCLE_H

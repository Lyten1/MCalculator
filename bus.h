#ifndef BUS_H
#define BUS_H
#include <vehicle.h>


class Bus: public Vehicle
{
protected:

    QString typ_oil;
    bool eur_1;
    float volume;
public:
    Bus();
    void setData(float _cina, QString _val, float _volume, QString _typ_oil, float _year, bool _eur_1);
    void Calculate();
};

#endif // BUS_H

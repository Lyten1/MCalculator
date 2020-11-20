#ifndef CAR_H
#define CAR_H
#include <vehicle.h>


class Car: public Vehicle
{
    int volume, date_first_reg, dateOfCreate, koef;
    float weight;
    QString typ_oil, typ_oil_elec;
    bool eur_1;

public:
    Car();
    void getData(float _cina, float _val, int _volume, QString _typ_oil, QString _typ_oil_elec, int _date_first_reg, int _dateOfCreate, bool _eur_1);
    void getYears();
    void Calculate();

};

#endif // CAR_H

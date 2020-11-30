#ifndef CAR_H
#define CAR_H
#include <vehicle.h>


class Car: public Vehicle
{
protected:
    float weight,  date_first_reg, dateOfCreate, koef;
    QString typ_oil, typ_oil_elec;
    bool eur_1;
    float volume;

public:
    Car();
    void setData(float _cina, QString _val, float _volume, QString _typ_oil, QString _typ_oil_elec, float _date_first_reg, float _dateOfCreate, bool _eur_1);
    void setAge();
    void Calculate();

};

#endif // CAR_H

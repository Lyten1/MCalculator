#ifndef TRAILER_H
#define TRAILER_H
#include <vehicle.h>


class Trailer: public Vehicle
{
    float weight;
    bool eur_1;
    QString typ;
public:
    Trailer();
    void setData(float _cina, QString _val, float _weight, bool _eur_1, QString _typ);
    void Calculate();
};

#endif // TRAILER_H

#ifndef TRAILER_H
#define TRAILER_H
#include <vehicle.h>


class Trailer: public Vehicle
{
    float weight;
    bool eur_1;
   QString use;
public:
    Trailer();
    void getData(float _cina, float _val, float _weight, bool _eur_1, QString _use);
    void Calculate();
};

#endif // TRAILER_H

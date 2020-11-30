#ifndef HAULER_H
#define HAULER_H
#include <vehicle.h>


class Hauler: public Vehicle
{
    bool eur_1;
    QString use;

public:
    Hauler();
    void setData(float _cina, QString _val, QString _use, bool _eur_1);
    void Calculate();

};

#endif // HAULER_H

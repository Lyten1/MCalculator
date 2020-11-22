#ifndef BUS_H
#define BUS_H
#include <vehicle.h>


class Bus: public Vehicle
{
    friend class MainWindow;
protected:

    QString typ_oil;
    bool eur_1;
    float volume;
public:
    Bus();
    void getData(float _cina, float _val, float _volume, QString _typ_oil, int _year, bool _eur_1);
    void Calculate();
};

#endif // BUS_H

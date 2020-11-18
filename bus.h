#ifndef BUS_H
#define BUS_H
#include <vehicle.h>


class Bus: public Vehicle
{
    friend class MainWindow;
protected:
    int volume, year;
    QString typ_oil;
    bool eur_1;
public:
    Bus();
    void getData(float _cina, float _val, int _volume, QString _typ_oil, int _year, bool _eur_1);
    void Calculate();
};

#endif // BUS_H

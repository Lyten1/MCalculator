#ifndef LORRY_H
#define LORRY_H
#include <vehicle.h>

class Lorry: public Vehicle
{
    friend class MainWindow;
protected:
    int volume;
    float weight;
    QString typ_oil;
    bool eur_1;
public:
    Lorry();
    void getData(float _cina, float _val, int _volume, QString _typ_oil, float _weight, int _year, bool _eur_1);
    void Calculate();
};

#endif // LORRY_H

#ifndef VEHICLE_H
#define VEHICLE_H
#include <mainwindow.h>


class Vehicle //базовий клас
{
    friend class MainWindow;
protected:
     float cina, val, st_muto,st_acc, muto, acc, pdv, result_clear, res_grn,res_usd, res_eur, cina_g;
     int year;
public:

    Vehicle();
    void getData(float _cina, float _val, int _year);
    void getYear();
};

#endif // VEHICLE_H

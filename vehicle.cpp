#include "vehicle.h"
#include <QDate>

Vehicle::Vehicle()
{

}

void Vehicle::getData(float _cina, float _val, int _year)
{
    cina = _cina;
    val = _val;
     year = _year;

}

void Vehicle::getYear(){
    QDate date = QDate::currentDate();
    year = date.year() - year;
}





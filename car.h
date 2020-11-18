#ifndef CAR_H
#define CAR_H
#include <vehicle.h>


class Car: public Vehicle
{
private:
    int typ_oil;

public:
    Car();
    //void getData();
};

#endif // CAR_H

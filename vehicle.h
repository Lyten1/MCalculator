#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>




class Vehicle //базовий клас
{
protected:
     float cina, cina_g,  main_val, st_muto,st_acc, muto, acc, pdv, result_clear,res_usd, res_eur, year;

     QString val;
     static float  val_eur, val_usd, val_pln, val_chf;

public:
     friend class convertor;

     Vehicle();
     void setData(float _cina, QString _val, float _year);
     void setAge();
     void setCurs(float temp_eur, float temp_usd, float temp_pln, float temp_chf);
     void checkVal();

    float getMuto();
    float getAcc();
    float getpdv();
    float getResult();
    float getResult_Eur();
    float getResult_Usd();


};

#endif // VEHICLE_H

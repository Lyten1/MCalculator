#ifndef CURRENCY_H
#define CURRENCY_H

#include <QMainWindow>
#include <QFile>
#include <QNetworkAccessManager>
#include <database.h>
#include <QSqlQueryModel>
#include <vehicle.h>




namespace Ui {
class Currency;
}

class Currency : public QMainWindow
{
    Q_OBJECT

public:
    explicit Currency(QWidget *parent = nullptr);
    ~Currency();
    void Update();


private slots:
    // Обработчик данных полученных от объекта QNetworkAccessManager
        void onResult(QNetworkReply *reply);
        void setupModel(const QString &tableName, const QStringList &headers);
        void createUI();




private:
    Ui::Currency *ui;
    QNetworkAccessManager *networkManager;

    DataBase        *db;
    QSqlQueryModel  *model_1;
    Vehicle         *car_curs;

    float temp_eur, temp_usd, temp_pln, temp_chf;
};

#endif // CURRENCY_H


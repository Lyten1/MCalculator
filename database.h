#ifndef DATABASE_H
#define DATABASE_H


#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "HostDataBase"
#define DATABASE_NAME       "DataBase.db"

#define HISTORY                   "History"
#define HISTORY_TYP               "TypeOfTrans"
#define HISTORY_PRICE             "Price"
#define HISTORY_VOLUME            "Volume"
#define HISTORY_YEAR              "Year"
#define HISTORY_OIL               "TypeOfOil"
#define HISTORY_RESULT            "Result"
#define HISTORY_RESULTEUR         "ResultInEur"

#define CURRENCY                  "Currency"
#define CURRENCY_CODE             "Code"
#define CURRENCY_NAME             "Name"
#define CURRENCY_RATE             "Rate"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();
    bool inserIntoTable_H(const QVariantList &data);
    bool inserIntoTable_C(const QVariantList &data);
    void clearCur();

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;



private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();

};

#endif // DATABASE_H






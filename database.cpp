#include "database.h"


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " HISTORY " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    HISTORY_TYP        " VARCHAR(255)    NOT NULL,"
                    HISTORY_PRICE      " VARCHAR(255)    NOT NULL,"
                    HISTORY_VOLUME     " VARCHAR(255)    NOT NULL,"
                    HISTORY_YEAR       " VARCHAR(255)    NOT NULL,"
                    HISTORY_OIL        " VARCHAR(255)    NOT NULL,"
                    HISTORY_RESULT     " VARCHAR(255)    NOT NULL,"
                    HISTORY_RESULTEUR  " VARCHAR(255)    NOT NULL"
                    " );"
                    )){
        qDebug() << "DataBase: error of create " << HISTORY;
        qDebug() << query.lastError().text();
        return false;
    }
    if(!query.exec( "CREATE TABLE " CURRENCY " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    CURRENCY_CODE        " VARCHAR(255)  NOT NULL, "
                    CURRENCY_NAME      " VARCHAR(255)  NOT NULL, "
                    CURRENCY_RATE     " VARCHAR(255)  NOT NULL"
                    " );"
                    )){
        qDebug() << "DataBase: error of create " << CURRENCY;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    }

    return true;


}

void DataBase::clearCur()
{
    QSqlQuery query;
    query.prepare("DELETE FROM " CURRENCY " ;");


    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into" << CURRENCY;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

    } ;

}

/* Метод для вставки записи в базу данных
 * */
bool DataBase::inserIntoTable_H(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " HISTORY " ( " HISTORY_TYP ", "
                  HISTORY_PRICE ", "
                  HISTORY_VOLUME ", "
                  HISTORY_YEAR", "
                  HISTORY_OIL ", "
                  HISTORY_RESULT ", "
                  HISTORY_RESULTEUR " ) "
                                    "VALUES (:Type, :Price,  :Volume, :Year, :Oil, :Result, :ResultEur );");
    query.bindValue(":Type",         data[0].toString());
    query.bindValue(":Price",        data[1].toString());
    query.bindValue(":Volume",       data[2].toString());
    query.bindValue(":Year",         data[3].toString());
    query.bindValue(":Oil",          data[4].toString());
    query.bindValue(":Result",       data[5].toString());
    query.bindValue(":ResultEur",    data[6].toString());
    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into" << HISTORY;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoTable_C(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " CURRENCY " ( " CURRENCY_CODE ", "
                  CURRENCY_NAME ", "
                  CURRENCY_RATE " ) "
                                "VALUES (:Code, :Name, :Rate);");
    query.bindValue(":Code",         data[0].toString());
    query.bindValue(":Name",         data[1].toString());
    query.bindValue(":Rate",         data[2].toString());

    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into" << CURRENCY;
        qDebug() << query.lastError().text();
        // qDebug() << query.lastQuery();
        return false;
    } else {
        return true;
    }
    return false;
}


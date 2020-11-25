#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QDateTime>

#include "database.h"
//#include <mainwindow.h>

namespace Ui {
class History;
}

class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
    void Update();


private:
    Ui::History *ui;

    friend class QMainWindow;

    DataBase        *db;
    QSqlQueryModel  *model;
};

#endif // HISTORY_H

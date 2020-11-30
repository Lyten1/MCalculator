#include "history.h"
#include <database.h>
#include "ui_history.h"

History::History(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);

    this->setupModel(HISTORY,
                     QStringList() << tr("Транспорт")
                                   << tr("Ціна")
                                   << tr("Об'єм")
                                   << tr("Рік")
                                   << tr("Тип палива")
                                   << tr("Результат")
                                   << tr("Рез. у євро")
               );


    this->createUI();


}



void History::setupModel(const QString &nameTable, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new QSqlQueryModel(this);


    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }


}

void History::createUI()
{
    ui->tableOfHist->setModel(model);     // Устанавливаем модель на TableView
    ui->tableOfHist->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->tableOfHist->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableOfHist->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableOfHist->resizeColumnsToContents();
    ui->tableOfHist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableOfHist->horizontalHeader()->setStretchLastSection(true);




}

void History::Update()
{
    model->setQuery("SELECT " HISTORY_TYP "," HISTORY_PRICE "," HISTORY_VOLUME "," HISTORY_YEAR "," HISTORY_OIL "," HISTORY_RESULT "," HISTORY_RESULTEUR " FROM " HISTORY " ORDER BY id DESC LIMIT 30;"); // Делаем выборку данных из таблицы
       /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    QStringList headers;
          headers << tr("Транспорт")
                  << tr("Ціна")
                  << tr("Об'єм")
                  << tr("Рік")
                  << tr("Тип палива")
                  << tr("Результат")
                  << tr("Рез. у євро");

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}


History::~History()
{
    delete ui;
}

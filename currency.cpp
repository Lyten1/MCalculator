#include "currency.h"
#include "ui_currency.h"







Currency::Currency(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Currency)
{



    networkManager = new QNetworkAccessManager();
    // Подключаем networkManager к обработчику ответа
    connect(networkManager, &QNetworkAccessManager::finished, this, &Currency::onResult);
    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json")));

    ui->setupUi(this);
    this->setupModel(CURRENCY,
                     QStringList() << tr("Код")
                     << tr("Назва")
                     << tr("Курс")

                     );


    this->createUI();
    //qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
}

Currency::~Currency()
{
    delete ui;
}

void Currency::setupModel(const QString &nameTable, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model_1 = new QSqlQueryModel(this);


    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < model_1->columnCount(), j < headers.count(); i++, j++){
        model_1->setHeaderData(i,Qt::Horizontal,headers[j]);
    }


}

void Currency::createUI()
{
    ui->tableView->setModel(model_1);     // Устанавливаем модель на TableView
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    //ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //ui->tableView->setColumnWidth(0, 40);




}

void Currency::Update()
{
    model_1->setQuery("SELECT " CURRENCY_CODE " , " CURRENCY_NAME " , " CURRENCY_RATE " FROM " CURRENCY " ;"); // Делаем выборку данных из таблицы
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    QStringList headers;
    headers << tr("Код")
            << tr("Назва")
            << tr("Курс");

    for(int i = 0, j = 0; i < model_1->columnCount(); i++, j++){
        model_1->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}




void Currency::onResult(QNetworkReply *reply)
{


    // Если ошибки отсутсвуют
    if(!reply->error()){
        db->clearCur();
        // То создаём объект Json Document, считав в него все данные из ответа
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        // Забираем из документа корневой объект
        QJsonArray root = document.array();


        for (int i = 0; i < root.size(); i++) {
            QVariantList data;
            data.append(QString("%1").arg(root[i].toObject().value("r030").toDouble()));
            data.append(root[i].toObject().value("txt").toString());
            data.append(QString("%1").arg(root[i].toObject().value("rate").toDouble()));

            if (data[0].toString() == "978") temp_eur = data[2].toFloat();//eur
            if (data[0].toString() == "985") temp_pln = data[2].toFloat();//pln
            if (data[0].toString() == "840") temp_usd = data[2].toFloat();//usd
            if (data[0].toString() == "756") temp_chf = data[2].toFloat();//chf

            // Вставляем данные в БД
            db->inserIntoTable_C(data);
        }


    }
    else qDebug() << "No network connection";

    car_curs = new Vehicle;
    car_curs->setCurs(temp_eur, temp_usd, temp_pln, temp_chf);

}


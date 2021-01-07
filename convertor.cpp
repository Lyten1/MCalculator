#include "convertor.h"
#include "ui_convertor.h"

#include "vehicle.h"

convertor::convertor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::convertor)
{

    ui->setupUi(this);
}

convertor::~convertor()
{
    delete ui;
}

void convertor::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

     QPainter qp(this);
     drawLines(&qp);
}

void convertor::drawLines(QPainter *qp)
{
    QPen pen(Qt::black, 6, Qt::SolidLine);
     qp->setPen(pen);
     qp->drawLine(160, 60, 160, 90);
     qp->drawLine(160, 93, 150, 85);
     qp->drawLine(161, 93, 170, 85);
}



void convertor::on_usd_f_cursorPositionChanged(int arg1, int arg2)
{
    float num = ui->usd_f->text().toFloat();
    num = (num * Vehicle::val_usd) / Vehicle::val_eur;
    ui->eur_f->setText(QString::number(num));
}

void convertor::on_usd_s_cursorPositionChanged(int arg1, int arg2)
{
    float num = ui->usd_s->text().toFloat();
    num = (num * Vehicle::val_usd) / Vehicle::val_eur;
    ui->eur_s->setText(QString::number(num));
}

void convertor::on_usd_t_cursorPositionChanged(int arg1, int arg2)
{
    float num = ui->usd_t->text().toFloat();
    num = (num * Vehicle::val_usd) / Vehicle::val_eur;
    ui->eur_t->setText(QString::number(num));
}

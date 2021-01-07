#ifndef CONVERTOR_H
#define CONVERTOR_H

#include <QMainWindow>
#include <QPainter>



namespace Ui {
class convertor;
}

class convertor : public QMainWindow
{
    Q_OBJECT

public:
    explicit convertor(QWidget *parent = nullptr);
    ~convertor();
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);

private slots:


    void on_usd_f_cursorPositionChanged(int arg1, int arg2);

    void on_usd_s_cursorPositionChanged(int arg1, int arg2);

    void on_usd_t_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::convertor *ui;
};

#endif // CONVERTOR_H

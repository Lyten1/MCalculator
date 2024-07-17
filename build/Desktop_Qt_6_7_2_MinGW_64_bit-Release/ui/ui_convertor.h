/********************************************************************************
** Form generated from reading UI file 'convertor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTOR_H
#define UI_CONVERTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_convertor
{
public:
    QWidget *centralwidget;
    QLabel *usd;
    QLineEdit *usd_f;
    QLineEdit *usd_s;
    QLineEdit *usd_t;
    QLabel *eur;
    QLineEdit *eur_f;
    QLineEdit *eur_s;
    QLineEdit *eur_t;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *convertor)
    {
        if (convertor->objectName().isEmpty())
            convertor->setObjectName("convertor");
        convertor->resize(312, 158);
        centralwidget = new QWidget(convertor);
        centralwidget->setObjectName("centralwidget");
        usd = new QLabel(centralwidget);
        usd->setObjectName("usd");
        usd->setGeometry(QRect(10, 10, 21, 21));
        QFont font;
        font.setPointSize(14);
        usd->setFont(font);
        usd_f = new QLineEdit(centralwidget);
        usd_f->setObjectName("usd_f");
        usd_f->setGeometry(QRect(30, 30, 81, 21));
        usd_s = new QLineEdit(centralwidget);
        usd_s->setObjectName("usd_s");
        usd_s->setGeometry(QRect(120, 30, 81, 21));
        usd_t = new QLineEdit(centralwidget);
        usd_t->setObjectName("usd_t");
        usd_t->setGeometry(QRect(210, 30, 81, 21));
        eur = new QLabel(centralwidget);
        eur->setObjectName("eur");
        eur->setGeometry(QRect(10, 90, 21, 21));
        eur->setFont(font);
        eur_f = new QLineEdit(centralwidget);
        eur_f->setObjectName("eur_f");
        eur_f->setGeometry(QRect(30, 110, 81, 21));
        eur_s = new QLineEdit(centralwidget);
        eur_s->setObjectName("eur_s");
        eur_s->setGeometry(QRect(120, 110, 81, 21));
        eur_t = new QLineEdit(centralwidget);
        eur_t->setObjectName("eur_t");
        eur_t->setGeometry(QRect(210, 110, 81, 21));
        convertor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(convertor);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 312, 20));
        convertor->setMenuBar(menubar);
        statusbar = new QStatusBar(convertor);
        statusbar->setObjectName("statusbar");
        convertor->setStatusBar(statusbar);

        retranslateUi(convertor);

        QMetaObject::connectSlotsByName(convertor);
    } // setupUi

    void retranslateUi(QMainWindow *convertor)
    {
        convertor->setWindowTitle(QCoreApplication::translate("convertor", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\202\320\276\321\200", nullptr));
        usd->setText(QCoreApplication::translate("convertor", "$", nullptr));
        eur->setText(QCoreApplication::translate("convertor", "\342\202\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class convertor: public Ui_convertor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTOR_H

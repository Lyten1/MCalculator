/********************************************************************************
** Form generated from reading UI file 'currency.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENCY_H
#define UI_CURRENCY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Currency
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Currency)
    {
        if (Currency->objectName().isEmpty())
            Currency->setObjectName("Currency");
        Currency->resize(380, 472);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Currency->sizePolicy().hasHeightForWidth());
        Currency->setSizePolicy(sizePolicy);
        Currency->setMinimumSize(QSize(380, 472));
        Currency->setMaximumSize(QSize(380, 472));
        centralwidget = new QWidget(Currency);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 361, 431));
        Currency->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Currency);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 380, 20));
        Currency->setMenuBar(menubar);
        statusbar = new QStatusBar(Currency);
        statusbar->setObjectName("statusbar");
        Currency->setStatusBar(statusbar);

        retranslateUi(Currency);

        QMetaObject::connectSlotsByName(Currency);
    } // setupUi

    void retranslateUi(QMainWindow *Currency)
    {
        Currency->setWindowTitle(QCoreApplication::translate("Currency", "\320\222\320\260\320\273\321\216\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Currency: public Ui_Currency {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENCY_H

/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_History
{
public:
    QWidget *centralwidget;
    QTableView *tableOfHist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *History)
    {
        if (History->objectName().isEmpty())
            History->setObjectName("History");
        History->setEnabled(true);
        History->resize(750, 320);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(History->sizePolicy().hasHeightForWidth());
        History->setSizePolicy(sizePolicy);
        History->setMinimumSize(QSize(750, 320));
        History->setMaximumSize(QSize(750, 320));
        History->setMouseTracking(false);
        History->setAcceptDrops(false);
        centralwidget = new QWidget(History);
        centralwidget->setObjectName("centralwidget");
        tableOfHist = new QTableView(centralwidget);
        tableOfHist->setObjectName("tableOfHist");
        tableOfHist->setGeometry(QRect(10, 10, 731, 290));
        History->setCentralWidget(centralwidget);
        menubar = new QMenuBar(History);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 20));
        History->setMenuBar(menubar);
        statusbar = new QStatusBar(History);
        statusbar->setObjectName("statusbar");
        History->setStatusBar(statusbar);

        retranslateUi(History);

        QMetaObject::connectSlotsByName(History);
    } // setupUi

    void retranslateUi(QMainWindow *History)
    {
        History->setWindowTitle(QCoreApplication::translate("History", "\320\206\321\201\321\202\320\276\321\200\321\226\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class History: public Ui_History {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H

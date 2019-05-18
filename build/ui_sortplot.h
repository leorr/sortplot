/********************************************************************************
** Form generated from reading UI file 'sortplot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTPLOT_H
#define UI_SORTPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_sortplot
{
public:
    QWidget *centralWidget;
    QCustomPlot *plot;
    QPushButton *unsortButton;
    QPushButton *sortButton;
    QComboBox *sorting;
    QLCDNumber *comp;
    QLCDNumber *swi;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *sortplot)
    {
        if (sortplot->objectName().isEmpty())
            sortplot->setObjectName(QString::fromUtf8("sortplot"));
        sortplot->resize(1001, 510);
        centralWidget = new QWidget(sortplot);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(249, 10, 741, 491));
        unsortButton = new QPushButton(centralWidget);
        unsortButton->setObjectName(QString::fromUtf8("unsortButton"));
        unsortButton->setGeometry(QRect(20, 30, 80, 24));
        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setGeometry(QRect(150, 30, 80, 24));
        sorting = new QComboBox(centralWidget);
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setGeometry(QRect(10, 80, 231, 24));
        comp = new QLCDNumber(centralWidget);
        comp->setObjectName(QString::fromUtf8("comp"));
        comp->setGeometry(QRect(110, 180, 131, 31));
        swi = new QLCDNumber(centralWidget);
        swi->setObjectName(QString::fromUtf8("swi"));
        swi->setGeometry(QRect(110, 320, 131, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 300, 51, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 160, 101, 16));
        label_2->setFont(font);
        sortplot->setCentralWidget(centralWidget);

        retranslateUi(sortplot);

        QMetaObject::connectSlotsByName(sortplot);
    } // setupUi

    void retranslateUi(QMainWindow *sortplot)
    {
        sortplot->setWindowTitle(QApplication::translate("sortplot", "sortplot", nullptr));
        unsortButton->setText(QApplication::translate("sortplot", "unsort", nullptr));
        sortButton->setText(QApplication::translate("sortplot", "sort", nullptr));
        sorting->setItemText(0, QApplication::translate("sortplot", "Selection sort", nullptr));
        sorting->setItemText(1, QApplication::translate("sortplot", "Merge sort", nullptr));
        sorting->setItemText(2, QApplication::translate("sortplot", "Bubble sort", nullptr));
        sorting->setItemText(3, QApplication::translate("sortplot", "Insertion sort", nullptr));

        label->setText(QApplication::translate("sortplot", "Trocas", nullptr));
        label_2->setText(QApplication::translate("sortplot", "Compara\303\247\303\265es", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sortplot: public Ui_sortplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTPLOT_H

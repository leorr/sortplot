/********************************************************************************
** Form generated from reading UI file 'sortplot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_sortplot
{
public:
    QWidget *centralWidget;
    QCustomPlot *plot;
    QLabel *label_2;
    QLCDNumber *comp;
    QLCDNumber *swi;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_4;
    QPushButton *sortButton;
    QPushButton *unsortButton;
    QPushButton *resetButton;
    QComboBox *sorting;

    void setupUi(QMainWindow *sortplot)
    {
        if (sortplot->objectName().isEmpty())
            sortplot->setObjectName(QString::fromUtf8("sortplot"));
        sortplot->resize(1001, 510);
        centralWidget = new QWidget(sortplot);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(-1, 0, 1001, 511));
        label_2 = new QLabel(plot);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(880, 0, 101, 16));
        comp = new QLCDNumber(plot);
        comp->setObjectName(QString::fromUtf8("comp"));
        comp->setGeometry(QRect(860, 20, 131, 31));
        swi = new QLCDNumber(plot);
        swi->setObjectName(QString::fromUtf8("swi"));
        swi->setGeometry(QRect(720, 20, 131, 31));
        label = new QLabel(plot);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(760, 0, 51, 20));
        spinBox = new QSpinBox(plot);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(630, 0, 81, 51));
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000);
        spinBox->setValue(10);
        label_4 = new QLabel(plot);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(600, 0, 20, 51));
        sortButton = new QPushButton(plot);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setGeometry(QRect(510, 0, 80, 24));
        unsortButton = new QPushButton(plot);
        unsortButton->setObjectName(QString::fromUtf8("unsortButton"));
        unsortButton->setGeometry(QRect(510, 30, 80, 24));
        resetButton = new QPushButton(plot);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(420, 30, 80, 24));
        sorting = new QComboBox(plot);
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setGeometry(QRect(130, 0, 231, 24));
        sortplot->setCentralWidget(centralWidget);

        retranslateUi(sortplot);

        QMetaObject::connectSlotsByName(sortplot);
    } // setupUi

    void retranslateUi(QMainWindow *sortplot)
    {
        sortplot->setWindowTitle(QApplication::translate("sortplot", "sortplot", nullptr));
        label_2->setText(QApplication::translate("sortplot", "Compara\303\247\303\265es", nullptr));
        label->setText(QApplication::translate("sortplot", "Trocas", nullptr));
        label_4->setText(QApplication::translate("sortplot", "N", nullptr));
        sortButton->setText(QApplication::translate("sortplot", "sort", nullptr));
        unsortButton->setText(QApplication::translate("sortplot", "unsort", nullptr));
        resetButton->setText(QApplication::translate("sortplot", "reset", nullptr));
        sorting->setItemText(0, QApplication::translate("sortplot", "Selection sort", nullptr));
        sorting->setItemText(1, QApplication::translate("sortplot", "Merge sort", nullptr));
        sorting->setItemText(2, QApplication::translate("sortplot", "Bubble sort", nullptr));
        sorting->setItemText(3, QApplication::translate("sortplot", "Insertion sort", nullptr));
        sorting->setItemText(4, QApplication::translate("sortplot", "Quick sort", nullptr));
        sorting->setItemText(5, QApplication::translate("sortplot", "Count sort", nullptr));
        sorting->setItemText(6, QApplication::translate("sortplot", "Shell sort", nullptr));

    } // retranslateUi

};

namespace Ui {
    class sortplot: public Ui_sortplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTPLOT_H

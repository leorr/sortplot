/********************************************************************************
** Form generated from reading UI file 'sortplot.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
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
    QLCDNumber *swi;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QLCDNumber *comp;
    QLabel *label;
    QLabel *label_4;
    QComboBox *sorting;
    QPushButton *resetButton;
    QSpinBox *spinBox;
    QPushButton *unsortButton;
    QLCDNumber *mem;
    QPushButton *sortButton;
    QLabel *label_3;

    void setupUi(QMainWindow *sortplot)
    {
        if (sortplot->objectName().isEmpty())
            sortplot->setObjectName(QString::fromUtf8("sortplot"));
        sortplot->resize(1001, 510);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        sortplot->setPalette(palette);
        centralWidget = new QWidget(sortplot);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        centralWidget->setPalette(palette1);
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(0, 70, 1001, 441));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(900, 0, 101, 16));
        swi = new QLCDNumber(centralWidget);
        swi->setObjectName(QString::fromUtf8("swi"));
        swi->setGeometry(QRect(810, 20, 81, 31));
        swi->setFrameShape(QFrame::Panel);
        swi->setFrameShadow(QFrame::Plain);
        swi->setSmallDecimalPoint(false);
        swi->setSegmentStyle(QLCDNumber::Flat);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(400, 10, 41, 51));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(450, 10, 81, 51));
        spinBox_2->setWrapping(false);
        spinBox_2->setFrame(true);
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_2->setAccelerated(false);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(9999999);
        spinBox_2->setValue(10);
        comp = new QLCDNumber(centralWidget);
        comp->setObjectName(QString::fromUtf8("comp"));
        comp->setGeometry(QRect(900, 20, 91, 31));
        comp->setFrameShape(QFrame::Panel);
        comp->setFrameShadow(QFrame::Plain);
        comp->setMidLineWidth(0);
        comp->setSegmentStyle(QLCDNumber::Flat);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 0, 51, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(540, 10, 20, 51));
        sorting = new QComboBox(centralWidget);
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->addItem(QString());
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setGeometry(QRect(10, 10, 231, 24));
        sorting->setFrame(true);
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(269, 43, 51, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(560, 10, 81, 51));
        spinBox->setWrapping(false);
        spinBox->setFrame(true);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox->setAccelerated(false);
        spinBox->setMinimum(1);
        spinBox->setMaximum(9999);
        spinBox->setValue(10);
        unsortButton = new QPushButton(centralWidget);
        unsortButton->setObjectName(QString::fromUtf8("unsortButton"));
        unsortButton->setGeometry(QRect(330, 43, 51, 21));
        mem = new QLCDNumber(centralWidget);
        mem->setObjectName(QString::fromUtf8("mem"));
        mem->setEnabled(true);
        mem->setGeometry(QRect(650, 20, 151, 31));
        mem->setFrameShape(QFrame::Panel);
        mem->setFrameShadow(QFrame::Plain);
        mem->setSmallDecimalPoint(false);
        mem->setDigitCount(10);
        mem->setSegmentStyle(QLCDNumber::Flat);
        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setGeometry(QRect(269, 10, 111, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(650, 0, 101, 20));
        sortplot->setCentralWidget(centralWidget);

        retranslateUi(sortplot);

        QMetaObject::connectSlotsByName(sortplot);
    } // setupUi

    void retranslateUi(QMainWindow *sortplot)
    {
        sortplot->setWindowTitle(QCoreApplication::translate("sortplot", "sortplot", nullptr));
        label_2->setText(QCoreApplication::translate("sortplot", "Compara\303\247\303\265es", nullptr));
        label_5->setText(QCoreApplication::translate("sortplot", "Range", nullptr));
        label->setText(QCoreApplication::translate("sortplot", "Trocas", nullptr));
        label_4->setText(QCoreApplication::translate("sortplot", "N", nullptr));
        sorting->setItemText(0, QCoreApplication::translate("sortplot", "Selection sort", nullptr));
        sorting->setItemText(1, QCoreApplication::translate("sortplot", "Bubble sort", nullptr));
        sorting->setItemText(2, QCoreApplication::translate("sortplot", "Insertion sort", nullptr));
        sorting->setItemText(3, QCoreApplication::translate("sortplot", "Merge sort", nullptr));
        sorting->setItemText(4, QCoreApplication::translate("sortplot", "Quick sort", nullptr));
        sorting->setItemText(5, QCoreApplication::translate("sortplot", "Count sort", nullptr));
        sorting->setItemText(6, QCoreApplication::translate("sortplot", "Shell sort", nullptr));
        sorting->setItemText(7, QCoreApplication::translate("sortplot", "Shell sort Knuth", nullptr));

        resetButton->setText(QCoreApplication::translate("sortplot", "unsort", nullptr));
        unsortButton->setText(QCoreApplication::translate("sortplot", "new", nullptr));
        sortButton->setText(QCoreApplication::translate("sortplot", "sort", nullptr));
        label_3->setText(QCoreApplication::translate("sortplot", "Bytes alocados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sortplot: public Ui_sortplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTPLOT_H

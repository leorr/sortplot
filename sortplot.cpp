#include "sortplot.h"
#include "ui_sortplot.h"

QVector<double> qv_x(100),qv_y(100);
QCPBars *bar;
QCPBars *hl;

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
        ui->setupUi(this);
        sortplot::replotbars();
	}

sortplot::~sortplot(){
	delete ui;
}

void sortplot::on_sortButton_clicked(){

}

QCPBars* sortplot::replotbars(){
    QCPBars* nbar;
    ui->plot->clearPlottables();
    ui->plot->xAxis->grid()->setVisible(true);
    //the bar width requires to add 1 in the frontiers
    ui->plot->xAxis->setRange(-1, 101);
    ui->plot->yAxis->setRange(0,100);
    nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    nbar->setStackingGap(0);
    nbar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    nbar->setBrush(QColor(111, 9, 176));
    nbar->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
    return nbar;
}

void sortplot::on_unsortButton_clicked(){
    for (int i = 0; i < qv_x.size(); i++){qv_x[i]=i;qv_y[i] = rand() % 100;}//setting x from 0 to 99 and y to a random number
    bar = replotbars();
}

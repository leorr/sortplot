#include "sortplot.h"
#include "ui_sortplot.h"

QVector<double> qv_x(500),qv_y(500);

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
        ui->setupUi(this);
	ui->plot->xAxis->grid()->setVisible(false);
	ui->plot->xAxis->setRange(-1, 501);
	ui->plot->yAxis->setRange(0, 1200);
	
	unsort();

	}

sortplot::~sortplot(){
	delete ui;
}

void sortplot::on_sortButton_clicked(){
	int min,aux;
	//selection sort
	for (int i = 0; i < qv_x.size(); i++) {
		min = i;
		//plot in green the min
		for(int j =i+1;j< qv_x.size();j++){
			//plot in red the j
			if(qv_y[j]<qv_y[min]){
				min = j;
			}
		}
		if(qv_y[i] != qv_y[min]){
			//plot in blue both and unplot
			aux = qv_y[i];
			qv_y[i] = qv_y[min];
			qv_y[min] = aux;
			replotbars(min,i);
		}
		else
			replotbars(min,i);
	}
	
}



void sortplot::on_unsortButton_clicked(){
	unsort();
}

void sortplot::replotbars(int min,int key){
	
	QCPBars* nbar;
	QCPBars* keybar;
	QCPBars* minbar;
	
	ui->plot->clearPlottables();
	
	nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	minbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	keybar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	
	nbar->setStackingGap(0);
	nbar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
	nbar->setBrush(QColor(111, 9, 176));
	nbar->setData(qv_x,qv_y);
	
	minbar->setPen(QColor(255, 0, 70, 255));
        minbar->addData(min,1001);
	
	keybar->setPen(QColor(0,255,255));
	keybar->addData(key,1001);

	ui->plot->replot();
}
void sortplot::unsort(){
	for (int i = 0; i < qv_x.size(); i++){qv_x[i]=i;qv_y[i] = rand() % 1000;}//setting x from 0 to 99 and y to a random number
	replotbars(-2,-2);
}

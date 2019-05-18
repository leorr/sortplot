#include "sortplot.h"
#include "ui_sortplot.h"

QVector<double> qv_x(50),qv_y(50);
int minim,aux;//variavéis unicamente auxíliares
int comp,swi;//contador de comparações e trocas realizadas

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
			ui->setupUi(this);
			ui->plot->xAxis->grid()->setVisible(false);
			ui->plot->xAxis->setRange(-1, 51);
			ui->plot->yAxis->setRange(0, 1200);
			unsort();
	}//init

sortplot::~sortplot(){
	delete ui;
}

void sortplot::on_sortButton_clicked(){
	//<selection sort>
	ui->comp->display(0);
	ui->swi->display(0);
	minim=0,aux=0,comp=0,swi=0;
	
	if(ui->sorting->currentText() == "Selection sort"){
		for (int i = 0; i < qv_x.size(); i++) {
			minim = i;
			for(int j =i+1;j< qv_x.size();j++){
				ui->comp->display(++comp);
				replotbars(i,j);
				if(qv_y[j]<qv_y[minim])
					minim = j;
			}
			if(qv_y[i] != qv_y[minim]){
				ui->swi->display(++swi);
				aux = qv_y[i];
				qv_y[i] = qv_y[minim];
				qv_y[minim] = aux;
			}
			
		}
	}
	//<bubble sort>
	if(ui->sorting->currentText() == "Bubble sort"){
		for (int i = 1; i < qv_x.size(); i++) {
			for (int j = 0; j < qv_x.size() -i ; j++) {
				ui->comp->display(++comp);
				if (qv_y[j] > qv_y[j+1]) {
					ui->swi->display(++swi);
					aux = qv_y[j];
					qv_y[j] = qv_y[j+1];
					qv_y[j+1] = aux;
				}
				replotbars(j+1,j);
			}
		}
	}//</bubble sort>
	//<insertion sort>
	if(ui->sorting->currentText() == "Insertion sort"){
		for (int i = 0; i < qv_y.size(); i++) {
			aux = i;
			while(aux>0){
				ui->comp->display(++comp);
				replotbars(i+1,aux);
				if(qv_y[aux-1]>qv_y[aux]){
					ui->swi->display(++swi);
					int temp = qv_y[aux-1];
					qv_y[aux-1] = qv_y[aux];
					qv_y[aux] =temp;
				}
				else{
					break;
				}
			aux--;
			}
		}
	}//</insertion sort>	
	if(ui->sorting->currentText() == "Merge sort")
		mergeSort(0,49);
}



void sortplot::on_unsortButton_clicked(){
	unsort();
}

void sortplot::replotbars(int minim,int key){
	
	QCPBars* nbar;
	QCPBars* keybar;
	QCPBars* minimbar;
	
	ui->plot->clearPlottables();
	
	nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	minimbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	keybar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	
	nbar->setStackingGap(0);
	nbar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
	nbar->setBrush(QColor(111, 9, 176));
	nbar->setData(qv_x,qv_y);
	
	minimbar->setPen(QColor(255, 0, 70, 255));
	minimbar->addData(minim,1001);
	
	keybar->setPen(QColor(0,255,255));
	keybar->addData(key,1001);
	
	ui->plot->replot();
}
void sortplot::unsort(){
	for (int i = 0; i < qv_x.size(); i++){qv_x[i]=i;qv_y[i] = rand() % 1000;}//setting x from 0 to 99 and y to a random number
	replotbars(-2,-2);
}

void sortplot::merge(int l,int m,int r){
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
	for (i = 0; i < n1; i++)
		L[i] = qv_y[l + i]; 
    for (j = 0; j < n2; j++) 
		R[j] = qv_y[m + 1+ j]; 
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2){ 
		ui->comp->display(++comp);
        if (L[i] <= R[j]) {
			replotbars(i,j);
			ui->swi->display(++swi);
            qv_y[k] = L[i]; 
            i++; 
        } 
        else{ 
			replotbars(k,j);
			ui->swi->display(++swi);
            qv_y[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
		replotbars(k,i);
		ui->swi->display(++swi);
        qv_y[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
		replotbars(k,j);
		ui->swi->display(++swi);
        qv_y[k] = R[j]; 
        j++; 
        k++; 
    } 
	return;
}
void sortplot::mergeSort(int l, int r) { 
    if (l < r){ 
        int m = l+(r-l)/2; 
        mergeSort(l, m); 
        mergeSort(m+1, r); 
        merge(l, m, r); 
    } 
} 


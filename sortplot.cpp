#include "sortplot.h"
#include "ui_sortplot.h"
#include <iostream>

int range=10;
int vsize=10;
QVector<double> qv_x(vsize),qv_y(vsize),qv_tmp(vsize);
int minv,aux;//variavéis unicamente auxíliares
int comp,swi;//contador de comparações e trocas realizadas
int umem=0;
int maxmem=0;

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
			ui->setupUi(this);
			ui->plot->xAxis->grid()->setVisible(false);
			ui->plot->xAxis->setRange(-1, vsize);
			ui->plot->yAxis->setRange(0, range+2*range/10);
			ui->plot->xAxis->setTickLength(2);
			unsort();
	}//init

sortplot::~sortplot(){
	delete ui;
}

void sortplot::on_sortButton_clicked(){
	ui->comp->display(0);
	ui->swi->display(0);
	umem=0;
	maxmem=0;
	ui->mem->display(0);
	minv=0,aux=0,comp=0,swi=0;
	
	if(ui->sorting->currentText() == "Selection sort")
		selectionSort();	
	if(ui->sorting->currentText() == "Bubble sort")
		bubbleSort();	
	if(ui->sorting->currentText() == "Insertion sort")
		insertionSort();
	if(ui->sorting->currentText() == "Merge sort")
		mergeSort(0,vsize-1);
	if(ui->sorting->currentText() == "Quick sort")
		quickSort(0,vsize-1);
	if(ui->sorting->currentText() == "Shell sort")
		shellSort();
	if(ui->sorting->currentText() == "Shell sort Knuth")
		shellSortKnuth();
	if(ui->sorting->currentText() == "Count sort")
		countSort();

}

void sortplot::on_unsortButton_clicked(){
	unsort();
}

void sortplot::replotbars(int minv,int key,int scan,int scani){
	
	QCPBars* nbar;

	QCPBars* keybar;
	QCPBars* minvbar;
	QCPBars* scanbar;
	QCPBars* scanbari;
	
	ui->plot->clearPlottables();
	
	scanbari = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	scanbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	minvbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	keybar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	
	nbar->setStackingGap(0);
	nbar->setPen(QPen(QColor(111, 9, 176,0).lighter(170)));
	nbar->setBrush(QColor(111, 9, 176));
	nbar->setData(qv_x,qv_y);
	
	minvbar->setPen(QColor(255, 0, 70, 255));
	minvbar->addData(minv,range+2*range/10);
	
	keybar->setPen(QColor(0,255,255));
	keybar->addData(key,range+2*range/10);
	
	scanbar->setPen(QColor(0,255,0));
	scanbar->addData(scan,range+2*range/10);
	
	scanbari->setPen(QColor(255,255,0));
	scanbari->addData(scani,range+2*range/10);

	ui->plot->replot();
}
void sortplot::replotbars(int e1,int e2){
	
	QCPBars* nbar;

	QCPBars* be1;
	QCPBars* be2;
	
	ui->plot->clearPlottables();
	
	nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	be1 = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	be2 = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	
	nbar->setStackingGap(0);
	nbar->setPen(QPen(QColor(111, 9, 176,0).lighter(170)));
	nbar->setBrush(QColor(111, 9, 176));
	nbar->setData(qv_x,qv_y);
	
	be1->setPen(QColor(255,0,0));
	be1->addData(e1,range+2*range/10);

	be2->setPen(QColor(255,0,0));
	be2->addData(e2,range+2*range/10);

	ui->plot->replot();
}


void sortplot::unsort(){
	for (int i = 0; i < qv_x.size(); i++){
		qv_x[i]=i;
		qv_y[i] = (rand() % range)+1;
	}//x =(0;99) y={?;?}
	qv_tmp = qv_y;
	replotbars(-2,-2,-2,-2);
}
void sortplot::on_resetButton_clicked(){
	qv_y= qv_tmp;
	replotbars(-2,-2,-2,-2);
}

void sortplot::on_spinBox_valueChanged(int arg1){
		qv_x.resize(arg1);
		qv_y.resize(arg1);
		vsize=arg1;
		ui->plot->xAxis->setRange(-1, arg1+1);
		unsort();
}
void sortplot::on_spinBox_2_valueChanged(int arg1){
		range=arg1;
		ui->plot->yAxis->setRange(0, range+2*range/10);
		unsort();
}

void sortplot::merge(int l,int m,int r){
	int i, j, k;
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2];
	umem+=20+n1*4+n2*4;
	if(maxmem < umem)
		maxmem=umem;
	ui->mem->display(umem);
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
			replotbars(k,l,r,-2);
			ui->swi->display(++swi);
            qv_y[k] = L[i]; 
            i++; 
        } 
        else{ 
			replotbars(k,l,r,-2);
			ui->swi->display(++swi);
            qv_y[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
		replotbars(k,l,r,-2);
		ui->swi->display(++swi);
        qv_y[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
		replotbars(k,k,k,-2);
		ui->swi->display(++swi);
        qv_y[k] = R[j]; 
        j++; 
        k++; 
    }
	umem=0;
	ui->mem->display(umem);
	return;
}

void sortplot::mergeSort(int l, int r) { 
    if (l < r){ 
        int m = l+(r-l)/2;//l=0, r = tamanho -1
		umem+=4;
		ui->mem->display(umem);
        mergeSort(l, m);//separa o vetor em vários vetores menores
        mergeSort(m+1, r);//stacks de pequenos vetores na call
        merge(l, m, r);
    }
	ui->mem->display(maxmem);
	replotbars(-10,-10,-10,-10);
} 

void sortplot::selectionSort(){
	ui->mem->display(16);
	for (int i = 0; i < qv_x.size(); i++) {
    	minv = i;
    	for(int j =i+1;j< qv_x.size();j++){
    		ui->comp->display(++comp);
    		if(qv_y[j]<qv_y[minv])
    			minv = j;
    		replotbars(minv,j,i,-2);
    	}
    	if(qv_y[i] != qv_y[minv]){
    		ui->swi->display(++swi);
    		aux = qv_y[i];
    		qv_y[i] = qv_y[minv];
    		qv_y[minv] = aux;
    	}
    	
    }
    replotbars(-10,-10,-10,-2);//replot retirando highlights
}

void sortplot::bubbleSort(){
	ui->mem->display(12);
	for (int i = 1; i < qv_x.size(); i++) {
    	for (int j = 0; j < qv_x.size() -i ; j++) {
    		ui->comp->display(++comp);
    		if (qv_y[j] > qv_y[j+1]) {
    			ui->swi->display(++swi);
    			aux = qv_y[j];
    			qv_y[j] = qv_y[j+1];
    			qv_y[j+1] = aux;
    		}
    		replotbars(j+1,j,qv_x.size()-i,-2);
    	}
    }
    replotbars(-10,-10,-10,-2);
}

void sortplot::insertionSort(){
	ui->mem->display(12);
	for (int i = 1; i < qv_y.size(); i++) {
    	int k = qv_y[i];
		int j = i-1;
		ui->comp->display(++comp);
		while(j>=0 && qv_y[j] > k){
		ui->comp->display(++comp);
			ui->swi->display(++swi);
			qv_y[j+1] = qv_y[j];
			j--;
			replotbars(i+1,j+1,i,-2);
			ui->comp->display(++comp);
		}
		qv_y[j+1]=k;
    }
    replotbars(-10,-10,-10,-2);
}

void sortplot::shellSortKnuth(){
	ui->mem->display(16);
	int h = 1;
	while(h<qv_y.size()/3)
		h=(3*h)+1;
	while(h>=1){
		for (int i = h; i < qv_y.size(); i += 1){ 
			int temp = qv_y[i]; 
        	int j;
			ui->comp->display(++comp);
        	for (j = i; j >= h && qv_y[j - h] > temp; j -= h){
				replotbars(j,j-h);
            	qv_y[j] = qv_y[j - h];
				replotbars(j,j-h);
				ui->swi->display(++swi);
			}
			replotbars(j,i);
        	qv_y[j] = temp;
			replotbars(j,i);
			ui->swi->display(++swi);
		}
		h=h/3;
	}
    replotbars(-10,-10,-10,-2);
}
void sortplot::shellSort(){
	ui->mem->display(16);
	for (int gap = qv_x.size()/2 ;  gap > 0;  gap /= 2) {
		for (int i = gap; i < qv_y.size(); i += 1){ 
            int temp = qv_y[i]; 
            int j;
			ui->comp->display(++comp);
            for (j = i; j >= gap && qv_y[j - gap] > temp; j -= gap){
				replotbars(j,j-gap);
                qv_y[j] = qv_y[j - gap];
				replotbars(j,j-gap);
				ui->swi->display(++swi);
			}
			replotbars(j,i);
            qv_y[j] = temp;
			replotbars(j,i);
			ui->swi->display(++swi);
        } 
    } 		
    replotbars(-10,-10,-10,-2);
}
int sortplot::partition(int low, int high){
	int pivot = qv_y[high];
    int i = (low -1);
    for (int j = low; j <= high- 1; j++) { 
    	ui->comp->display(++comp);
        replotbars(i+1,j,high,low);
		if (qv_y[j] <= pivot) { 
            i++;
			int aux = qv_y[i];
			qv_y[i]=qv_y[j];
			qv_y[j]=aux;
			ui->swi->display(++swi);
        } 
    }
	replotbars(i+1,high,high,low);
	int aux = qv_y[high];
	qv_y[high]=qv_y[i+1];
	qv_y[i+1]=aux;
	ui->swi->display(++swi);
    return (i + 1); 
}
void sortplot::quickSort(int low, int high){
	ui->mem->display(24);
	if (low < high) { 
        int pivot = partition(low, high); 
        quickSort(low, pivot - 1); 
        quickSort(pivot + 1, high); 
    } 
    replotbars(-10,-10,-10,-2);
} 


void sortplot::countSort(){  
	//criar um vetor int vtmp de range posições preenchido com 0
	ui->mem->display(vsize*4 + 4*range + 4);

	int output[vsize];
	int count[range+1], i;
	for (int aux = 0; aux<range; aux++)
			count[aux]=0;

	//ler o vetor principal, sempre que encontrar i valor, incrementar vtmp[i] 
	for(i = 0; i<vsize; i++)  
        ++count[(int)qv_y[i]];

	//para j de 0 a range vtmp[j+1] += vtmp[j]
	for (i = 1; i <= range; ++i)  
        count[i] += count[i-1];

	//criamos um vetor vaux com o mesmo tamnho do vetor princpal
	//nas posições correspondentes é colocado o valor (index de vtmp) e -- vtmp
	for (i = 0; i<vsize; i++){
        output[count[(int)qv_y[i]]-1] = qv_y[i];
        --count[(int)qv_y[i]];
    }
	for (i = 0; i<vsize; i++){
		ui->swi->display(++swi);
        qv_y[i] = output[i];
		replotbars(i,i,i,i);
	}

    replotbars(-10,-10,-10,-10);
}

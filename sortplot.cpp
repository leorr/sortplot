#include "sortplot.h"
#include "ui_sortplot.h"

int vsize=10;
QVector<double> qv_x(vsize),qv_y(vsize);
int minv,aux;//variavéis unicamente auxíliares
int comp,swi;//contador de comparações e trocas realizadas

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
			ui->setupUi(this);
			ui->plot->xAxis->grid()->setVisible(false);
			ui->plot->xAxis->setRange(-1, vsize);
			ui->plot->yAxis->setRange(0, 1200);
			unsort();
	}//init

sortplot::~sortplot(){
	delete ui;
}

void sortplot::on_sortButton_clicked(){
	ui->comp->display(0);
	ui->swi->display(0);
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

}

void sortplot::on_unsortButton_clicked(){
	unsort();
}

void sortplot::replotbars(int minv,int key,int scan){
	
	QCPBars* nbar;
	QCPBars* keybar;
	QCPBars* minvbar;
	QCPBars* scanbar;
	
	
	ui->plot->clearPlottables();
	
	scanbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	nbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	minvbar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	keybar = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
	
	nbar->setStackingGap(0);
	nbar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
	nbar->setBrush(QColor(111, 9, 176));
	nbar->setData(qv_x,qv_y);
	
	minvbar->setPen(QColor(255, 0, 70, 255));
	minvbar->addData(minv,1001);
	
	keybar->setPen(QColor(0,255,255));
	keybar->addData(key,1001);
	
	scanbar->setPen(QColor(0,255,0));
	scanbar->addData(scan,1001);
	
	ui->plot->replot();
}

void sortplot::unsort(){
	for (int i = 0; i < qv_x.size(); i++){qv_x[i]=i;qv_y[i] = rand() % 1000;}//setting x from 0 to 99 and y to a random number
	replotbars(-2,-2,-2);
}

void sortplot::on_spinBox_valueChanged(int arg1){
		qv_x.resize(arg1);
		qv_y.resize(arg1);
		vsize=arg1;
		ui->plot->xAxis->setRange(-1, arg1+1);
		unsort();
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
			replotbars(k,k,k);
			ui->swi->display(++swi);
            qv_y[k] = L[i]; 
            i++; 
        } 
        else{ 
			replotbars(k,k,k);
			ui->swi->display(++swi);
            qv_y[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
		replotbars(k,k,k);
		ui->swi->display(++swi);
        qv_y[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
		replotbars(k,k,k);
		ui->swi->display(++swi);
        qv_y[k] = R[j]; 
        j++; 
        k++; 
    } 
	return;
}

void sortplot::mergeSort(int l, int r) { 
    if (l < r){ 
        int m = l+(r-l)/2;//l=0, r = tamanho -1
        mergeSort(l, m);//separa o vetor tem vários vetores menores, criando stacks de pequenos vetores na call
        mergeSort(m+1, r); 
        merge(l, m, r);
    }
	replotbars(-10,-10,-10);
} 

void sortplot::selectionSort(){
	for (int i = 0; i < qv_x.size(); i++) {
    	minv = i;
    	for(int j =i+1;j< qv_x.size();j++){
    		ui->comp->display(++comp);
    		if(qv_y[j]<qv_y[minv])
    			minv = j;
    		replotbars(i,j,minv);
    	}
    	if(qv_y[i] != qv_y[minv]){
    		ui->swi->display(++swi);
    		aux = qv_y[i];
    		qv_y[i] = qv_y[minv];
    		qv_y[minv] = aux;
    	}
    	
    }
    replotbars(-10,-10,-10);//replot retirando highlights
}

void sortplot::bubbleSort(){
	for (int i = 1; i < qv_x.size(); i++) {
    	for (int j = 0; j < qv_x.size() -i ; j++) {
    		ui->comp->display(++comp);
    		if (qv_y[j] > qv_y[j+1]) {
    			ui->swi->display(++swi);
    			aux = qv_y[j];
    			qv_y[j] = qv_y[j+1];
    			qv_y[j+1] = aux;
    		}
    		replotbars(j+1,j,qv_x.size()-i);
    	}
    }
    replotbars(-10,-10,-10);
}

void sortplot::insertionSort(){
	for (int i = 0; i < qv_y.size(); i++) {
    	aux = i;
    	while(aux>0){
    		ui->comp->display(++comp);
    		replotbars(i+1,aux,aux);
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
    replotbars(-10,-10,-10);
}

void sortplot::shellSort(){
	for (int gap = qv_x.size()/2 ;  gap > 0;  gap /= 2) {
			
	}
	
}
int sortplot::partition(int low, int high){
	int pivot = qv_y[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) { 
    	ui->comp->display(++comp);
        replotbars(i,j,j);
		if (qv_y[j] <= pivot) { 
            i++;    // increment index of smaller element 
            //swap(&arr[i], &arr[j]); 
			int aux = qv_y[i];
			qv_y[i]=qv_y[j];
			qv_y[j]=aux;
			ui->swi->display(++swi);
        } 
    }
	replotbars(i+1,high,high);
	int aux = qv_y[high];
	qv_y[high]=qv_y[i+1];
	qv_y[i+1]=aux;
	ui->swi->display(++swi);
    return (i + 1); 
}
void sortplot::quickSort(int low, int high){
	if (low < high) { 
        int pivot = partition(low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(low, pivot - 1); 
        quickSort(pivot + 1, high); 
    } 
} 

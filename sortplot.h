#ifndef SORTPLOT_H
#define SORTPLOT_H

#include <QMainWindow>
#include "qcustomplot.h"

extern QVector<double> qv_x,qv_y;
extern QCPBars *bar;
extern QCPBars *hl;

namespace Ui {
	class sortplot;
}

class sortplot : public QMainWindow{
	Q_OBJECT

public:
	explicit sortplot(QWidget *parent = nullptr);
	~sortplot();


private slots:
	void unsort();
	void replotbars(int min,int key,int scan);

	void on_sortButton_clicked();
	void on_unsortButton_clicked();
	void on_resetButton_clicked();
    void on_spinBox_valueChanged(int arg1);

	void merge(int l,int m,int r);
	void mergeSort(int l, int r);
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	void quickSort(int low, int high);
	int partition(int low, int high);
	void shellSort();
	void countSort();


private:
	Ui::sortplot *ui;

};

#endif // SORTPLOT_H

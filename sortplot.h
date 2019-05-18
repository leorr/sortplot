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
	void replotbars(int min,int key);
	void on_sortButton_clicked();
	void on_unsortButton_clicked();
	void merge(int l,int m,int r);
	void mergeSort(int l, int r);

private:
	Ui::sortplot *ui;

};

#endif // SORTPLOT_H

#include "sortplot.h"
#include "ui_sortplot.h"

sortplot::sortplot(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::sortplot){
		ui->setupUi(this);
	}

sortplot::~sortplot(){
	delete ui;
}

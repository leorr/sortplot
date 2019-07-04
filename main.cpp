#include "sortplot.h"
#include <QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	sortplot w;
	w.show();
	a.exec();
	return 1;
}

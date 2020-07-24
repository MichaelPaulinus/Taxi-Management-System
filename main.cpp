#include "TaxiCoZa.h"
#include <QtWidgets/QApplication>
#include "Driver.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TaxiCoZa w;
	w.show();
	return a.exec();
}

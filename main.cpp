#include "TaxiCoZa.h"
#include <QtWidgets/QApplication>
#include <QtSql>
#include <QSqlDatabase> // means to add a database
#include <QSqlQuery> // means of executing SQL queries
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TaxiCoZa w;
	w.show();
	return a.exec();
}

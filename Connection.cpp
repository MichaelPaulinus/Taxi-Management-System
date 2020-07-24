#include "Connection.h"

Connection conn;

Connection::Connection() {
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("C:/Coding_Projects/SQL/Taxi.co.za/TaxiDB.db");
	Connection::connOpen();
}

Connection::~Connection() {

}

bool Connection::connOpen() {

	if (db.open()) {
		qDebug() << "Database Connected!";
		return true;
	}
	else {
		qDebug() << "Database Not Connected!";
		return false;
	}
}

void Connection::connClose() {
	db.close();
	db.removeDatabase(QSqlDatabase::defaultConnection);
}
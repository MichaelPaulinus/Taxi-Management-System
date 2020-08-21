#include "Connection.h"

Connection conn;

Connection::Connection() {
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Database/TaxiDB.db");
	Connection::connOpen();
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
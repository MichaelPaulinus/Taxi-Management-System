#pragma once

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

class Connection
{
public:
	//members
	QSqlDatabase db;

	//methods
	bool connOpen();
	void connClose();

	//constructors
	Connection();
};

extern Connection conn;


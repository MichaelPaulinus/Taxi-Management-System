#pragma once

#include <QtWidgets/QWidget>
#include "ui_TaxiCoZa.h"
#include <QtSql>
#include <QSqlDatabase> // means to add a database
#include <QSqlQuery> // means of executing SQL queries
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include "Register.h"

class TaxiCoZa : public QWidget
{
	Q_OBJECT

public:
	QSqlDatabase db;

	void connClose() {
		db.close();
		db.removeDatabase(QSqlDatabase::defaultConnection);
	}
	
	bool connOpen() {
		// this is the setup for the database 
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("C:/Coding_Projects/SQL/Taxi.co.za/TaxiDB.db");

		if (db.open()) {
			qDebug() << "Database Connected!";
			return true;
		}
		else {
			qDebug() << "Database Not Connected!";
			return false;
		}
	}

public:
	TaxiCoZa(QWidget* parent = Q_NULLPTR);

private:
	Ui::TaxiCoZaClass ui;

private slots:
	void on_loginButton_clicked();
	void on_signupButton_clicked();
	
};

#pragma once

#include <QDialog>
#include "ui_DriverArrival.h"
#include <QtSql>
#include <QSqlDatabase> // means to add a database
#include <QSqlQuery> // means of executing SQL queries
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include "TaxiCoZa.h"
#include "TripCompleted.h"

class DriverArrival : public QDialog
{
	Q_OBJECT

public:
	DriverArrival(QWidget *parent = Q_NULLPTR);
	~DriverArrival();

private:
	Ui::DriverArrival ui;

private slots:
	void on_acceptButton_clicked();
};

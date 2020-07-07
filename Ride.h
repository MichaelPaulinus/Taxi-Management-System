#pragma once

#include <QDialog>
#include "ui_Ride.h"
#include <QtSql>
#include <QSqlDatabase> // means to add a database
#include <QSqlQuery> // means of executing SQL queries
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QPixmap>
#include <QIcon>
#include "TaxiCoZa.h"
#include "DriverArrival.h"

class Ride : public QDialog
{
	Q_OBJECT

public:
	Ride(QWidget *parent = Q_NULLPTR);
	~Ride();

private:
	Ui::Ride ui;

private slots:
	void on_confirmButton_clicked();
	void on_carxButton_clicked();
	void on_carxlButton_clicked();
};

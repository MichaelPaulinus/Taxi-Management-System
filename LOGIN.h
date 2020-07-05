#pragma once

#include <QDialog>
#include "ui_Register.h"
#include <QtSql>
#include <QSqlDatabase> // means to add a database
#include <QSqlQuery> // means of executing SQL queries
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include "TaxiCoZa.h"
#include "ui_LOGIN.h"

class LOGIN : public QDialog
{
	Q_OBJECT

public:
	LOGIN(QWidget *parent = Q_NULLPTR);
	~LOGIN();

private:
	Ui::LOGIN ui;

private slots:
	void on_RideButton_clicked();
};


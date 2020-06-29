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

class TaxiCoZa : public QWidget
{
	Q_OBJECT

public:
	TaxiCoZa(QWidget *parent = Q_NULLPTR);

private:
	Ui::TaxiCoZaClass ui;

private slots:
	void on_loginButton_clicked();
};

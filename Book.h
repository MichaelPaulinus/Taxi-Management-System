#pragma once

#include <QDialog>
#include <QMovie>
#include "ui_Book.h"
#include "Connection.h"
#include "Ride.h"

class Book : public QDialog
{
	Q_OBJECT

public:
	Book(QWidget *parent = Q_NULLPTR);
	void setGreetingLabel(QString);

private:
	Ui::Book ui;

private slots:
	void on_rideButton_clicked();
};

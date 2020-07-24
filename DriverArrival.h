#pragma once

#include <QDialog>
#include <QMovie>
#include "ui_DriverArrival.h"
#include <string>
#include "Connection.h"
#include "Driver.h"
#include "TripCompleted.h"


class DriverArrival : public QDialog
{
	Q_OBJECT

public:
	DriverArrival(QWidget *parent = Q_NULLPTR);
	~DriverArrival();
	void setDriverDetailsD(Driver);

private:
	Ui::DriverArrival ui;

private slots:
	void on_acceptButton_clicked();
};

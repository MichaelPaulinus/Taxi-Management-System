#pragma once
#include <QDialog>
#include "ui_Ride.h"
#include "Connection.h"
#include "Utility.h"
#include <QPixmap>
#include <QIcon>
#include "DriverArrival.h"

class Ride : public QDialog
{
	Q_OBJECT

public:
	Ride(QWidget *parent = Q_NULLPTR);
	bool carX;

private:
	Ui::Ride ui;

private slots:
	void on_confirmButton_clicked();
	void on_carxButton_clicked();
	void on_carxlButton_clicked();
	void on_comboBoxDestination_currentIndexChanged(const QString& arg1);
};

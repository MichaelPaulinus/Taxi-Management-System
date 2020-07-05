#pragma once

#include <QDialog>
#include "ui_Ride.h"

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
};

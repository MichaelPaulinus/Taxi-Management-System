#pragma once
#include <QDialog>
#include "ui_TripCompleted.h"
#include "Connection.h"
#include "Utility.h"

class TripCompleted : public QDialog
{
	Q_OBJECT

public:
	TripCompleted(QWidget *parent = Q_NULLPTR);
	float f,r;
	bool checker;
	void setDriverDetailsT(Driver);

private:
	Ui::TripCompleted ui;

private slots:
	void on_endButton_clicked();
};

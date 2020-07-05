#pragma once

#include <QDialog>
#include "ui_afterRide.h"

class afterRide : public QDialog
{
	Q_OBJECT

public:
	afterRide(QWidget *parent = Q_NULLPTR);
	~afterRide();

private:

	Ui::afterRide ui;

private slots:
	void on_acceptButton_clicked();
};

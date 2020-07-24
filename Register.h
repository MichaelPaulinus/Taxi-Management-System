#pragma once

#include <QDialog>
#include "ui_Register.h"
#include "Connection.h"
#include "Book.h"
#include "Rider.h"


class Register : public QDialog
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();

private:
	Ui::Register ui;

private slots:
	void on_registerButton_clicked();
};

#pragma once

#include <QDialog>
#include "ui_endoftrip.h"

class endoftrip : public QDialog
{
	Q_OBJECT

public:
	endoftrip(QWidget *parent = Q_NULLPTR);
	~endoftrip();

private:
	Ui::endoftrip ui;
private slots:
	void on_endButton_clicked();
};

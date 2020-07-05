#include "afterRide.h"
#include "endoftrip.h"

afterRide::afterRide(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

afterRide::~afterRide()
{
}

void afterRide::on_acceptButton_clicked(){
	endoftrip end;
	this->hide();
	end.setModal(true);
	end.exec();
};
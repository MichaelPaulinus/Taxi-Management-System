#include "Ride.h"
#include "afterRide.h"
Ride::Ride(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Ride::~Ride()
{

}

void Ride::on_confirmButton_clicked() {
	afterRide confrim;
	this->hide();
	confrim.setModal(true);
	confrim.exec();
};


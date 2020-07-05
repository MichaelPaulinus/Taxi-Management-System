#include "LOGIN.h"
#include "Ride.h"

LOGIN::LOGIN(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	


}

LOGIN::~LOGIN()
{
}

void LOGIN::on_RideButton_clicked() {
	Ride r1;

	this->hide();
	r1.setModal(true);
	r1.exec();

}
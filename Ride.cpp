#include "Ride.h"

Ride::Ride(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QPixmap pixmap("C:/Coding_Projects/C++/TaxiCoZa/Images/UberX.jpg");
	QIcon ButtonIcon(pixmap);
	ui.carxButton->setIcon(ButtonIcon);
	ui.carxButton->setIconSize(pixmap.rect().size());

	QPixmap pixmap2("C:/Coding_Projects/C++/TaxiCoZa/Images/UberXL.jpg");
	QIcon ButtonIcon2(pixmap2);
	ui.carxlButton->setIcon(ButtonIcon2);
	ui.carxlButton->setIconSize(pixmap2.rect().size());

	TaxiCoZa conn;

	if (conn.connOpen()) {
		ui.status->setText("Database Connected...");
	}
	else {
		ui.status->setText("Database Not Connected...");
	}
}

Ride::~Ride()
{
}

void Ride::on_confirmButton_clicked() {
	TaxiCoZa conn;
	conn.close();
	this->hide();
	DriverArrival d;
	d.setModal(true);
	d.exec();
}

void Ride::on_carxButton_clicked() {
	ui.priceLabel->setText("R25");
}

void Ride::on_carxlButton_clicked() {
	ui.priceLabel->setText("R32.30");
}

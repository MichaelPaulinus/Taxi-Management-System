#include "DriverArrival.h"

DriverArrival::DriverArrival(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QMovie* movie = new QMovie("C:/Coding_Projects/C++/TaxiCoZa/Images/Driver_Arriving.gif");
	ui.driverRoute->setMovie(movie);
	movie->start();


	TaxiCoZa conn;
	if (conn.connOpen()) {
		ui.status->setText("Database Connected...");
	}
	else {
		ui.status->setText("Database Not Connected...");
	}
}

DriverArrival::~DriverArrival()
{
}

void DriverArrival::on_acceptButton_clicked() {
	TaxiCoZa conn;
	conn.close();
	this->hide();
	TripCompleted t;
	t.setModal(true);
	t.exec();
}
#include "DriverArrival.h"

DriverArrival::DriverArrival(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QMovie* movie = new QMovie("C:/Coding_Projects/C++/TaxiCoZa/Images/Driver_Arriving.gif");
	ui.driverRoute->setMovie(movie);
	movie->start();

	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");

}

DriverArrival::~DriverArrival() {

}

void DriverArrival::on_acceptButton_clicked() {
	TripCompleted t;
	t.setDriverDetailsT(DriverObj);
	this->hide();
	t.exec();
}

void DriverArrival::setDriverDetailsD(Driver d) {
	ui.label->setText(QString::fromStdString(d.getName() + " is on his way!"));
	ui.driverName->setText("Driver Name: " + QString::fromStdString(d.getName()));
	ui.numPlate->setText("Number Plate: " + QString::fromStdString(d.getNumPlate()));
	std::string rating = std::to_string(d.getRating());
	ui.avgRating->setText("Average Rating: " + QString::fromStdString(rating));
	QPixmap pixmap(QString::fromStdString(d.getPicture()));
	ui.driverImage->setPixmap(pixmap.scaled(ui.driverImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	QPixmap pixmap2(QString::fromStdString(d.getVehicle()));
	ui.carImage->setPixmap(pixmap2.scaled(ui.carImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
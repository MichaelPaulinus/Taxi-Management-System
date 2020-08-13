#include "DriverArrival.h"

DriverArrival::DriverArrival(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//set background
	QPixmap bkgnd(":/Images/babyblue.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//setting the image of the driver arriving
	QMovie* movie = new QMovie(":Images/Driver_Arriving.gif");
	ui.driverRoute->setMovie(movie);
	movie->start();

	//checking the database status
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");

}

DriverArrival::~DriverArrival() {

}

void DriverArrival::on_acceptButton_clicked() {
	//bringing up the next GUI
	this->hide();
	TripCompleted t;
	t.setDriverDetailsT(DriverObj);
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
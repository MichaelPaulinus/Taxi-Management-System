#include "Book.h"
//3rd GUI

Book::Book(QWidget *parent)
	: QDialog(parent)
{	
	ui.setupUi(this);

	//set background
	QPixmap bkgnd(":/Images/babyblue.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//setting the image of the map
	QMovie* movie = new QMovie(":Images/Map.gif");
	ui.mapLabel->setMovie(movie);
	movie->start();

	//checking the database status
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");
}

void Book::on_rideButton_clicked() {

	//bringing up the next GUI
	this->hide();
	Ride r;
	r.exec();
}

void Book::setGreetingLabel(QString x) {
	//sets a custom greeting label for the rider
	ui.greetingLabel->setText(x);
}
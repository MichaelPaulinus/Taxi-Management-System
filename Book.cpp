#include "Book.h"


Book::Book(QWidget *parent)
	: QDialog(parent)
{	
	ui.setupUi(this);

	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");
	
	QMovie* movie = new QMovie("C:/Coding_Projects/C++/TaxiCoZa/Images/Map.gif");
	ui.mapLabel->setMovie(movie);
	movie->start();
}

Book::~Book() {

}

void Book::on_rideButton_clicked() {
	this->hide();
	Ride r;
	r.exec();
}

void Book::setGreetingLabel(QString x) {
	ui.greetingLabel->setStyleSheet("QLabel{font-size: 15px;font-family: Consolas;color: rgb(0, 0, 0);}");
	ui.greetingLabel->setText(x);
}
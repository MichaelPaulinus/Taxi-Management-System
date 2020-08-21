#include "TripCompleted.h"
//6th GUI

TripCompleted::TripCompleted(QWidget *parent)
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
	QMovie* movie = new QMovie(":Images/Trip-Completed-Cropped.gif");
	ui.mapLabel->setMovie(movie);
	movie->start();

	//checking the database status
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");
}

void TripCompleted::on_endButton_clicked() {
	checker = false;
	//checks whether a user has rated the trip
		if (ui.radioButton->isChecked()) {
			r = 1;
			checker = true;
		}
		else if (ui.radioButton_2->isChecked()) {
			r = 2;
			checker = true;
		}
		else if (ui.radioButton_3->isChecked()) {
			r = 3;
			checker = true;
		}
		else if (ui.radioButton_4->isChecked()) {
			r = 4;
			checker = true;
		}
		else if (ui.radioButton_5->isChecked()) {
			r = 5;
			checker = true;
		}

		if (checker == false) QMessageBox::critical(this, "Error", "Please rate the trip!");
		else
		{
			f = UtilityObj.calcRating(DriverObj, r);
			DriverObj.updateDatabase(f, money*0.8); //driver gets 80% of fee
			RiderObj.updateDatabase(money, 0);//rider is charged 100% of fee
			UtilityObj.tripsDetails(DriverObj, money, r, destination); //captures the full details of the trip
			conn.connClose(); //closes the database connection
			this->close();
			//end of program
		}
}

void TripCompleted::setDriverDetailsT(Driver d) {
	//used to display image & name of driver on this GUI
	QPixmap pixmap(QString::fromStdString(d.getPicture()));
	ui.imageofDriver->setPixmap(pixmap.scaled(ui.imageofDriver->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui.label_5->setText("Please Rate Your Trip with " + QString::fromStdString(d.getName()));
}
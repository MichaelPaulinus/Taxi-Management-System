#include "TripCompleted.h"

TripCompleted::TripCompleted(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");
}

TripCompleted::~TripCompleted()
{
}

void TripCompleted::on_endButton_clicked() {
	checker = false;

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

		if (checker == false) QMessageBox::critical(this, "Error", "Please Rate The Trip");
		else
		{
			f = UtilityObj.calcRating(DriverObj, r);
			DriverObj.updateDatabase(f, money);
			RiderObj.updateDatabase(money);
			UtilityObj.tripsDetails(DriverObj, money, r, destination);
			conn.connClose();
			this->close();
		}
}

void TripCompleted::setDriverDetailsT(Driver d) {
	QPixmap pixmap(QString::fromStdString(d.getPicture()));
	ui.imageofDriver->setPixmap(pixmap.scaled(ui.imageofDriver->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui.label_5->setText("Please Rate Your Trip with " + QString::fromStdString(d.getName()));
}
#include "Ride.h"
//4th GUI

Ride::Ride(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//set background
	QPixmap bkgnd(":/Images/babyblue.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//location drop down menu
	QSqlQueryModel* modal1 = new QSqlQueryModel();
	QSqlQuery *query1 = new QSqlQuery(conn.db);
	query1->prepare("SELECT address FROM locations WHERE addressID<2");
	query1->exec();
	modal1->setQuery(*query1);
	ui.comboBoxLocation->setModel(modal1);

	//destination drop down menu
	QSqlQueryModel* modal2 = new QSqlQueryModel();
	QSqlQuery* query2 = new QSqlQuery(conn.db);
	query2->prepare("SELECT address FROM locations WHERE addressID>1 ORDER BY address");
	query2->exec();
	modal2->setQuery(*query2);
	ui.comboBoxDestination->setModel(modal2);

	//image for TaxiX
	QPixmap pixmap(":/Images/UberX.jpg");
	QIcon ButtonIcon(pixmap);
	ui.carxButton->setIcon(ButtonIcon);
	ui.carxButton->setIconSize(pixmap.rect().size());

	//image for TaxiXL
	QPixmap pixmap2(":/Images/UberXL.jpg");
	QIcon ButtonIcon2(pixmap2);
	ui.carxlButton->setIcon(ButtonIcon2);
	ui.carxlButton->setIconSize(pixmap2.rect().size());

	//checking the database status
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database NOT Connected...");
}

void Ride::on_confirmButton_clicked() {
	if (money == 0) QMessageBox::critical(this, "Error", "Please select a car type!");

	else {
		//checks if rider has sufficient funds
		if (RiderObj.getAccount() > money) {
			//selecting a driver
			QSqlQuery query;
			if (carX == true) query.prepare("SELECT * FROM drivers WHERE vehicle='X' AND rating>3.5 ORDER BY RANDOM() LIMIT 1");
			else query.prepare("SELECT * FROM drivers WHERE vehicle='XL' AND rating>3.5 ORDER BY RANDOM() LIMIT 1");
			query.exec();
			query.first();

			//setting the drivers details from database to the DriverObj
			DriverObj.setDriverId(query.value(0).toInt());
			DriverObj.setName(query.value(1).toString().toStdString());
			DriverObj.setSurname(query.value(2).toString().toStdString());
			DriverObj.setEmail(query.value(3).toString().toStdString());
			DriverObj.setID(query.value(4).toString().toInt());
			DriverObj.setPnum(query.value(5).toString().toInt());
			DriverObj.setAccount(query.value(6).toString().toDouble());
			DriverObj.setNumPlate(query.value(7).toString().toStdString());
			DriverObj.setVehicle(carX);
			DriverObj.setNumofTrips(query.value(9).toString().toInt());
			DriverObj.setRating(query.value(10).toString().toFloat());
			DriverObj.setPicture(query.value(11).toString().toStdString());

			//bringing up the next GUI
			this->hide();
			DriverArrival d;
			d.setDriverDetailsD(DriverObj);
			d.exec();
		}
		else {
			QMessageBox::critical(this, "Error", "Insufficient Funds");
		}
	}
}

void Ride::on_carxButton_clicked() {
	//action if an TaxiX is chosen
	carX = true;
	money = UtilityObj.calcPrice(value, 0, "X");
	ui.priceLabel->setText("R" + QString::fromStdString(std::to_string(money)));
}

void Ride::on_carxlButton_clicked() {
	//action if TaxiXL is chosen
	carX = false;
	money = UtilityObj.calcPrice(value, 0, "XL");
	ui.priceLabel->setText("R" + QString::fromStdString(std::to_string(money)));
}

void Ride::on_comboBoxDestination_currentIndexChanged(const QString &arg1) {
	//action when the destination is chosen
	QString location = ui.comboBoxDestination->currentText();
	destination = location.toStdString();
	QSqlQuery query;
	query.prepare("SELECT value FROM locations WHERE address = '" + location + "'");
	query.exec();
	query.first();
	value = query.value(0).toFloat();
}
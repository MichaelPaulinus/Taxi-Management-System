#include "Register.h"
//2nd GUI

Register::Register(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//set background
	QPixmap bkgnd(":/Images/babyblue.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
	
	//checking the database status
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database Not Connected...");
}

void Register::on_registerButton_clicked() {
	//check if user has left a blank detail
	if (ui.nameEdit_2->text()=="" || ui.surnameEdit_2->text()=="" || ui.idEdit_2->text()=="" || ui.emailEdit_2->text()=="" || ui.pnumEdit_2->text()=="" || ui.passwordEdit_2->text()=="") {
		QMessageBox::warning(this, "Error", "Please enter all details!");
	}
	else {
		QSqlQuery query;
		QString emailChecker = ui.emailEdit_2->text();
		query.prepare("SELECT email FROM riders WHERE email='" + emailChecker + "' ");
		query.exec();
		query.first();
		QString emailChecker2 = query.value(0).toString();

		//check if user tries to sign-up with used email
		if (emailChecker != emailChecker2) {
			query.prepare("SELECT * FROM riders ORDER BY riderID DESC LIMIT 1");
			query.exec();
			query.first();

			//setting the new Riders details
			RiderObj.setRiderId(query.value(0).toInt() + 1);
			RiderObj.setName(ui.nameEdit_2->text().toStdString());
			RiderObj.setSurname(ui.surnameEdit_2->text().toStdString());
			RiderObj.setID(ui.idEdit_2->text().toInt());
			RiderObj.setEmail(ui.emailEdit_2->text().toStdString());
			RiderObj.setPnum(ui.pnumEdit_2->text().toInt());
			RiderObj.setPassword(ui.passwordEdit_2->text().toStdString());
			RiderObj.setNumofTrips(0);
			RiderObj.setAccount(1000);

			//uploading the new Riders details onto the database
			RiderObj.uploadData();

			QMessageBox::information(this, "Success", "Registration completed SUCCESSFULY!");

			//bringing up the next GUI
			this->hide();
			Book b;
			b.setGreetingLabel("Hello, " + QString::fromStdString(RiderObj.getName()));
			b.exec();
		}
		else {
			QMessageBox::critical(this, "Error", "Email already exists!");
		}
	}
}
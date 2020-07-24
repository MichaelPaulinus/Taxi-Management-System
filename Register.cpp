#include "Register.h"

Register::Register(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	if (conn.connOpen()) ui.status->setText("Database Connected...");
	else ui.status->setText("Database Not Connected...");
}

Register::~Register()
{
}

void Register::on_registerButton_clicked() {
	QSqlQuery query;
	query.prepare("SELECT * FROM riders ORDER BY riderID DESC LIMIT 1");
	query.exec();
	query.first();
	RiderObj.setRiderId(query.value(0).toInt() + 1);
	RiderObj.setName(ui.nameEdit_2->text().toStdString());
	RiderObj.setSurname(ui.surnameEdit_2->text().toStdString());
	RiderObj.setID(ui.idEdit_2->text().toInt());
	RiderObj.setEmail(ui.emailEdit_2->text().toStdString());
	RiderObj.setPnum(ui.pnumEdit_2->text().toInt());
	RiderObj.setPassword(ui.passwordEdit_2->text().toStdString());
	RiderObj.setNumofTrips(0);
	RiderObj.setAccount(10000);

	RiderObj.uploadData();

	QMessageBox::information(this, "Success", "Data saved successfuly!");
	this->hide();

	Book b;
	b.setGreetingLabel("Hello, " + QString::fromStdString(RiderObj.getName()));
	b.exec();
}
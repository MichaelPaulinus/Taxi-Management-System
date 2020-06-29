#include "TaxiCoZa.h"

TaxiCoZa::TaxiCoZa(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void TaxiCoZa::on_loginButton_clicked() {
	// store the data the user entered into varaibles
	QString emailInput = ui.emailEdit1->text();
	QString passwordInput = ui.passwordEdit1->text();

	// this is the setup for the database 
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("C:/Users/Michael/TaxiDB.db");

	if (db.open()) {
		QMessageBox::information(this, "Connection", "Database Connected Successfuly");
	}
	else {
		QMessageBox::information(this, "Not connected", "Database is not connected");
	}

	// queries to be written
	QSqlQuery query("C:/Users/Michael/TaxiDB.db");
	query.exec("SELECT name FROM riders WHERE surname = 'Mashabane'"); // incorrect query
	emailInput = query.value(0).toString();
	ui.emailLabel->setText(emailInput);

}

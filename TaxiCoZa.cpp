#include "TaxiCoZa.h"

TaxiCoZa::TaxiCoZa(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// checks if the database is connected or not
	if (connOpen()) {
		//QMessageBox::information(this, "Database Status", "Database Connected!");
		ui.statusofLogin->setText("Database Connected...");
	}
	else {
		//QMessageBox::information(this, "Database Status", "Database Not Connected!");
		ui.statusofLogin->setText("Database NOT Connected...");
	}
}

void TaxiCoZa::on_loginButton_clicked() {
// store the data the user entered into varaibles
	QString emailInput = ui.emailEdit1->text();
	QString passwordInput = ui.passwordEdit1->text();

	TaxiCoZa::connOpen();

	QSqlQuery query;

	query.prepare("SELECT * FROM riders WHERE email='" + emailInput + "' and password='" + passwordInput + "'");

	if (query.exec()) {
		int count = 0;

		while (query.next()) {
			count++;
		}
		// scenario for the correct password
		if (count == 1) {
			QMessageBox::information(this, "Success", "CORRECT PASSWORD ENTERED!!!");
			TaxiCoZa::connClose();
			// before opening new window, close connection
		}
		// scenario for a duplicate
		else if (count > 1) {
			QMessageBox::critical(this, "Error", "DUPLICATE");
		}
		// scenario for incorrect password
		else{
			QMessageBox::critical(this, "Error", "INCORRECT EMAIL OR PASSWORD ENTERED!!!");
		}
	}

}

void TaxiCoZa::on_signupButton_clicked()
{
	TaxiCoZa::connClose();
	this->hide();
	Register reg;
	reg.setModal(true);
	reg.exec();
}

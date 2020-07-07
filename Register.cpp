#include "Register.h"

Register::Register(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	TaxiCoZa conn;
	if (conn.connOpen()) {
		ui.statusofRegister->setText("Database Connected...");
	}
	else {
		ui.statusofRegister->setText("Database Not Connected...");
	}

}

Register::~Register()
{
}

void Register::on_registerButton_clicked() {
	TaxiCoZa conn;

	// store the data the user entered into varaibles
	QString nameInput = ui.nameEdit_2->text();
	QString surnameInput = ui.surnameEdit_2->text();
	QString idInput = ui.idEdit_2->text();
	QString emailInput = ui.emailEdit_2->text();
	QString pNumInput = ui.pnumEdit_2->text();
	QString passwordInput = ui.passwordEdit_2->text();

	conn.connOpen();

	QSqlQuery query;
	query.prepare("INSERT INTO riders(name, surname, email, password, id, pNum) VALUES (?, ?, ?, ?, ?, ?)");
	query.addBindValue(nameInput);
	query.addBindValue(surnameInput);
	query.addBindValue(emailInput);
	query.addBindValue(passwordInput);
	query.addBindValue(idInput);
	query.addBindValue(pNumInput);

	// if the query executes
	if (query.exec()) {
		QMessageBox::information(this, "Success", "Data saved successfuly!");
		this->hide();
		conn.connClose();
		Book b;
		b.setModal(true);
		b.exec();
	}
	else {
		QMessageBox::critical(this, "Error", query.lastError().text());
	}
}
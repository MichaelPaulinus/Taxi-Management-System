#include "Rider.h"
#include <string>

Rider RiderObj;

void Rider::setRiderId(int riderid) {
	this->riderid = riderid;
}

void Rider::updateAccount(double money) {
	account -= money;
}

void Rider::updateDatabase(float m) {
	setAccount(RiderObj.getAccount() - m);
	setNumofTrips(RiderObj.getNumofTrips() + 1);
	QString riderid = QString::number(RiderObj.getRiderId());
	QString numofTrips = QString::number(RiderObj.getNumofTrips());
	QString account = QString::number(RiderObj.getAccount());
	QSqlQuery query;
	query.prepare("UPDATE riders SET account='"+account+"', numofTrips='" + numofTrips + "' WHERE riderID='" + riderid + "'");
	query.exec();
}

Rider::Rider() {
	std::string name = "Not Specified";
	std::string surname = "Not Specified";
	std::string email = "Not Specified";
	int id = 0;
	int pNum = 0;
	double account = 10000;
	int numofTrips = 0;
}

Rider::Rider(std::string name, std::string surname, std::string email, int id, int pNum) {
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
	this->pNum = pNum;
	double account = 10000;
	int numofTrips = 0;
}

void Rider::setPassword(std::string password) {
	this->password = password;
}

std::string Rider::getPassword() {
	return password;
}

int Rider::getRiderId() {
	return riderid;
}

void Rider::uploadData() {
	QSqlQuery query;
	query.prepare("INSERT INTO riders(name, surname, email, password, id, pNum, numofTrips, account) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
	query.addBindValue(QString::fromStdString(getName()));
	query.addBindValue(QString::fromStdString(getSurname()));
	query.addBindValue(QString::fromStdString(getEmail()));
	query.addBindValue(QString::fromStdString(getPassword()));
	query.addBindValue(QString::number(getID()));
	query.addBindValue(QString::number(getPnum()));
	query.addBindValue(QString::number(getNumofTrips()));
	query.addBindValue(QString::number(getAccount()));
	query.exec();
}
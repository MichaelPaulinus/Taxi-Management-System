#include "Rider.h"
#include <string>

Rider RiderObj;

	//constructors
Rider::Rider() {
	this->name = "NULL";
	this->surname = "NULL";
	this->email = "NULL";
	this->password = "NULL";
	this->riderid = NULL;
	this->id = NULL;
	this->pNum = NULL;
	this->account = 1000;
	this->numofTrips = NULL;	
}

	//general methods
void Rider::updateAccount(double money) {
	account -= money;
}

void Rider::updateDatabase(float m, float n) {
	updateAccount(m);
	setNumofTrips(RiderObj.getNumofTrips() + 1);
	QString riderid = QString::number(RiderObj.getRiderId());
	QString numofTrips = QString::number(RiderObj.getNumofTrips());
	QString account = QString::number(RiderObj.getAccount());
	QSqlQuery query;
	query.prepare("UPDATE riders SET account='"+account+"', numofTrips='" + numofTrips + "' WHERE riderID='" + riderid + "'");
	query.exec();
}

void Rider::uploadData() { //only used in Register GUI
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

	//set methods
void Rider::setRiderId(int riderid) {
	this->riderid = riderid;
}

void Rider::setPassword(std::string password) {
	this->password = password;
}

	//get methods
std::string Rider::getPassword() {
	return password;
}

int Rider::getRiderId() {
	return riderid;
}
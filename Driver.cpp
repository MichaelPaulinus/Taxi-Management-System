#include <string>
#include "Driver.h"

Driver DriverObj;

// set methods
void Driver::updateAccount(double money) {
	account += money;
}

void Driver::setDriverId(int driverid) {
	this->driverid = driverid;
}

void Driver::setPicture(std::string picture) {
	this->picture = picture;
}

void Driver::setRating(float rating) {
	this->rating = rating;
}

void Driver::setNumPlate(std::string numPlate) {
	this->numPlate = numPlate;
}

void Driver::setVehicle(bool x) {
	if (x == true) this->vehicle = "C:/Coding_Projects/C++/TaxiCoZa/Images/carX.jpg";
	else this->vehicle = "C:/Coding_Projects/C++/TaxiCoZa/Images/carXL.jpg";
}

// get methods
std::string Driver::getNumPlate() {
	return numPlate;
}

std::string Driver::getPicture() {
	return this->picture;
}

float Driver::getRating() {
	return rating;
}

int Driver::getDriverId() {
	return driverid;
}

std::string Driver::getVehicle() {
	return vehicle;
}

void Driver::updateDatabase(float r, float m) {
	setAccount(DriverObj.getAccount() + m);
	setNumofTrips(DriverObj.getNumofTrips() + 1);
	setRating(r);
	QString account = QString::number(DriverObj.getAccount());
	QString driverid = QString::number(DriverObj.getDriverId());
	QString numofTrips = QString::number(DriverObj.getNumofTrips());
	QString rating = QString::number(r);
	QSqlQuery query;
	query.prepare("UPDATE drivers SET account='"+account+"', numofTrips='" + numofTrips + "', rating = '"+rating+"' WHERE driverID='" + driverid + "'");
	query.exec();
}

Driver::Driver() {
	std::string name = "Not Specified";
	std::string surname = "Not Specified";
	std::string email = "Not Specified";
	int id = 0;
	int pNum = 0;
	double account = 0;
	int numofTrips = 0;
}

Driver::Driver(std::string name, std::string surname, std::string email, int id, int pNum) {
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
	this->pNum = pNum;
	account = 0;
	numofTrips = 0;
}
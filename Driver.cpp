#include <string>
#include "Driver.h"

Driver DriverObj;

	//constructors
Driver::Driver() {
	this->name = "NULL";
	this->surname = "NULL";
	this->email = "NULL";
	this->picture = "NULL";
	this->vehicle = "NULL";
	this->driverid = NULL;
	this->id = NULL;
	this->pNum = NULL;
	this->account = NULL;
	this->numofTrips = NULL;
	this->rating = NULL;
}

	//general methods
void Driver::updateAccount(double money) {
	account += money;
}

void Driver::updateDatabase(float r, float m) {
	updateAccount(m);
	setNumofTrips(DriverObj.getNumofTrips() + 1);
	setRating(r);
	QString account = QString::number(DriverObj.getAccount());
	QString driverid = QString::number(DriverObj.getDriverId());
	QString numofTrips = QString::number(DriverObj.getNumofTrips());
	QString rating = QString::number(r);
	QSqlQuery query;
	query.prepare("UPDATE drivers SET account='" + account + "', numofTrips='" + numofTrips + "', rating = '" + rating + "' WHERE driverID='" + driverid + "'");
	query.exec();
}
	
	//set methods
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
	if (x == true) this->vehicle = ":/Images/carX.jpg";
	else this->vehicle = ":/Images/carXL.jpg";
}

	//get methods
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

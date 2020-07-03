#include <string>
#include "Driver.h"

int Driver::driverid = 1;

void Driver::updateAccount(double money) {
	account += money;
}
Driver::Driver() {
	driverid++;
	std::string name = "Not Specified";
	std::string surname = "Not Specified";
	std::string email = "Not Specified";
	int id = 0;
	int pNum = 0;
	bool active = true;
	double account = 0;
	int numofTrips = 0;
}

Driver::Driver(std::string name, std::string surname, std::string email, int id, int pNum, bool active) {
	driverid++;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
	this->pNum = pNum;
	this->active = active;
	account = 0;
	numofTrips = 0;
}
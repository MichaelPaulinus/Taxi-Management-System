#include "Rider.h"
#include <string>

int Rider::riderid = 1;

void Rider::updateAccount(double money) {
	account -= money;
}

Rider::Rider() {
	riderid++;
	std::string name = "Not Specified";
	std::string surname = "Not Specified";
	std::string email = "Not Specified";
	int id = 0;
	int pNum = 0;
	bool active = true;
	double account = 0;
	int numofTrips = 0;
}

Rider::Rider(std::string name, std::string surname, std::string email, int id, int pNum, bool active) {
	riderid++;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
	this->pNum = pNum;
	this->active = active;
	double account = 0;
	int numofTrips = 0;
}
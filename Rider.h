#pragma once
#include <string>
#include "Person.h"
#include "TaxiCoZa.h"

class Rider :public Person
{
public:
	int riderid;
	int numofTrips;
	std::string password;

	// methods
	void updateAccount(double money);
	void uploadData();
	void setPassword(std::string);
	void setRiderId(int);
	std::string getPassword();
	int getRiderId();
	void updateDatabase(float);

	// constructors
	Rider();
	Rider(std::string, std::string, std::string, int, int);
};

extern Rider RiderObj;
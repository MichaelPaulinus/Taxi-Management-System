#pragma once
#include <string>
#include "Person.h"
#include "TaxiCoZa.h"

class Rider :public Person
{
public:
	int riderid;
	std::string password;

	//general methods
	virtual void updateAccount(double money);
	virtual void updateDatabase(float, float);
	void uploadData();

	//set methods
	void setPassword(std::string);
	void setRiderId(int);

	//get methods
	std::string getPassword();
	int getRiderId();
	
	//constructors
	Rider();
};

extern Rider RiderObj;
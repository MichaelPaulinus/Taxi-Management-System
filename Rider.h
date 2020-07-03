#pragma once
#include <string>
#include "Person.h"

class Rider :public Person
{

public:
	static int riderid;
	int numofTrips;
	bool active;
	std::string password;
	double account;

	// methods
	void updateAccount(double money);

	// constructors
	Rider();
	Rider(std::string, std::string, std::string, int, int, bool);
};


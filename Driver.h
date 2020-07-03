#pragma once
#include <iostream>
#include <string>
#include "Person.h"

class Driver :private Person {

public:
	static int driverid;
	int numofTrips;
	float rating;
	double account;
	bool active;
	std::string vehicle;

	//methods
	void updateAccount(double money);

	Driver();
	Driver(std::string, std::string, std::string, int, int, bool);
};


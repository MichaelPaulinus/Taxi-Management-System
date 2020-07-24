#pragma once
#include <string>
#include "Person.h"
#include "Connection.h"

class Driver :public Person {
public:
	int driverid;
	int numofTrips;
	float rating;
	double account;
	std::string vehicle;
	std::string picture;
	std::string numPlate;

	// set methods
	void updateAccount(double money);
	void setDriverId(int);
	void setNumPlate(std::string);
	void setPicture(std::string);
	void setRating(float);
	void setVehicle(bool);
	void updateDatabase(float, float);

	// get methods
	std::string getPicture();
	std::string getNumPlate();
	float getRating();
	int getDriverId();
	std::string getVehicle();

	Driver();
	Driver(std::string, std::string, std::string, int, int);
};

extern Driver DriverObj;
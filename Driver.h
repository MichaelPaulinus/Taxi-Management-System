#pragma once
#include <string>
#include "Person.h"
#include "Connection.h"

class Driver :public Person {
public:
	int driverid;
	float rating;
	std::string vehicle;
	std::string picture;
	std::string numPlate;

	//general methods
	virtual void updateAccount(double money);
	virtual void updateDatabase(float, float);

	// set methods
	void setDriverId(int);
	void setNumPlate(std::string);
	void setPicture(std::string);
	void setRating(float);
	void setVehicle(bool);
	

	// get methods
	std::string getPicture();
	std::string getNumPlate();
	float getRating();
	int getDriverId();
	std::string getVehicle();

	Driver();
};

extern Driver DriverObj;
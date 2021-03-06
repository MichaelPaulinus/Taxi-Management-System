#pragma once
#include <string>

class Person
{
protected:
	std::string name;
	std::string surname;
	std::string email;
	int pNum;
	int id;
	double account;
	int numofTrips;

public:
	//general methods
	virtual void updateAccount(double) = 0;
	virtual void updateDatabase(float, float) = 0;

	//set methods
	void setName(std::string);
	void setSurname(std::string);
	void setEmail(std::string);
	void setID(int);
	void setPnum(int);
	void setAccount(double);
	void setNumofTrips(int);
	
	//get methods
	std::string getName();
	std::string getSurname();
	std::string getEmail();
	int getID();
	int getPnum();
	double getAccount();
	int getNumofTrips();

	// constrcutors
	Person();
};


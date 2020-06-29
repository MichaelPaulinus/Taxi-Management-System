#pragma once
#include <string>

class Person
{
public:
	float radius;

protected:
	std::string name;
	std::string email;
	int pNum;
	int id;

public:
	// set methods
	void setName(std::string);
	void setEmail(std::string);
	void setID(int);
	void setNum(int);
	void setRadius(float);

	// get methods
	std::string getName();
	std::string getEmail();
	int getID();
	int getNum();
	float getRadius();

	// constrcutors
	Person();
	Person(std::string, std::string, int, int);
	//~Person(); // destructor
};


#include "Person.h"
#include <string>

Person::Person() {
	std::string name = "Not Specified";
	std::string email = "Not Specified";
	int id = 0;
	int pNum = 0;
	float radius = 0;
}

Person::Person(std::string name, std::string surname, std::string email, int id, int pNum) {
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
	this->pNum = pNum;
	float radius = 0;
}

// set methods
void Person::setName(std::string name) {
	this->name = name;
}

void Person::setSurname(std::string surname) {
	this->surname = surname;
}

void Person::setEmail(std::string email) {
	this->email = email;
}

void Person::setID(int id) {
	this->id = id;
}

void Person::setNum(int pNum) {
	this->pNum = pNum;
}

void Person::setRadius(float radius) {
	this->radius = radius;
}

// get methods
std::string Person::getName() {
	return name;
}

std::string Person::getSurname() {
	return surname;
}

std::string Person::getEmail() {
	return email;
}

int Person::getID() {
	return id;
}

int Person::getNum() {
	return pNum;
}

float Person::getRadius() {
	return radius;
}
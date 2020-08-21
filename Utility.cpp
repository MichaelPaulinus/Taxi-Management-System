#include "Utility.h"

Utility UtilityObj;

std::string destination;

int money;

float value;

int Utility::calcPrice(float a, float b, std::string x) {
	if (x == "X") return (a - b) * 7; //determines pproce based on the size of taxi chosen
	else return (a - b) * 9.25;
}

float Utility::calcRating(Driver d, float f) {
	return (d.getRating() + f) / 2; //calculates the drivers average rating
}

void Utility::tripsDetails(Driver d, float p, float r2, std::string d2) {
	QSqlQuery query;
	query.prepare("INSERT INTO trips(driverID, riderID, location, destination, price, rating) VALUES (?, ?, ?, ?, ?, ?)");
	query.addBindValue(QString::number(d.getDriverId()));
	query.addBindValue(QString::number(RiderObj.getRiderId()));
	query.addBindValue("University of KwaZulu-Natal");
	query.addBindValue(QString::fromStdString(d2));
	query.addBindValue(QString::number(p));
	query.addBindValue(QString::number(r2));
	query.exec();
}
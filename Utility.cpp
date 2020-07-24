#include "Utility.h"

Utility UtilityObj;

std::string destination;

float money;

float value;


float Utility::calcPrice(float a, float b, std::string x) {
	if (x == "X") return (a - b) * 7.5;
	else return (a - b) * 9.75;
}

float Utility::calcRating(Driver d, float f) {
	return (d.getRating() + f) / 2;
}

void Utility::tripsDetails(Driver d, float p, float r2, std::string d2) {
	QSqlQuery query;
	query.prepare("INSERT INTO trips(driverID, named, riderID, namer,location, destination, price, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
	query.addBindValue(QString::number(d.getDriverId()));
	query.addBindValue(QString::fromStdString(d.getName()));
	query.addBindValue(QString::number(RiderObj.getRiderId()));
	query.addBindValue(QString::fromStdString(RiderObj.getName()));
	query.addBindValue("University of KwaZulu-Natal");
	query.addBindValue(QString::fromStdString(d2));
	query.addBindValue(QString::number(p));
	query.addBindValue(QString::number(r2));
	query.exec();
}
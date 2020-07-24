#pragma once
#include <string>
#include "Driver.h"
#include "Rider.h"

class Utility
{
public:
	float calcPrice(float, float, std::string);
	float calcRating(Driver, float);
	void tripsDetails(Driver,float, float, std::string);
};

extern Utility UtilityObj;

extern std::string destination;

extern float money;

extern float value;

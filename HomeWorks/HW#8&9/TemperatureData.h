#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

#include <string>

struct TemperatureData {
	//data members
	std::string id;
	int year;
	int month;
	double temperature;

	//default Constructor
	TemperatureData();
	//Parametrized Constructor
	TemperatureData(std::string id, int year, int month, double temperature);
	//Destructor
	virtual ~TemperatureData();
	//Overloading operator to check if one set of data is less than the other
	//according to the given conditions
	bool operator<(const TemperatureData& b);
};

#endif

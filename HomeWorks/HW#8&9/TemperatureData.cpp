#include "TemperatureData.h"
using namespace std;

//Default constructor
//set everything to null or zero
TemperatureData::TemperatureData() 
{
	id = "";
	year = 0;
	month = 0;
	temperature = 0;
}

//parametrized constructor
TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) 
{
	//set all the data members
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;
}

//Destructor
TemperatureData::~TemperatureData() {}

//overloaded operator <
bool TemperatureData::operator<(const TemperatureData& b) {
	
	//compare two strings id
	//if the first char that is not same in both, is smaller in the first one
	//then it will return a negative number
	if(id.compare(b.id) < 0)
		return true;
	//if they are both same
	else if(id.compare(b.id) == 0)
	{
		//check the year
		if(year < b.year)
			return true;
		//if they are same
		else if(year == b.year)
		{
			//check month	
			if(month < b.month)
				return true;
			//if they are same
			else if(month == b.month)
			{
				//check the temperature
				if(temperature <= b.temperature)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}


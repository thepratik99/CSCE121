#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

//constant variable to check the validity of different data members of class TemperatureData
const int CURRENT_YEAR = 2018;
const int OLDEST_YEAR = 1800;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const double MIN_TEMPERATURE = -50.0;
const double MAX_TEMPERATURE = 50.0;
const double SPECIAL_TEMPERATURE = -99.99;
const string CALC_AVERAGE = "AVG";
const string CALC_MODE = "MODE";

void TemperatureDatabase::loadData(const string& filename) {

	//open the file name "filename"
	ifstream inFile{filename};

	//if the file does not exist, give an error message and terminate the program
	if(!inFile)
	{
		cout << "Error: Could not find or open a file." << endl;
		return;
	}

	//make an output file
	ofstream outFile{"result.dat"};

	//string to hold one line of the file
	string inputString;

	//iterate through the file
	while(getline(inFile, inputString))
	{
		//to hold the values before inserting the object of class TemperatureData in the LinkedList
		string id;
		int year;
		int month;
		double temperature;

		//make a stringstream of the string "inputString"
		istringstream ss(inputString);

		//get the id, it does not need any validation checks
		ss >> id;

		//if the bit after id is good for year
		if(ss >> year)
		{
			//if year is in the given range
			if(year >= OLDEST_YEAR && year <= CURRENT_YEAR)
			{
				//if the bit after year is goof for month
				if(ss >> month)
				{
					//if month is in the range
					if(month >= MIN_MONTH && month <= MAX_MONTH)
					{
						//if the bit after month is good foe temperature
						if(ss >> temperature)
						{
							//if temperature is in the range
							//then call the insert function
							if((temperature >= MIN_TEMPERATURE && temperature <= MAX_TEMPERATURE) || (temperature - SPECIAL_TEMPERATURE) < 0.0001)
								records.insert(id, year, month, temperature);
							else
								cout << "Error: Invalid temperature " << temperature << endl;
						}
						else
							cout << "Error: Other invalid input" << endl;
					}
					else
						cout << "Error: Invalid month " << month << endl;
				}
				else
					cout << "Error: Other invalid input" << endl;
			}
			else
				cout << "Error: Invalid year " << year << endl;
		}
		else
			cout << "Error: Other invalid input" << endl;
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	
	//open the file name "filename"
	ifstream inFile{filename};

	//if the file does not exist, give an error message and terminate the program
	if(!inFile)
	{
		cout << "Error: Could not find or open a file." << endl;
		return;
	}

	//making a file to write the output
	ofstream outFile{"result.dat"};

	//string to hold one line of the file
	string inputString;

	//iterate through the file
	while(getline(inFile, inputString))
	{
		//variables to hold values in each line of the file
		string location;
		string query;
		int startYear;
		int endYear;

		//make a stringstream of the string "inputString"
		istringstream ss(inputString);

		//get the id, it does not need any validations
		ss >> location;

		//if the bit after id is good for query
		if(ss >> query)
		{
			//we cna only perform two types of queries
			if(query == CALC_MODE || query == CALC_AVERAGE || !isalpha(query.at(0)))
			{
				//if the next two bits after query are good for starting and ending year
				if(ss >> startYear >> endYear)
				{
					//if years are in the given range and starting year has to smaller than ending year
					if(startYear >= OLDEST_YEAR && startYear <= CURRENT_YEAR
						&& endYear >= OLDEST_YEAR && endYear <= CURRENT_YEAR
						&& startYear <= endYear)
					{
						//get the head of the linkedlist
						Node* temp = records.getHead();

						//to calculate the AVG query
						double totalTemp = 0;
						int counterForAverage = 0;

						//to calculate the MODE query
						vector<vector<int>> mode;
						bool locationNotFound = true;

						//iterate through the LinkedList
						while(temp)
						{
							//if the current node have the right values need to perform the query
							if(temp->data.id == location
								&& temp->data.year >= startYear
								&& temp->data.year <= endYear
								&& !((temp->data.temperature - SPECIAL_TEMPERATURE) < 0.0001))
							{
								//flag the notFound bool to false
								locationNotFound = false;

								//if the query type is AVG
								if(query == CALC_AVERAGE)
								{
									//add the temperature of the current node into totalTemp
									totalTemp += temp->data.temperature;
									//increment the counter
									++counterForAverage;
								}
								//then the query is MODE
								else
								{
									bool doesNotExistYet = true;

									//round the temperature of the current node
									int roundedTemp = round(temp->data.temperature);

									//iterate throught the vector mode
									//check if this temperature exists or not
									//if it does then increment the counter of it
									//and set the doesNotExist boolean to false
									for(int i = 0; i < mode.size(); ++i)
									{
										if(roundedTemp == mode.at(i).at(0))
										{
											++mode.at(i).at(1);
											doesNotExistYet = false;
										}
									}

									//if it is not in the vector yet
									//then make a new entry in the vector
									if(doesNotExistYet)
									{
										vector<int> toInsert;
										toInsert.push_back(roundedTemp);
										toInsert.push_back(1);
										mode.push_back(toInsert);
									}
								}
							}
							temp = temp->next;
						}

						//if the given location does not match to any node in the list
						if(locationNotFound)
							outFile << location << " " << startYear << " " << endYear << " " << query << " unknown" << endl;

						else
						{
							//if the query is AVG
							//divide the total by its counter to get the average
							if(query == CALC_AVERAGE)
								outFile << location << " " << startYear << " " << endYear << " " << query << " " << (totalTemp / counterForAverage) << endl;

							//if the query is MODE
							//sort the vector so that desired value is at the bottom of the vector
							//then print the lat element of the vector
							else
							{
								int tempSwap;
								int repSwap;
															
								for(int i = 0; i < mode.size(); ++i)
								{
									for(int j = 0; j < i; ++j)
									{
										if(mode.at(j).at(1) > mode.at(j+1).at(1)
											|| (mode.at(j).at(1) == mode.at(j+1).at(1) && mode.at(j).at(0) > mode.at(j+1).at(0)))
										{
											tempSwap = mode.at(j).at(0);
											repSwap = mode.at(j).at(1);
											mode.at(j).at(0) = mode.at(j+1).at(0);
											mode.at(j).at(1) = mode.at(j+1).at(1);
											mode.at(j+1).at(0) = tempSwap;
											mode.at(j+1).at(1) = repSwap;
										}
									}
								}

								outFile << location << " " << startYear << " " << endYear << " " << query << " " << mode.at(mode.size()-1).at(0) << endl;
							}
						}
					}	
					else
						cout << "Error: Invalid range " << startYear << "-" << endYear << endl;
				}
				else
					cout << "Error: Other invalid query" << endl;
			}
			else
				cout << "Error: Unsupported query " << query << endl;
		}
		else
			cout << "Error: Other invalid query" << endl;
	}
}
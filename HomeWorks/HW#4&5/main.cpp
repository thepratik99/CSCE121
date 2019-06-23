#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
#include <cmath>
#include "functions.h"

using namespace std;

//function to validate rows and columns
bool IntegerValidation(double& value)
{
	if(!(value - static_cast<int>(value) <= 0.0001) || value <= 0)
	{
		cout << "Error: Only Integers" << endl;
		return false;
	}
	return true;
}

int main()
{
	//const int arrays to store the rgb values to get Red and Green color
	const int toColorRed[3] = {252, 25, 63};
	const int toColorGreen[3] = {31, 253, 13};

	double rows = 0;
	double columns = 0;

	//getting input for columns
	cout << "Enter number of columns: ";
	cin >> columns;

	//running an input validation
	bool check = IntegerValidation(columns);

	if(!check)
		return 1;

	//getting input for rows
	cout << "Enter number of rows: ";
	cin >> rows;
	
	//running an input validation
	check = IntegerValidation(rows);

	if(!check)
		return 1;

	//getting input for the filename
	string fileName;
	cout << "Enter name of file: ";
	cin >> fileName;

	//opening the file
	ifstream inFile;
	inFile.open(fileName);

	//vector to store the topographic data
	vector<vector<int>> data(static_cast<int>(rows));

	//initialize to maximum and minimum values possible
	double tempValue;
	int min_val = INT_MAX; 
	int max_val = INT_MIN;
		
	//reading data from the file and storing into a 2D vector	
	for(int i = 0; i < static_cast<int>(rows); ++i)
	{
		for(int j = 0; j < static_cast<int>(columns); ++j)
		{
			if(!(inFile >> tempValue))
			{
				cout << "Error: error" << endl;
				return 1;
			}

			//finding min and max in the data
			if(static_cast<int>(tempValue) < min_val)
				min_val = static_cast<int>(tempValue);

			if(static_cast<int>(tempValue) > max_val)
				max_val = static_cast<int>(tempValue);
					
			//push the values in the data
			data.at(i).push_back(static_cast<int>(tempValue));
		}
	}	
	
	//if the file still has more data then that is an error
	if(inFile >> tempValue)
	{
		cout << "Error: Recieved lesser or more data than expected." << endl;
		return -1;
	}

	//vectors to store Red, Green and Blue values
	vector<vector<int>> Red(static_cast<int>(rows));
	vector<vector<int>> Green(static_cast<int>(rows));
	vector<vector<int>> Blue(static_cast<int>(rows));

	double value;
	
	//calculating rgb values for the grey shade and storing them into the vectors.
	for(int i = 0; i < static_cast<int>(rows); ++i)
	{
		for(int j = 0; j < static_cast<int>(columns); ++j)
		{
			if(max_val == min_val)
				value=0;
			else
				value = (double)((data.at(i).at(j) - min_val)) * 255 / (max_val - min_val);
			
				Red.at(i).push_back(round(value));
				Green.at(i).push_back(round(value));
				Blue.at(i).push_back(round(value));
		}
	}

	//an array to store the cahnge in the elevation from each row.
	int elevationChanges[data.size()];
	int tempDistance = 0;
	
	//call the function on each raw and store the elevation change in to the array
	for(int i = 0; i < data.size(); ++i)
	{
		tempDistance = colorPath(data, Red, Green, Blue, toColorRed[0], toColorRed[1], toColorRed[2], i);
		elevationChanges[i] = tempDistance;
	}

	//initialize the minChange as the first element of the array
	int minElevationChange = elevationChanges[0];
	int minRow = 0;
	
	//iterate through the loop to find the minChange an then store the index of that value in minRow
	for(int i = 0; i < data.size(); ++i)
	{
		if(elevationChanges[i] < minElevationChange)
		{
			minElevationChange = elevationChanges[i];
			minRow = i;
		}
	}

	//call the colorPath again to apply Green color to the shortest change
	minElevationChange = colorPath(data, Red, Green, Blue, toColorGreen[0], toColorGreen[1], toColorGreen[2], minRow);
	
	//open an output file
	ofstream outFile;
	outFile.open(fileName + ".ppm");
	
	//if file does not open give an error message
	if(!outFile.is_open())
	{
		cerr << "Error: Could not open file." << endl;
		return -1;
	}

	//write the output file in the given format
	outFile << "P3" << endl;
	outFile << rows << " " << columns << endl;
	outFile << 255 << endl;

	for(int i = 0; i < static_cast<int>(rows); i++)
	{
		for(int j = 0; j < static_cast<int>(columns); j++)
		{
			outFile << Red.at(i).at(j) << " " << Green.at(i).at(j) << " " << Blue.at(i).at(j) << " ";
		}
			outFile << endl;
		
	}

	return 0;
}



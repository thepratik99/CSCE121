#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <float.h>

using namespace std;

int main(int argv, char* argc[])
{
    if (argv != 2) {
        cerr << "Usage: ./a.out filename.dat" << endl;
        return 1;
    }

    string inputFile = argc[1];
    cout << "File with input data : " << inputFile << endl;

    //vector to store xValues, yValues and the index of the point, which is closest to the given point of index
    vector<int> xValues;
    vector<int> yValues;
    vector<int> finalIndex;

    //file streams, one for input and other for output
    ifstream inFile;
    ofstream outFile;

    //openening the inputFile given in the argument
    inFile.open(inputFile);
    //creating a new file named output.txt to write the output
    outFile.open("output.txt");

    //if inFile is not in the same directory or does not exist
    //then print an error msg and terminate the program with return value of 1
    if(!inFile.is_open())
    {
    	cout << "Error......" ;
    	return 1;
    }

    //string bothValue will store each line of the inputFile
    string bothValues;
    //token will store a substring of bothValues string separated by a comma
    string token;
    //below strings will hold values of token
    string xValueString;
    string yValueString;

    //int xValue and yValue will hold the ints read from file and will use them to use into the vector
    int xValue = 0;
    int yValue = 0;

    //the bool will decide weather the token will be stored in xValueString or yValueString
    //initialize it to true because we know that the first value in each line is a xValue
    bool isXValue = true;

    //the loop will read each line of the file into bothValues untill the end of file
    while(!inFile.eof())
    {
    	//reading in bothValues
    	inFile >> bothValues;

    	//stringstream ss is a stream of bothValue
    	//using stringstream because to separate a string by ',' we need to pass a stringstream as parameter instead of a string
    	istringstream ss((string) bothValues);

    	//this will separate the stream into two tokens separated by ','
    	while(getline(ss, token, ','))
    	{
    		//if isXValue is true we will store the token into xValueString
    		if(isXValue)
    		{
    			xValueString = token;

    			//set the bool to false so the next token can be stored as a yValueString
    			isXValue = false;
    			//convert string to an int
    			xValue = stoi(xValueString);
    			//add the int into the vector
    			xValues.push_back(xValue);
    		}
    		//after token is assigned to the xValue, the next token should go to yValue
    		else
    		{
    			//assign the yValueString to token
    			yValueString = token;
    			//set bool to true so the next token can be stored as a xValueString
    			isXValue = true;
    			//convert string to an int
    			yValue = stoi(yValueString);
    			//add the int into the vector
    			yValues.push_back(yValue);
    		}
    		
    	}    	
    }

    //iterarte throught the loop to find the minimum distance to the given point
    for(int i = 0; i < xValues.size(); ++i)
    {
    	//initialize the double to its possible maximum value, because we need the minimum
    	double minDistance = DBL_MAX;
    	int indexOfMin = 0;

    	for(int j = 0; j < xValues.size(); ++j)
    	{
    		//skip one interation of the loop if both counters are the same, meaning we would calculate the distace from a point to the same point
    		//the distance will be zero in this case, so we will skip it
    		if(i == j)
    			continue;
    		else
    		{
    			//tempDistance will store the distance from point.at(i) to point(j)
    			double tempDistance = sqrt(pow((xValues.at(i) - xValues.at(j)), 2) + pow((yValues.at(i) - yValues.at(j)), 2));
    			//if the tempDistace is less the minDistance than update the minDistance and update the indexOfMin to j
    			if(tempDistance < minDistance)
    			{
    				minDistance = tempDistance;
    				indexOfMin = j;
    			}
    		}
    	}

    	//push the indexOfMin to the vector
    	finalIndex.push_back(indexOfMin);
    }

    //write xValue, yValue and the index of the point to which the point is nearest into outFile stream
    for(int i = 0; i < xValues.size(); ++i)
    {
    	outFile << xValues.at(i) << "," << yValues.at(i) << "," << finalIndex.at(i) << endl;
    }

    //close both input and output files
    inFile.close();
    outFile.close();

    return 0;
}
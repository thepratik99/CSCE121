#include<vector>
#include<cmath>
#include<iostream>
#include "functions.h"

using namespace std;

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
	int color_b, int start_row) {
	//initialize the distance to zero
	int dist = 0;

	//an integer to keep track of the row
	int currentRow = start_row;

	//booleans to decide whether to increase the currentRow or decrese or keep the same in the next iteration
	bool incrementRow = false;
	bool decrementRow = false;

	//color all the data points in the first column as Red
	r.at(currentRow).at(0) = color_r;
	g.at(currentRow).at(0) = color_g;
	b.at(currentRow).at(0) = color_b;

	for(int i = 0; i < heightMap.at(start_row).size(); ++i)
	{
		//set both bool values to false at the start of each iteration
		incrementRow = false;
		decrementRow = false;

		//if in the last column then don't do anything
		if(i == (heightMap.at(start_row).size() - 1))
			break;

		else
		{
			//if the current position is in the first row then we have only two option to go, either straight or down
			if(currentRow == 0)
			{
				//compare the change in the elevation for available options and then decide
				if(abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1)) <= abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow + 1).at(i+1)))
				{
					//if the change is less in the forward direction then change the color of that cell
					r.at(currentRow).at(i+1) = color_r;
					g.at(currentRow).at(i+1) = color_g;
					b.at(currentRow).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1));
				}
				else
				{
					//if the change is less in the south east direction then change the color of that cell
					//and flag up the bool to increase the value of the row at the end of the iteration
					incrementRow = true;
					r.at(currentRow+1).at(i+1) = color_r;
					g.at(currentRow+1).at(i+1) = color_g;
					b.at(currentRow+1).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow+1).at(i+1));
				}
			}

			//if the current position is in the last row then we have only two option to go, either straight or up
			else if(currentRow == heightMap.size() - 1)
			{
				//compare the change in the elevation for available options and then decide
				if(abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1)) <= abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow-1).at(i+1)))
				{
					//if the change is less in the forward direction then change the color of that cell
					r.at(currentRow).at(i+1) = color_r;
					g.at(currentRow).at(i+1) = color_g;
					b.at(currentRow).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1));
				}
				else
				{
					//if the change is less in the north east direction then change the color of that cell
					//and flag up the bool to decrease the value of the row at the end of the iteration
					decrementRow = true;
					r.at(currentRow-1).at(i+1) = color_r;
					g.at(currentRow-1).at(i+1) = color_g;
					b.at(currentRow-1).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow-1).at(i+1));
				}
			}

			else
			{
				//compare the change in the elevation for available options and then decide
				if((abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1)) <= abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow+1).at(i+1)) 
						&& abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1)) <= abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow-1).at(i+1))))
				{
					//if the change is less in the forward direction then change the color of that cell
					r.at(currentRow).at(i+1) = color_r;
					g.at(currentRow).at(i+1) = color_g;
					b.at(currentRow).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1));
				}
				else if(abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow+1).at(i+1)) < abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow).at(i+1)) 
						&& abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow+1).at(i+1)) <= abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow-1).at(i+1)))
				{
					//if the change is less in the south east direction then change the color of that cell
					//and flag up the bool to increase the value of the row at the end of the iteration
					incrementRow = true;
					r.at(currentRow+1).at(i+1) = color_r;
					g.at(currentRow+1).at(i+1) = color_g;
					b.at(currentRow+1).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow+1).at(i+1));	
				}
				else
				{
					//if the change is less in the north east direction then change the color of that cell
					//and flag up the bool to decrease the value of the row at the end of the iteration
					decrementRow = true;
					r.at(currentRow-1).at(i+1) = color_r;
					g.at(currentRow-1).at(i+1) = color_g;
					b.at(currentRow-1).at(i+1) = color_b;

					//add the distance
					dist += abs(heightMap.at(currentRow).at(i) - heightMap.at(currentRow-1).at(i+1));
				}
			}
		}

		//change the value of the currentRow according to the flags set
		if(incrementRow)
			currentRow++;
		else if(decrementRow)
			currentRow--;
		else
			;
	}

	return dist;
}

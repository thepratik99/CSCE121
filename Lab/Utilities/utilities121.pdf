//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                              UTILITIES 121                               //
//                             utilities121.cpp                             //
//                                                                          //
// Written By :                         Environment :                       //
// Date ......:                         Compiler ...:                       //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                #includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "utilities121.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <random>
#include <cstdlib>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//                           Function Definitions                           //
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
*                              void pause(void)                              *
*                                                                            *
*       Description ....: Delay the system so that the user can read what    *
*                         is written to standard output.                     *
*                                                                            *
*                                                                            *
* Written By : Michael R. Nowak         Environment : Mac OS X 10.10.5       *
* Date ......: 2017/10/01               Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
void pause(void)
{
    std::string temp;
    std::cout << std::endl << "[Press RETURN to continue]" << std::endl;
    std::getline(std::cin, temp);
}

/*****************************************************************************
*                            char upChar(char c)                             *
*                                                                            *
*       Description ....: Converts the char into a upper char                *
*                                                                            *
*                                                                            *
* Written By : Yusuf Ulla               Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
char upChar(char c)
{
	if ((c >= 97) && (c <= 122)) 
	{
    	c = c - 32;
    	return c;
  	}
  	else 
  	{
    	return c;
  	}
}

/*****************************************************************************
*                            char lowChar(char c)                            *
*                                                                            *
*       Description ....: Converts the char into a lower char                *
*                                                                            *
*                                                                            *
* Written By : Benjamin Tures           Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
char lowChar(char c)
{
	if ((c >= 65) && (c <= 90)) 
	{
    	c = c + 32;
    	return c;
  	}
  	else 
  	{
    	return c;
  	}

}

/*****************************************************************************
*                    std::string upperStr(std::string s)                     *
*                                                                            *
*       Description ....: converts each char of the string to upper alphabet *
*                                                                            *
*                                                                            *
* Written By : Pratik Patel             Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
string upperStr(string s)
{
	char temp;
	for(int i = 0; i < s.length(); ++i)
	{
		temp = s.at(i);
		s.at(i) = upChar(temp);
	}
	return s;
}

/*****************************************************************************
*                    std::string lowerStr(std::string s)                     *
*                                                                            *
*       Description ....: converts each char of the string to lower alphabet *
*                                                                            *
*                                                                            *
* Written By : Yusuf Ulla               Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
string lowerStr(string s)
{
	char temp;
	for(int i = 0; i < s.length(); ++i)
	{
		temp = s.at(i);
		s.at(i) = lowChar(temp);
	}
	return s;
}

/*****************************************************************************
*                         std::string tostr(int i)                           *
*                                                                            *
*       Description ....: Converts an int to string                          *
*                                                                            *
*                                                                            *
* Written By : Benjamin Tures           Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
string toStr(int n)
{

	stringstream ss;
	ss << n;
	string str = ss.str();

	return str;
}


/*****************************************************************************
*                        std::string tostr(double d)                         *
*                                                                            *
*       Description ....: Converts a double to a string                      *
*                                                                            *
*                                                                            *
* Written By : Pratik Patel             Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
string toStr(double n)
{

	stringstream ss;
	ss << n;
	string str = ss.str();

	return str;
}


/*****************************************************************************
*          int getInt(int low, int high, std::string const& prompt)          *
*                                                                            *
*       Description ....: Get an int input from the user and runs            *
*						  a input validation which also checks for the       *
*						  range provided by the user                         *
*                                                                            *
*                                                                            *
* Written By : Yusuf Ulla               Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
int getInt(int low, int high, std::string const& prompt)
{
	int num;

	cout << prompt ;
	cin >> num;

	while(!(num > low && num < high))
	{
		if(!(cin.good()) || num < low || num > high)
		{
			if(cin.bad())
			{
				throw runtime_error("stream corrupted");
			}
			else if(cin.eof())
			{
				throw runtime_error("unexpected eof");
			}
			else if(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Input is Invalid." << endl;
				cout << prompt;
				cin >> num;
			}
			else
			{
				cout << "Input is out of Range." << endl;
				cout << prompt ;
				cin >> num;
			}
		}
	}
	return num;
}

/*****************************************************************************
*            double getDouble(double low, double high, double tolerance,     *
*                                     double, std::string const& prompt)     *
*                                                                            *
*       Description ....: Get an double input from the user and runs         *
*						  a input validation which also checks for the       *
*						  range provided by the user                         *
*                                                                            *
*                                                                            *
* Written By : Benjamin Tures           Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
double getDouble(double low, double high, double tolerance, std::string const& prompt)
{
	double num;

	cout << prompt;
	cin >> num;

	while(!(num > (low - tolerance) && num < (high + tolerance)))
	{

		if(!(cin.good()) || num < (low - tolerance) || (high + tolerance))
		{
			if(cin.bad())
			{
				throw runtime_error("stream corrupted");
			}
			else if(cin.eof())
			{
				throw runtime_error("unexpected eof");
			}
			else if(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Input is Invalid." << endl;
				cout << prompt;
				cin >> num;
			}
			else
			{
				cout << "Input is out of Range." << endl;
				cout << prompt ;
				cin >> num;
			}
		}
	}
	return num;
}


/*****************************************************************************
*                        int randNo(int min, int max)                        *
*                                                                            *
*       Description ....:                                                    *
*                                                                            *
*                                                                            *
* Written By :                          Environment :                        *
* Date ......:                          Compiler ...:                        *
*****************************************************************************/


/*****************************************************************************
*                   double randDo(double min, double max)                    *
*                                                                            *
*       Description ....: .                                                  *
*                                                                            *
*                                                                            *
* Written By :                          Environment :                        *
* Date ......:                          Compiler ...:                        *
*****************************************************************************/


/*****************************************************************************
*                           void clearScreen(void)                           *
*                                                                            *
*       Description ....: clears the terminal's  							 *
*						  screen                       					     *
*                                                                            *
*                                                                            *
* Written By : Pratik Patel             Environment :                        *
* Date ......: 2018/10/03               Compiler ...:                        *
*****************************************************************************/
void clearScreen()
{
	system("CLS");
}
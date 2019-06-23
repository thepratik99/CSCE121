#include "functions.h"
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void printUsageInfo(char* fileName)
{
	cout << "Usage: " << fileName << " [-c] [-s] string ..." << endl;
	cout << "-c: turn on case sensitivity" << endl;
	cout << "-s: turn off ignoring spaces" << endl;
}

bool isPalindrome(char* checkString, bool caseSensitive, bool space)
{
	vector<char> check;
	bool result;

	for(int i = 0; i < strlen(checkString); ++i)
	{
		check.push_back(checkString[i]);
	}

	if(!space && !caseSensitive)
	{
		for(int i = 0; i < check.size(); ++i)
		{
			check.at(i) = tolower(check.at(i));
			if(check.at(i) < 97 || check.at(i) > 122)
				check.erase(check.begin() + i);
		}
		
	}

	else if(space && !caseSensitive)
	{
		for(int i = 0; i < check.size(); ++i)
		{
			check.at(i) = tolower(check.at(i));
			if(check.at(i) != 32 && (check.at(i) < 97 || check.at(i) > 122))
				check.erase(check.begin() + i);
		}
	}

	else if(!space && caseSensitive)
	{
		for(int i = 0; i < check.size(); ++i)
		{
			if(check.at(i) < 97 || check.at(i) > 122)
				check.erase(check.begin() + i);
		}
	}

	else if(space && caseSensitive)
	{
		for(int i = 0; i < check.size(); ++i)
		{
			if(check.at(i) != 32 && (check.at(i) < 97 || check.at(i) > 122))
				check.erase(check.begin() + i);
		}
	}

	string toCheck;

	for(int i = 0; i < check.size(); ++i)
	{
		toCheck += check.at(i);
	}

	result = isPalindromeR(toCheck);

	return result;

}

bool isPalindromeR(string checkString)
{
	int size = checkString.size();

	if(size <= 2)
	{
		if(size == 2 && checkString.at(0) == checkString.at(1))
			return true;
		else if(size == 1)
			return true;
		else 
			return false;
	}
	else 
	{
		if(checkString.at(0) == checkString.at(size - 1))
		{
			string newCheck = checkString.substr(1, size - 2);
			
			return isPalindromeR(newCheck);
		}
		else
			return false;
	}
	return true;
}
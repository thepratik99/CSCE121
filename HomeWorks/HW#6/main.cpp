#include "functions.h"
#include <string.h>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argv, char* argc[])
{

	if(argv < 2)
	{
		printUsageInfo(argc[0]);
	}

	bool caseSensitive = false;
	bool space = false;

	bool ispali;

	if(argc[1][0] == '-' && argv > 2)
	{
		for(int i = 1; i < strlen(argc[1]); ++i)
		{
			if(argc[1][i] == 'c' || argc[1][i] == 'C')
			{
				if(!caseSensitive)
					caseSensitive = true;
				else
					caseSensitive = false;
			}

			if(argc[1][i] == 's' || argc[1][i] == 'S')
			{
				if(!space)
					space = true;
				else
					space = false;
			}
			else if((argc[1][i] != 's' && argc[1][i] != 'S') && (argc[1][i] != 'c' && argc[1][i] != 'C'))
			{
				printUsageInfo(argc[0]);
				return 0;
			}
			else
				;
		}

		if(argv > 3 && argc[2][0] == '-')
		{
			for(int i = 1; i < strlen(argc[2]); ++i)
			{
				if(argc[2][i] == 'c' || argc[2][i] == 'C')
				{
					if(!caseSensitive)
						caseSensitive = true;
					else
						caseSensitive = false;
				}

				if(argc[2][i] == 's' || argc[2][i] == 'S')
				{
					if(!space)
						space = true;
					else
						space = false;
				}
				else if((argc[2][i] != 's' && argc[2][i] != 'S') && (argc[2][i] != 'c' && argc[2][i] != 'C'))
				{
					printUsageInfo(argc[0]);
					return 0;
				}
				else
					;
			}

			for(int i = 3; i < argv; ++i)
			{
				ispali = isPalindrome(argc[i], caseSensitive, space);
				if(ispali)
					cout << "\"" << argc[i] << "\"" << " is a palindrome." << endl;
				else
					cout << "\"" << argc[i] << "\"" << " is not a palindrome." << endl;
			}
		}

		else if(argc[2][0] != '-')
		{
			for(int i = 2; i < argv; ++i)
			{
				ispali = isPalindrome(argc[i], caseSensitive, space);
				if(ispali)
					cout << "\"" << argc[i] << "\"" << " is a palindrome." << endl;
				else
					cout << "\"" << argc[i] << "\"" << " is not a palindrome." << endl;
			}
		}

		else
			printUsageInfo(argc[0]);

	}
	else if(argc[1][0] != '-')
	{
		for(int i = 1; i < argv; ++i)
		{
			ispali = isPalindrome(argc[i], caseSensitive, space);
			if(ispali)
				cout << "\"" << argc[i] << "\"" << " is a palindrome." << endl;
			else
				cout << "\"" << argc[i] << "\"" << " is not a palindrome." << endl;
		}
	}
	else
		printUsageInfo(argc[0]);

	return 0;
}
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	int decimalValue;
	int base;
	
	vector<int> list;

	cout << "Enter a decimal value : " ;
	cin >> decimalValue;

	cout << "Enter a base (2-16) : ";
	cin >> base;

	while(base > 16)
	{
		cin.ignore();
		cout << "Enter a base (2-16) : ";
		cin >> base;
	}

	cout << endl;

	int division = decimalValue / base;
	int remainder = decimalValue % base;
	list.push_back(remainder);

	//cout << division << endl;

	while(division > 0)
	{
		remainder = division % base;
		division = division / base;
		list.push_back(remainder);
		//cout << division << endl;
	}

	for(int i = 0; i < list.size() / 2; i++)
	{
		int temp = list.at(i);
		list.at(i) = list.at(list.size() - 1 - i);
		list.at(list.size() - 1 - i) = temp;
	}

	cout << "Base-10 value : " << decimalValue << endl;

	char hex = 'A';

	cout << "Base-" << base << " value : "; 

	for(int i = 0; i < list.size(); i++)
	{
		if(list.at(i) >= 10)
		{
			hex = 'A' - 10 + list.at(i);
			cout << hex;
		}
		else
			cout << list.at(i) ;
	}
	
	cout << endl;

	if(list.size() == 1 && list.at(0) == 0)
	{
		cout << "Digits required : 0" << endl;
	}


	cout << "Digits required : " << list.size() << endl;

	return 0;
}
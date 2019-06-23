#include <iostream>
#include <string>

using namespace std;

int main()
{
	//declaring variables for user's name, birthyear and height
	string firstName;
	string lastName;

	int birthYear;
	int age;

	double heightFeet;
	double heightInch;
	double heightCM;
	double growthRate;

	//propting user for name, birthyear and height
	cout << "First name: " ;
	getline(cin, firstName);

	cout << "Last name: " ;
	getline(cin, lastName);

	cout << "Birth year: " ;
	cin >> birthYear;

	cout << "Height in feet (do not include inches): " ;
	cin >> heightFeet;

	cout << "Height in inches (do not include feet): " ;
	cin >> heightInch;

	//calculating user's age
	age = 2018 - birthYear;

	//converting heigth to cms
	heightCM = (heightFeet * 12 * 2.54) + (heightInch * 2.54);

	//checking for the denominator
	//if the denominator is 0, then terminate the program with a discription
	if(age == 0)
		cout << "\nYou are just born this year. Please try next year." << endl;

	else
	{
		//calculate the growthRate, assuming that height at birth is 51 cm
		growthRate = (heightCM - 51) / age;

		//printing Useer's Name and Growthrate
		cout << "\nHello " << firstName << " " << lastName << "." << endl;
		cout << "You are " << age << " years old in 2018." << endl;
		cout << "Your height is " << heightCM << " cm." << endl;
		cout << "You grew an average of " << growthRate << " cm per year (assuming you were 51 cm at birth)." << endl;
	}

	return 0;
}				//end of main
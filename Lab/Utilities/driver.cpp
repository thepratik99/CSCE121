#include <iostream>
#include <vector>
#include <string>
#include "utilities121.h"
using namespace std;

int main ()
{

    cout << "Write code in driver.cpp to test your functions..." << endl;

    //making a string of an int and a double datatype
    string integerString = toStr(5);
    string doubleString = toStr(5.6);

    //printing the results
    cout << integerString << endl << doubleString << endl;

    //converting lower char to upper and vice-versa
    char lowerToUpper = upChar('a');
    char upperToLower = lowChar('A');

    //printing the results
    cout << lowerToUpper << endl << upperToLower << endl;

    //pausing the execution of the program until user presses the key [RETURN]
    pause();

    //converting the lower string to upper and vice-versa
    string lowerToUpperStr = upperStr("hey");
    string upperToLowerStr = lowerStr("HEY");

    //printing the results
    cout << lowerToUpperStr << endl << upperToLowerStr << endl;

    //a string to prompt the user to enter a number
    string prompt = "Please Enter a number : ";

    //call the function to validate the userInput
    int a = getInt(3, 10, prompt);

    //printing the result
    cout << "You have entered the number - " << a << endl;

    //call the function to validate the userInput
    double b = getDouble(9.8, 20, 0.00001, prompt);

    //printing the result
    cout << "You have entered the number - " << b << endl;
    
    return 0;
}
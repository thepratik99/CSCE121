#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>

using namespace std;

//function to convert an integer into a vector of integer
vector<int> FromIntegerToVector(int code)
{
    //vector to store the integer
    //the integer will be stored in reverse as the name also suggests
    vector<int> reverseDigits;

    //divide and modulo by 10 will to get an individual digit
    //then push it into the vector
    int singleDigit = code % 10;
    int remainder = code / 10;
    reverseDigits.push_back(singleDigit);
    
    //when the remainder will be less than one there should be no more digits in the integer
    //that's why break the loop
    while(remainder >= 1)
    {
        singleDigit = remainder % 10;
        remainder /= 10;
        reverseDigits.push_back(singleDigit);
    }

    //return the vector
    return reverseDigits;
}

//function to print the vector in the given format
void PrintVector(vector<int> v1)
{
    cout << v1.at(0);

    //iterate through the loop from index 1 to the last index
    for(int i = 1; i < v1.size(); ++i)
    {
        cout << "-" << v1.at(i);
    }
}

//function to add zeros in front of the number
//if the entered number has less digits than expected
void AppedLeadingZero(int numOfDigits, const vector<int>& v1, vector<int>& realNumberOrGuess)
{
    //add as many as the difference
    for(int i = 0; i < (numOfDigits - v1.size()); ++i)
    {
        realNumberOrGuess.push_back(0);
    }
}

//function to reverse a given vector
void ReverseVector(const vector<int>& reversedVector, vector<int>& realNumberOrGuess)
{
    //iterate through the reversed vector which has digits of the given integer
    //and push them in a new vector
    for(int i = reversedVector.size() - 1; i > -1; --i)
    {
        realNumberOrGuess.push_back(reversedVector.at(i));
    }
}

//function checks for enetred guess and calcaulates the value of bulls and cows for each guess
void CalculateBullsAndCows(bool& sameDigits, bool&moreDigits, int& bulls, int& cows, vector<int>& guess, int guessedNum, int numOfDigitsToShow, const vector<int>& realNumber)
{
    vector<int> reverseGuess;

    //make a vector of the given guessedNum
    reverseGuess = FromIntegerToVector(guessedNum);

    //if the vector's size is more than expected
    //print an error message and flag up the boolean vaiable 'moreDigits'
    if(reverseGuess.size() > numOfDigitsToShow)
    {
        cout << "You can only enter " << numOfDigitsToShow << " digits." << endl;
        moreDigits = true;
    }

    //check if the vector's size is less than expected
    else if(reverseGuess.size() < numOfDigitsToShow)
    {
        //if so then, append zeros in front of the vector
        AppedLeadingZero(numOfDigitsToShow, reverseGuess, guess);   
    }
    
    //if moreDigits flag is not up then execute the block of code        
    if(!moreDigits)
    {   
        //reverse the given vector
        ReverseVector(reverseGuess, guess);

        //iterarate throught the reveresed vector
        for(int i = 0; i < guess.size(); ++i)
        {
            for(int j = 0; j < guess.size(); ++j)
            {
                //if there are same digits at different indexes, then break the inner loop
                //also flag up the boolean variable 'sameDigits' 
                if(i != j && guess.at(i) == guess.at(j))
                {
                    cout << "Each number must be different." << endl;
                    sameDigits = true;
                    break;
                }
            }

            //if there are same digits then break the outer loop as well
            if(sameDigits)
                break;
            //otherwise iterate through two vectors, the realNumber and the guess to calculate 
            //values of variables bulls and cows
            else
            {
                for(int j = 0; j < realNumber.size(); ++j)
                {
                    //if a digit in the vector guess matches up with a digit in the vector in realNumber
                    //and if they both are at same index in respective vectors
                    //then increse the value of bulls by 1
                    if(i == j && guess.at(i) == realNumber.at(j))
                        bulls++;
                    //if a digit does exist in both vectors
                    //but not at the same index
                    //then increse the value of variable cows
                    else if(guess.at(i) == realNumber.at(j))
                        cows++;
                }
            }
        }
    }
}

//function to generate a random number of given length
vector<int> GenerateNumber(int size)
{
    vector<int> singleDigits;
    vector<int> realNumber;

    //make a vector which will store the digits, 0 to 9
    for(int i = 0; i < 10; i++)
    {
        singleDigits.push_back(i);
    }

    //fill the realNumber with random digits
    for(int i = 0; i < size; i++)
    {
        //generate random digits using the function rand()
        int randomIndex = rand() % (singleDigits.size() - 1);
        //push the digit into the vector
        realNumber.push_back(singleDigits.at(randomIndex));
        //erase that digit from the vector which stores digits , 0 to 9
        //so that there will be no duplicates generated in the realNumber vector
        singleDigits.erase(singleDigits.begin() + randomIndex, singleDigits.begin() + randomIndex + 1);
    }

    //print the generated number
    cout << "Number to guess: ";

    PrintVector(realNumber);

    cout << endl;

    //return the generated number as a vector od ints
    return realNumber;
}

//function to print the calcualted values of bulls and cows
void PrintBullsAndCows(bool moreDigits, bool sameDigits, int bulls, int cows, int numOfDigits, const vector<int>& guess)
{
    //if the guess does not contain same digits and is not longer than expected
    //then print the values of bulls and cows for each guessed Number
    if(!sameDigits && !moreDigits && bulls != numOfDigits)
    {
        cout << bulls << " bulls" << endl;
        cout << cows << " cows" << endl;
    }

    //if the user guesses the right number
    //meaning that the value of bulls is equal to the value of numOfDigts
    //then print the realNumber as well as the value of bulls and do not print the value of cows
    if(!sameDigits && bulls == numOfDigits && !moreDigits)
    {
        cout << bulls << " bulls... ";
        PrintVector(guess);
        cout << " is correct!" << endl;
    }
}

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir

    //declare two constant variables to hold the minimum and maximum length of the number
    const int MIN_DIGITS = 3;
    const int MAX_DIGITS = 5;

    vector<int> realNumber;

    //int to store the number of digits
    int numOfDigits = 0;

    cout << "Enter number of digits in code (3, 4 or 5): " ;
    cin >> numOfDigits;

    //if the number is not between the min and max value
    //or it is not zero
    //then prompt an error message and ask for another input value
    while((numOfDigits < MIN_DIGITS || numOfDigits > MAX_DIGITS) && numOfDigits != 0)
    {
        cout << "Enter number of digits in code (3, 4 or 5): " ;
        cin >> numOfDigits;
    }

    //integers to hold the value of bulls and cows and the guess itself for each guess
    int bulls = 0;
    int cows = 0;
    int guessedNum = 0;

    //bool variables to validate the entered guesses
    bool moreDigits = false;
    bool sameDigits = false;

    //0 works as an cheat code
    //it gives the user an ability to enter the code he wants and then guess it
    if(numOfDigits == 0)
    {
        vector<int> reverseDigits;
    	
        //to hold the code user wants to enter
        int code = 0;

        //prompt to user and store the code
    	cout << "Enter code: " ;
    	cin >> code;

        //convert the ineteger into a reverseDigits vector
    	reverseDigits = FromIntegerToVector(code);

        //ask user how many digits he wants in the code
    	int numOfDigitsToShow = reverseDigits.size();

    	cout << "Enter number of digits in code: " ;
    	cin >> numOfDigitsToShow;

        //if the user wnats more digits in the code than he entered
        //then append the code with zeros to make both equal
        if(numOfDigitsToShow > reverseDigits.size())
        {
            AppedLeadingZero(numOfDigitsToShow, reverseDigits, realNumber);
        }

        //reverse the vector and store the result in the realNumber
        ReverseVector(reverseDigits, realNumber);

        //prin the code on the screen
        cout << "Number to guess: " ;
        PrintVector(realNumber);
        cout << endl;

        //ask the user to guess the number until he guesses the correct code
    	while(bulls != numOfDigitsToShow)
    	{
            //to hold the value of the guess
            vector<int> guess;
    		
            //set the value of bulls and cows 0, for every guess
    		bulls = 0;
    		cows = 0;

            //set the booleans to false for every guess
            sameDigits = false;
            moreDigits = false;

            //prompt to enter the guess
    		cout << "Enter Guess: ";
    		cin >> guessedNum;

            //calculate the value of bulls and cows
            //if the entered guess is valid, otherwise print an error message
            CalculateBullsAndCows(sameDigits, moreDigits, bulls, cows, guess, guessedNum, numOfDigitsToShow, realNumber);

            //print he value of bulls and cows for every guess
    		PrintBullsAndCows(moreDigits, sameDigits, bulls, cows, numOfDigitsToShow, guess);	
    	}
    }

    else
    {
        //generate a random number of 'numOfDigits' digits
        realNumber = GenerateNumber(numOfDigits);

        //ask the user to guess the number until he guesses the correct code
        while(bulls != numOfDigits)
        {
            //to hold the value of the guess
            vector<int> guess;

            //set the value of bulls and cows 0, for every guess
            bulls = 0;
            cows = 0;

            //set the booleans to false for every guess
            sameDigits = false;
            moreDigits = false;

            //prompt to enter the guess
            cout << "Enter Guess: ";
            cin >> guessedNum;

            //calculate the value of bulls and cows
            //if the entered guess is valid, otherwise print an error message
            CalculateBullsAndCows(sameDigits, moreDigits, bulls, cows, guess, guessedNum, numOfDigits, realNumber);

            //print he value of bulls and cows for every guess
            PrintBullsAndCows(moreDigits, sameDigits, bulls, cows, numOfDigits, guess);
        }
    }
    return 0;
}
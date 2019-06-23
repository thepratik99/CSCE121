#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//declaring variables for each co-efficients
	double a;
	double b;
	double c;

	//getting values and storing them into respective variables
	cin >> a;
	cin >> b;
	cin >> c;

	//if - else structure to display the equation correctly on the screen
	if(b < 0 && c < 0)
		cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
	else if(b < 0)
		cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
	else if(c < 0)
		cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
	else
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

	//nested if - else structure to get the right roots for each type of quadratic eqaution
	//first we will check that if the given equation is a qaudratic equation or not
	if(a==0 && b==0)
		//if a and b both are zero then that is not an equation at all.
		//thus just printing the below statement
		cout << "Unable to determine root(s)." << endl;

	else																					
	{
		//if only a is zero then the equation becomes a linear eqaution and only has one root
		if(a == 0)																			
		{
			//calculating that one root
			double r = (-c) / b;

			//printing the results
			cout << "x = " << r << endl;
		}
		//at this point it is clear that the equation is a quadratic equation
		else
		{
			//calculating the descriminator of the equation
			double descr = (b * b) - (4 * a * c);

			//if the descriminator is less than 0 than the equation has roots amde up of two parts. one is real, other is imaginary
			if(descr < 0)
			{
				//calculating the real part of the root
				double real = (-b) / (2 * a) ;
				//calculating the imaginary part of the root
				double img = sqrt(fabs(descr)) / (2 * a) ;

				//since the condition in the problem is to display the substraction first,
				//we need to check weather imaginary part of the root is negative or positive
				if(img < 0)
				{
					//if it is negative then we will print the plus sign first because (- * -) becomes positive
					cout << "x = " << real << " + " << fabs(img) << "i" << endl;
					cout << "x = " << real << " - " << fabs(img) << "i" << endl;
				}
				//if not then we will print in the regular given order
				else
				{
					cout << "x = " << real << " - " << fabs(img) << "i" << endl;
					cout << "x = " << real << " + " << fabs(img) << "i" << endl;
				}
			}

			//if the descriminator is zero, then the equation has two roots mathemetically, but both having the same value.
			//thus we will just display one root.
			else if(descr == 0)
			{
				//calculating the root
				double r = (-b) / (2 * a) ;

				//printing the root
				cout << "x = " << r << endl;
			}

			//here it is known that the equation has two real and different roots.
			else
			{
				//calculating both roots
				//calculate the substraction part first as asked in the prompt
				double r1 = ( (-b) - sqrt(descr)) / (2 * a) ;
				double r2 = ( (-b) + sqrt(descr)) / (2 * a) ;

				//printing the roots on the screen
				cout << "x = " << r1 << endl;
				cout << "x = " << r2 << endl;
			}
		}
		
	}         //end of the if-else structure

	return 0;
}			 //end of main
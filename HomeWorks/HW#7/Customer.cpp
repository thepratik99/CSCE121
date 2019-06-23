#include "Customer.h"
#include "Product.h"
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

//Constructor with defalt value for bool credit
Customer::Customer(int id, string name, bool credit = false)
{
	//if string arg is null, then throw an error
	if(name == "")
		throw runtime_error("Please enter name of the Customer");

	this->id = id;
	this->name = name;
	this->credit = credit;

	balance = 0;
}

//Mutator
void Customer::setName(string name)
{
	//if string arg is null, then throw an error
	if(name == "")
		throw runtime_error("Please enter name of the Customer");

	this->name = name;
}

//Helper function for takePayment
void Customer::processPayment(double amount)
{
	//if passed arg is not valid, then throw an error
	if(amount < 0.001)
		throw runtime_error("Please enter a valid integer");

	//increase the balance
	balance += amount;
}

//helper function for sellProduct
void Customer::processPurchase(double amount, Product product)
{
	//if passed arg is not valid, then throw an error
	if(amount < 0.001)
		throw runtime_error("Please enter a valid integer");

	//balance can go down, if the customer is allowed to
	if(credit)
	{
		balance -= amount;
		productsPurchased.push_back(product);
	}

	else
	{
		if(balance >= amount)
		{
			balance -= amount;
			productsPurchased.push_back(product);
		}
		//if balance goes down and customer is not allowed for credit then throw an error
		else
			throw runtime_error("Not enough balance");
	}
}

//helper function to operator overloading function
string Customer::getProductsPurchased() const
{
	string productDetails = "";

	//iterate through the vector and append each product's detail to the string
	for(int i = 0; i < productsPurchased.size(); ++i)
	{
		productDetails = productDetails + "Product Name: " + productsPurchased.at(i).getName() + "\n" + "Product ID: " + to_string(productsPurchased.at(i).getID()) + "\n\n" ;
	}

	return productDetails;
}

//operator << overloading , non-member function
stringstream& operator<<(stringstream& os, Customer const& customer)
{
	//call mutators to get the values and print them
	os << "Customer Name: " << customer.getName()
	   << "\nCustomer ID: " << customer.getID()
	   << "\nHas Credit: " << boolalpha << customer.getCredit()
	   << "\nBalance: " << customer.getBalance()
	   << "\nProducts Purchased --" << endl << endl
	   << customer.getProductsPurchased();

	return os;
}
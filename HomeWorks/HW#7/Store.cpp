#include "Product.h"
#include "Customer.h"
#include "Store.h"
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

//Constuctor with no arguments
Store::Store()
{
	name = "";
}

//Constructor's argument will update the name of the store object
Store::Store(string name)
{
	this->name = name;
}

//Mutator 
void Store::setName(string name)
{
	//if the argument is empty throw an error
	if(name == "")
		throw runtime_error("Please enter name of the Store");

	this->name = name;
}

//Add product to the products vector
void Store::addProduct(int productID, string productName)
{
	//iterate though products vector
	for(int i = 0; i < products.size(); ++i)
	{
		//if product already exists in the list, throw an error
		if(productID == products.at(i)->getID())
			throw runtime_error("Product already exists in the list.");
	}

	products.push_back(new Product(productID, productName));
}

//Accessor
Product& Store::getProduct(int productID)
{
	//iterate through customers vector
	for(int i = 0; i < products.size(); ++i)
	{
		//if product is in the list, return a pointer to it
		if(productID == products.at(i)->getID())
			return *products.at(i);
	}

	//or else throw an error
	throw runtime_error("Product does not exists in the list.");
}

//Add customer to the customers vector
void Store::addCustomer(int customerID, string customerName, bool credit = false)
{
	//iterate though customers vector
	for(int i = 0; i < customers.size(); ++i)
	{
		//if customer already exists in the list, throw an error
		if(customerID == customers.at(i)->getID())
			throw runtime_error("Customer already exists in the list.");
	}

	customers.push_back(new Customer(customerID, customerName, credit));
}

//Accessor
Customer& Store::getCustomer(int customerID)
{
	//iterate though customers vector
	for(int i = 0; i < customers.size(); ++i)
	{
		//if customer is in the list, return the pointer to it
		if(customerID == customers.at(i)->getID())
			return *customers.at(i);
	}

	//or else throw an error
	throw runtime_error("Customer does not exists in the list.");
}

//call addShipment mehtod after finding the right product object in the vector
void Store::takeShipment(int productID, int quantity, double cost)
{
	getProduct(productID).addShipment(quantity, cost);
}

//call processPayment mehtod after finding the right customer object in the vector
void Store::takePayment(int customerID, double amount)
{
	getCustomer(customerID).processPayment(amount);
}

//sell the product if no error is thrown
void Store::sellProduct(int customerID, int productID, int quantity)
{
	//calculate the amount<if possible>
	double amount = static_cast<double>(quantity) * getProduct(productID).getPrice();
	//call the reduceInventory method to keep the vector up to date
	getProduct(productID).reduceInventory(quantity);
	//call the processPurchase methos to complete the sell
	getCustomer(customerID).processPurchase(amount, getProduct(productID));
}

//Print the list of products in the store object
string Store::listProducts()
{
	string list = "";
	
	for(int i = 0; i < products.size(); ++i)
	{
        stringstream os;
        string s = (operator<<(os, getProduct(products.at(i)->getID()))).str() + "\n";
        list = list + s;
	}
	return list;
}

//Print the list of customers and products they have purchased
string Store::listCustomers()
{
	string list = "";

	for(int i = 0; i < customers.size(); ++i)
	{
		stringstream os;
		string s = (operator<<(os, getCustomer(customers.at(i)->getID()))).str() + "\n";
		list = list + s;
	}
	return list;
}

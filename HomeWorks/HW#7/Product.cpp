#include "Product.h"
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

//Constructor
Product::Product(int id, string name)
{
	//if string arg is null, then throw an error
	if(name == "")
		throw runtime_error("Please Enter a Product Name");

	this->id = id;
	this->name = name;

	inventory = 0;
	numSold = 0;
	totalPaid = 0;
	description = "";
}

//Mutator
void Product::setName(string name)
{
	//if string arg is null, then throw an error
	if(name == "")
		throw runtime_error("Please Enter a Product Name");

	this->name = name;
}

//helper function to takeShipment
void Product::addShipment(int shipmentQuantity, double shipmentCost)
{
	//if values are invalid, throw an error
	if(shipmentCost < 0.001 || shipmentQuantity < 0)
		throw runtime_error("Please Enter valid integers");

	//update the data members for Product object
	inventory += shipmentQuantity;
	totalPaid += shipmentCost;
}

//helper function to sellProduct
void Product::reduceInventory(int purchaseQuantity)
{
	//if the store does not have enough quantity, throw an error
	if((inventory - purchaseQuantity) < 0 || purchaseQuantity < 0)
		throw runtime_error("Please Enter valid integers");

	//update the data members for the Product object
	inventory -= purchaseQuantity;
	numSold += purchaseQuantity;
}

//Mutator
double Product::getPrice() const
{
	double price;

	//if the values of the data members of the Product obj are legit, then calculate the price
	if(totalPaid >= 0.001 && inventory >= 0 && numSold >= 0)
	{
		price = (totalPaid / static_cast<double>(inventory + numSold)) * 1.25;
		return price;
	}

	//or else throw an error
	throw runtime_error("Can not compute the price");
}

//operator << overloading , non-member function
stringstream& operator<<(stringstream& os, Product const& product)
{
	try
	{
		double price = product.getPrice();
	}
	//if price data member can not be calculated then print with "Unavailable"
	catch(runtime_error)
	{
		os << "Product Name: " << product.getName() 
	   	   << "\nProduct ID: " << product.getID()
	   	   << "\nDescription: " << product.getDescription()
	       << "\nInventory: " << product.getInventoryCount()
	       << "\nNumber Sold: " << product.getNumberSold()
	       << "\nTotal Paid: " << product.getTotalPaid()
	       << "\nPrice: Unavailable\n";

	    return os;
	}

	//or else call accessors and print the Product obj
	os << "Product Name: " << product.getName() 
   	   << "\nProduct ID: " << product.getID()
   	   << "\nDescription: " << product.getDescription()
       << "\nInventory: " << product.getInventoryCount()
       << "\nNumber Sold: " << product.getNumberSold()
       << "\nTotal Paid: " << product.getTotalPaid()
       << "\nPrice: " << product.getPrice() << "\n";

	return os;
}
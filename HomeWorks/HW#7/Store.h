#ifndef STORE_H
#define STORE_H 

#include "Product.h"
#include "Customer.h"
#include <string>
#include <vector>

class Store{

//public member functions
public:
	//Constructor
	Store();
	Store(std::string);

	//Accessors
	std::string getName() const { return name; }
	Product& getProduct(int);
	Customer& getCustomer(int);

	//Mutator
	void setName(std::string);
	
	void addProduct(int, std::string);
	void addCustomer(int, std::string, bool);
	void takeShipment(int, int, double);
	void takePayment(int, double);
	void sellProduct(int, int, int);
	std::string listProducts();
	std::string listCustomers();

//private data members
private:
	std::string name;
	std::vector<Product*> products;
	std::vector<Customer*> customers;
};

#endif

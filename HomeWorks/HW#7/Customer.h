#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Product.h"
#include <string>
#include <vector>

class Customer{

//public member functions
public:
	//Constructor
	Customer(int, std::string, bool);

	//Accessors
	int getID() const { return id; }
	std::string getName() const { return name; }
	bool getCredit() const { return credit; }
	double getBalance() const { return balance; }
	std::string getProductsPurchased() const;

	//Mutators
	void setName(std::string);
	void setCredit(bool hasCredit) { credit = hasCredit; }

	//To update data members
	void processPayment(double);
	void processPurchase(double, Product);

//private data members
private:
	int id;
	std::string name;
	bool credit;
	double balance;
    std::vector<Product> productsPurchased;

};

//non-member operator overloading function
std::stringstream& operator<<(std::stringstream&, Customer const&);

#endif

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product{

//member function
public:
	Product(int, std::string);

	//Accessors
	int getID() const { return id; }
	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
	int getNumberSold() const { return numSold; }
	int getInventoryCount() const { return inventory; }
	double getTotalPaid() const { return totalPaid; }
	double getPrice() const;

	//Mutators
	void setName(std::string);
	void setDescription(std::string description) { this->description = description; }

	//To update data members
	void addShipment(int, double);
	void reduceInventory(int);

//private data members
private:
	int id;
	int inventory;
	int numSold;
	std::string name;
	std::string description;
	double totalPaid;
};

//non-member operator overloading function
std::stringstream& operator<<(std::stringstream&, Product const&);

#endif

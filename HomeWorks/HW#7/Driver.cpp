#include "Store.h"
#include "Customer.h"
#include "Product.h"
#include <string.h>
#include <sstream>
#include <vector>
#include <iostream>


using namespace std;

int main()
{
	try{


	Store s = new Store();
	s.addProduct(123,"towel");
	//s.getProduct(123).setDescription("For drying.");

	//s.addProduct(234,"mask");
	//s.getProduct(234).setDescription("For hiding.");

	s.addCustomer(987,"Joe Blockhead",true);
	//s.addCustomer(789, "Jane Grooves");

	s.takeShipment(123,200,400);

	s.takePayment(987,600);

	s.sellProduct(987,123,10);

	string output = s.listProducts();

	cout << output;

	}

	catch(runtime_error& exc)
	{
		cout << "Exception caught: "<< exc.what() << endl;
	}

	return 0;
}
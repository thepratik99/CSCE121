#include "Employee.h"
#include <string>
#include <sstream>

using namespace std;

Employee::Employee()
{
	name = "";
}

Employee::Employee(string name)
{
	this->name = name;
}

ostream operator<<(ostream os, Employee e)
{
	os << e.to_str();
	return os;
}
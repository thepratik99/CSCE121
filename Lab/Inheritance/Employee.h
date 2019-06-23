#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee{

private:
	std::string name;
public:
	Employee();
	Employee(std::string);
	void set_name(std::string name) { this->name = name; }
	std::string get_name() const { return name; }
	virtual std::string to_str() = 0;

};

std::ostream operator<<(std::ostream os, std::string);

#endif
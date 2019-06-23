#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "SalariedEmployee.h" 

class Manager : public SalariedEmployee
{
public:
	Manager();
	Manager(std::string, double, double);
	double weekly_pay() const { return SalariedEmployee::weekly_pay() + weekly_bonus; }
	std::string to_str();
private:
	double weekly_bonus;
};

#endif
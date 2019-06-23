#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee();
	SalariedEmployee(std::string, double);
	double weekly_pay() const { return annual_salary/52; }
	std::string to_str();

private:
	double annual_salary;	
};

#endif
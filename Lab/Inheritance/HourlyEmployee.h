#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "Employee.h"

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee();
	HourlyEmployee(std::string, double);
	HourlyEmployee(std::string, double, double);
	void set_hours_worked(double hours_worked) { this->hours_worked = hours_worked; }
	double get_hours_worked() const { return hours_worked; }
	double get_hourly_wage() const { return hourly_wage; }
	double weekly_pay() const ;
	std::string to_str();

private:
	double hourly_wage;
	double hours_worked;
};

#endif
#include "HourlyEmployee.h"
#include "Employee.h"
#include <string>
#include <sstream>

using namespace std;

HourlyEmployee::HourlyEmployee()
	: Employee()
{
	hours_worked = 0;
	hourly_wage = 0;
}

HourlyEmployee::HourlyEmployee(string name, double hourly_wage)
	: Employee(name)
{
	this->hourly_wage = hourly_wage;
	hours_worked = 0;
}

HourlyEmployee::HourlyEmployee(string name, double hourly_wage, double hours_worked)
	: Employee(name)
{
	this->hourly_wage = hourly_wage;
	this->hours_worked = hours_worked;
}

double HourlyEmployee::weekly_pay() const
{
	if(hours_worked <= 40)
		return hours_worked * hourly_wage;
	else
		return (40*hourly_wage + (hours_worked-40)*hourly_wage*1.5);
}

string HourlyEmployee::to_str() 
{
	stringstream ss;
	ss << "Employee's Name: " << get_name() << "\nWeekly Pay: " << weekly_pay() << "\nHours Worked: " << get_hours_worked() << "\nHourly Wage: " << get_hourly_wage() << endl;

	return ss.str(); 
}
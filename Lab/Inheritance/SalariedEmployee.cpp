#include "SalariedEmployee.h"
#include "Employee.h"
#include <string>

using namespace std;

SalariedEmployee::SalariedEmployee()
	:Employee()
{
	annual_salary = 0;
}

SalariedEmployee::SalariedEmployee(string name, double annual_salary)
	: Employee(name)
{
	this->annual_salary = annual_salary;
}

string SalariedEmployee::to_str() 
{
	stringstream ss;
	ss << "Employee's Name: " << name << "\nWeekly Pay: " << weekly_pay() << "\nAnnual Salary: " << annual_salary << endl;

	return ss.str(); 
}
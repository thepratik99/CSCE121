#include "Manager.h"
#include "SalariedEmployee.h"
#include "Employee.h"
#include <string>

using namespace std;

Manager::Manager()
	: SalariedEmployee()
{
	weekly_bonus = 0;
}

Manager::Manager(string name, double annual_salary, double weekly_bonus)
	: SalariedEmployee(name, annual_salary)
{
	this->weekly_bonus = weekly_bonus;
}

string SalariedEmployee::to_str() 
{
	stringstream ss;
	ss << "Employee's Name: " << name << "\nWeekly Pay: " << weekly_pay() << "\nWeekly Bonus: " << weekly_bonus << "\nAnnual Salary: " << annual_salary << endl;

	return ss.str(); 
}
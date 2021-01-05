#include<iostream>
using namespace std;
//This program allows the user to input any number of months, and calculate
//the amount of backdated pay that is owed.
//This is linked intrinsically is Chapter2PP3

int main()
{
	double const pay_increase = 0.076;
	cout << "Please enter the previous year's salary: ";
	double previous_salary = 0.00;
	cin >> previous_salary;
	double new_salary = previous_salary + (previous_salary * pay_increase);
	double monthly_owed_salary = (new_salary/12) - (previous_salary/12);
	cout << "How many months of backdated pay are owed?\n";
	int months = 0;
	cin >> months;

	cout << "The old salary was " << previous_salary << endl;
	cout << "The new salary is " << new_salary << endl;
	cout << "The total amount of salary owed is " << monthly_owed_salary * months << endl;
}
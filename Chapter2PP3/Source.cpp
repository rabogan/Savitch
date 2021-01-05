#include<iostream>
using namespace std;

/*Program taking an input of an employee's salary from the previous year.
//Employees have won a retroactive pay increase of 7.6%
//This program uses the input to calculate:
1) The new salary
2) The new monthly salary
3) The amount of backdated pay that is owed to employees
*/

int main()
{
	const double pay_increase = 0.076;  //Expresses the pay increase using a const
	
	double previous_salary = 0;
	
	cout << "Please enter the previous annual salary: ";
	cin >> previous_salary;
	double new_salary = previous_salary + (previous_salary * pay_increase);
	cout << "Last year's salary:  " << previous_salary <<endl;
	cout << "New annual salary: " << new_salary << endl << "New monthly salary: " << new_salary / 12 << endl;
	cout << "The amount owed to employees is " << (new_salary - previous_salary) / 2;
}
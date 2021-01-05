#include <iostream>
using namespace std;
/*This calculates a worker's gross pay based on the hours worked per week.  There's a standard rate and OT rate
From this gross pay, there are a number of deductions for taxes
In addition, if a worker has 3 or more dependents, an additional deduction of $35 is levied for the health insurance
The inputs from the user are the hours worked, and the number of dependents
The outputs from the program are the gross pay, each withholding amount, and the net pay
*/
int main()
{
	const double social_security = 0.06;
	const double federal_income = 0.14;
	const double state_income = 0.05;
	const int union_dues = 10;
	const double hourly_rate = 16.78;
	const double overtime_rate = (hourly_rate * 1.5);
	const double max_standard_hours = 40;

	double hours_worked = 0;
	double gross_pay = 0;

	char repeat = 'y';

	while (repeat == 'y')
	{
		int dependents = 0;
		int dependent_tax = 0;
		cout << "First of all, how many dependents do you have?\n";
		cin >> dependents;
		if (dependents >= 3)
			dependent_tax = 35;
		else
			dependent_tax = 0;

		cout << "How many hours were worked this week?\n";
		cin >> hours_worked;


		double overtime_hours = hours_worked - max_standard_hours;

		if (hours_worked <= 40)
			gross_pay = hourly_rate * hours_worked;
		else
			gross_pay = (hourly_rate * max_standard_hours) + (overtime_rate * overtime_hours);

		cout << "The gross pay the worker is getting is: $" << gross_pay << endl;
		cout << "Social security withheld = $" << social_security * gross_pay << endl;
		cout << "Federal income tax withheld = $" << federal_income * gross_pay << endl;
		cout << "State income tax withheld = $" << state_income * gross_pay << endl;
		cout << "Union dues deducted = $" << union_dues << endl;
		cout << "Additional dependents tax = $" << dependent_tax << endl;

		cout << "Net take-home pay = $" << gross_pay - (social_security * gross_pay) - (federal_income * gross_pay)
			- (state_income * gross_pay) - union_dues - dependent_tax<<endl;

		cout << "Would you like to perform this calculation again?  Enter 'y' if so, and anything else to exit: ";
		cin >> repeat;
	}
	return 0;
}
#include <iostream>
using namespace std;
/*This program takes 3 inputs
1)  The amount a customer wishes to loan
2)  The annual interest rate of the loan
3)  The duration of that loan, in months

It will output:
1)  The face value require to return the customer's demanded amount
2)  A calculation of the montly repayment plan

There are a lack of reliable inputs (other than those from the textbook), but I think this is correct!
*/
int main()
{
	double customer_demand = 0.00;
	double percentage_interest_rate = 0.00;
	double monthly_duration_of_loan = 0;

	cout << "How much does the customer want to receive, cash in hand?\n";
	cin >> customer_demand;
	cout << "At what interest rate is this loan being offered?\n";
	cin >> percentage_interest_rate;
	cout << "For how long, in months, will this loan be lasting?\n";
	cin >> monthly_duration_of_loan;

	double actual_interest_rate = (percentage_interest_rate / 100);
	double annual_duration = (monthly_duration_of_loan / 12);
	double face_value = customer_demand / (1 - (actual_interest_rate * annual_duration));
	double monthly_repayment = face_value / monthly_duration_of_loan;

	cout << "You have requested a loan of " << customer_demand << ", which is calculated at "
		<< "an interest rate of " << percentage_interest_rate << "% for a total of " << monthly_duration_of_loan << " months\n";
	cout << "You'll be paying back a total of " << face_value << " at a monthly repayment rate of " << monthly_repayment << endl;
	
}
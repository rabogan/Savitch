#include<iostream>
using namespace std;
//This is Programming Project 9 of Chapter 2 in Savitch's book!
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	const double interest_rate = 0.015;
	double loan = 0.00;
	const double monthly_payment = 50.00;
	cout << "How much is being borrowed?\n";
	cin >> loan;
	int count = 1;
	do
	{
		double new_loan = loan + (loan * interest_rate);
		loan = new_loan - monthly_payment;
		cout << "Month number " << count << "   The loan is at " << new_loan << endl;
			++count;
	} while (loan > 0.00);
	cout << "It took " << count << " months to pay it off.\n";
}
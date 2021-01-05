#include<iostream>
using namespace std;
/*This program calculates the projected cost of an item after a user-specified number of years.  It takes three inputs:
1)  The inflation rate
2)  The cost of an item
3)  The number of years from now the item will be purchased
It needs to use a loop to calculate an adjusted expected future price.
By the way, there is a deliberately somewhat clumsy attempt to include the year!  I'm writing this in 2021...
Lines 13-15 allows a maximum of two significant figures after the decimal point 
*/
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double percentage_inflation_rate = 0.0;
	double current_cost = 0.00;
	int number_of_years = 0;
	const int next_year = 2022;

	cout << "How much is your item now?\n";
	cin >> current_cost;
	cout << "What is the rate of inflation?\n";
	cin >> percentage_inflation_rate;
	cout << "And how many years from now will you purchase this item?\n";
	cin >> number_of_years;
	double raw_inflation_rate = percentage_inflation_rate / 100;
	int count = 0;

	double projected_cost = current_cost;

	while (number_of_years>count)
	{
		projected_cost += projected_cost * raw_inflation_rate;
		cout << "In the year " << count+next_year << ", the projected cost is  $" << projected_cost << endl;
		++count;
	}
	cout << "For an item bought today for $" << current_cost << ", the projected cost in " << number_of_years
		<< " years is $" << projected_cost << endl << "This depends on the inflation rate of "<<  percentage_inflation_rate
		<< "% staying constant." << endl;
}
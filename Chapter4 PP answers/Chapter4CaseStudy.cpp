/* 
Covers the main points of Chapter 4, for personal reference.
1)  Represents the start of including preconditions and postconditions in the comments
2)  Introduces basic call-by-reference.
3)  Every function should be tested in a program in which every other function has been tested and debugged.
4)  A DRIVER PROGRAM does nothing but test a function
5)  A function 'definition' cannot appear inside the body of another function definition.
6)  A function definition can contain a call to another function
7)  Remember!!!!   WHAT IS THE INPUT?   2)  ????   3)  WHAT IS THE OUTPUT?   2 being 'What functions/subtasks are needed to calculate the output?'
*/

#include<iostream>

const double LOW_MARKUP = 0.05;
const double HIGH_MARKUP = 0.10;
const int THRESHOLD = 7;

void introduction();
//Postcondition: Description of the program is written on the screen

void get_input(double& cost, int& turnover);
//Precondition:  User is ready to enter values correctly
//Postcondition:  The value of cost has been set to the wholesale cost of one item.  The value of turnover has been set to the expected number
//of dats until the item is sold.

double price(double cost, int turnover);
//Precondition:  cost is the wholesale cost of one item.  AND: turnover is the expected number of days until the sale
//Postcondition: Returns the RETAIL price of the item, as a double.

void give_output(double cost, int turnover, double price);
//Precondition:  costs is the wholesale cost of one item.  Turnovers is the expected time until the sale of the item.
//AND price is the retail price of the item calculated previously.
//Postcondition:  values of the cost, turnover, and price are printed on the screen.

int main()
{
	double wholesale_cost, retail_price;
	int shelf_time;
	introduction();
	get_input(wholesale_cost, shelf_time);
	retail_price = price(wholesale_cost, shelf_time);
	give_output(wholesale_cost, shelf_time, retail_price);
	return 0;
}

//Uses iostream
void introduction()
{
	using namespace std;   //(Which is itself, a fully tested function)
	cout << "This program determines the retail price for \n";
	cout << "an item at a Quick-Shop supermarket store\n";
}
//Uses iostream
void get_input(double& cost, int& turnover)
{
	using namespace std;
	cout << "Enter the wholesale cost of the item: $";
	cin >> cost;
	cout << "Enter the expected number of days until sold: ";
	cin >> turnover;
}
//Uses iostream
void give_output(double cost, int turnover, double price)
{
	using namespace std;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Wholesale cost = $" << cost << endl
		<< "Expected time until sale = " << turnover
		<< " days." << endl
		<< "Retail price = $" << price << endl;
}

double price(double cost, int turnover)
{
	if (turnover <= THRESHOLD)
		return (cost + (LOW_MARKUP * cost));
	else
		return (cost + (HIGH_MARKUP * cost));
}
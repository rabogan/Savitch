/*This program is designed to:
1)  Read in the liters of gasoline consumed by the user's car.
2)  Read in the number of miles travelled by the car
3)  Output the number of miles per GALLON the car delivered
*/
#include<iostream>

const double GALLONS_PER_LITER = 0.264179;

double mpg(double gas_liters, double miles_travelled);

int main()
{
	using namespace std;    //Note how it is good practice to place these using directives where necessary.

	double liters = 0.0;
	double distance = 0.0;

	cout << "Please enter the number of liters consumed:\n";
	cin >> liters;
	cout << "Please enter the distance travelled, in miles:\n";
	cin >> distance;

	cout << "The miles per gallon is " << mpg(liters, distance) << endl;
}

double mpg(double gas_liters, double miles_travelled)
{
	return (miles_travelled / (gas_liters * GALLONS_PER_LITER));
}
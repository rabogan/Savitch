#include<iostream>

const double FEET_TO_METERS = 0.3048;
const int INCHES_PER_FOOT = 12;

void introduction();
//Postcondition:  this prints out the purpose of the program to the user.

void get_input(int& feet, double& inches);
//Precondition:  the user must be ready to input the number of feet and inches.
//Postcondition:  feet equals the number of feet input, and inches equals the user input for inches.

double calculate(int feet, double inches);
//Precondition: takes the user inputs for feet and inches.
//Postcondition:  returns a value (in meters)

void get_metric(double conversion, int &meters, int &cm);
//Precondition:  uses the calculation for conversion found in calculated.
//Precondition:  also takes in the variables meters and cm by reference.
//Postcondition:  returns values for meters and cm.

void give_output(int feet, double inches, int meters, int cm);
//Precondition:  Feet and inches are the user values input for these variables.
//The values meters and cm were calculated by get_metric.
//Postcondition:  prints out the value in meters and centimeters.

int main()
{
	using namespace std;
	introduction();
	int feet, meters, centimeters;
	double inches, converted;
	char ans = 'y';
	do {

		get_input(feet, inches);
		converted = calculate(feet, inches);
		get_metric(converted, meters, centimeters);
		give_output(feet, inches, meters, centimeters);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program inputs values of feet and inches\n"
		<< "from the user, and output a value in meters.\n";
}

void get_input(int& feet, double& inches)
{
	using namespace std;
	cout << "Please enter your value in feet: ";
	cin >> feet;
	cout << "And now the value in inches: ";
	cin >> inches;
}

double calculate(int feet, double inches)
{
	double result = feet * FEET_TO_METERS;
	double result2 = (inches / INCHES_PER_FOOT) * FEET_TO_METERS;
	return result + result2;
}

void get_metric(double conversion, int& meters, int& cm)
{
	cm = (conversion - (int)conversion) * 100;
	meters = (int)conversion;
}

void give_output(int feet, double inches, int meters, int centimeters)
{
	using namespace std;
	cout << "The amount in meters for " << feet;
	if (feet != 1)
		cout << " feet, ";
	else
		cout << " foot, ";
	cout << "and " << inches;
	if (inches != 1)
		cout << " inches ";
	else
		cout << " inch ";

	cout << "is " << meters;
	if (meters != 1)
		cout << " meters,";
	else
		cout << " meter,";
	cout << " and " << centimeters << " centimeters." << endl;
	cout << "Would you like to go again?  (y/n): ";
}
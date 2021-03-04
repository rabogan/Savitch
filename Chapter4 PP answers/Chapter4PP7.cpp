#include<iostream>

const double FEET_TO_METERS = 0.3048;
const int INCHES_PER_FOOT = 12;

void introduction();
//Postcondition:  this prints out the purpose of the program to the user.

void get_input(int& meters, int& centimeters);
//Precondition:  the user must be ready to input the number of meters and centimeters.
//Postcondition:  meters equals the number of meters input, and centimeters equals the user input for cm.

double calculate(int meters, double centimeters);
//Precondition: takes the user inputs for meters and centimeters.
//Postcondition:  returns a value (in inches)

void get_imperial(double conversion, int& feet, double& inches);
//Precondition:  uses the calculation for conversion found in calculated.
//Precondition:  also takes in the call-by-reference variables feet and inches.
//Postcondition:  returns values for feet and inches, after converting them using the conversion.

void give_output(int meters, int cm, int feet, double inches);
//Precondition:  Meters and cm are the user values input for these variables.
//The values feet and inches were calculated by get_imperial.
//Postcondition:  prints out the value for the inputs meters and cm using feet and inches.

int main()
{
	using namespace std;
	introduction();
	int feet, meters, centimeters;
	double inches, converted;
	char ans = 'y';
	do {

		get_input(meters, centimeters);
		converted = calculate(meters, centimeters);
		get_imperial(converted, feet, inches);
		give_output(meters, centimeters, feet, inches);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program inputs values in meters and centimeters\n"
		<< "from the user, and outputs a value in feet and inches.\n";
}

void get_input(int& meters, int& centimeters)
{
	using namespace std;
	cout << "Please enter your value in meters: ";
	cin >> meters;
	cout << "And now the value in centimeters: ";
	cin >> centimeters;
}

double calculate(int meters, double centimeters)
{
	double result = (meters + (centimeters / 100));
	return result / FEET_TO_METERS;
}

void get_imperial(double conversion, int& feet, double& inches)
{
	feet = (int)conversion;
	inches = (conversion - feet) * INCHES_PER_FOOT;
}

void give_output(int meters, int cm, int feet, double inches)
{
	using namespace std;
	cout << "The amount in feet for " << meters;
	if (meters != 1)
		cout << " meters, ";
	else
		cout << " meter, ";
	cout << "and " << cm;
	if (cm != 1)
		cout << " centimeters ";
	else
		cout << " centimeter ";

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "is " << feet;
	if (feet != 1)
		cout << " feet, ";
	else
		cout << " foot, ";
	cout << inches << " inches." << endl;
	cout << "Would you like to go again?  (y/n): ";
}
#include<iostream>

const double FEET_TO_METERS = 0.3048;
const int INCHES_PER_FOOT = 12;

void introduction();
//Postcondition:  this prints out the purpose of the program to the user.

int menu_choice();
//Precondition:  user is ready to enter 1 for imperial to metric, and 2 for metric to imperial
//Postcondition:  returns the appropriate value

void imperial_to_metric();
//Precondition:  the user has selected '1' in their choice.
//Postcondition:  this function runs through multiple function calls, converting from imperial to metric

void metric_to_imperial();
//Precondition:  the user has selected '2' in their choice.
//Postcondition:  this function runs through multiple function calls, converting from metric to imperial

void get_input_imperial(int& feet, double& inches);
//Precondition:  the user must be ready to input the number of feet and inches.
//Postcondition:  feet equals the number of feet input, and inches equals the user input for inches.

void get_input_metric(int& meters, int& centimeters);
//Precondition:  the user must be ready to input the number of meters and centimeters.
//Postcondition:  meters equals the number of meters input, and centimeters equals the user input for cm.

double calculate_from_imp(int feet, double inches);
//Precondition: takes the user inputs for feet and inches.
//Postcondition:  returns a value (in meters)

double calculate_from_metric(int meters, double centimeters);
//Precondition: takes the user inputs for meters and centimeters.
//Postcondition:  returns a value (in inches)

void get_metric(double conversion, int& meters, int& cm);
//Precondition:  uses the calculation for conversion found in calculated.
//Precondition:  also takes in the variables meters and cm by reference.
//Postcondition:  returns values for meters and cm.

void get_imperial(double conversion, int& feet, double& inches);
//Precondition:  uses the calculation for conversion found in calculated.
//Precondition:  also takes in the call-by-reference variables feet and inches.
//Postcondition:  returns values for feet and inches, after converting them using the conversion.

void give_metric_output(int feet, double inches, int meters, int cm);
//Precondition:  Feet and inches are the user values input for these variables.
//The values meters and cm were calculated by get_metric.
//Postcondition:  prints out the value in meters and centimeters.

void give_imperial_output(int meters, int cm, int feet, double inches);
//Precondition:  Meters and cm are the user values input for these variables.
//The values feet and inches were calculated by get_imperial.
//Postcondition:  prints out the value for the inputs meters and cm using feet and inches.

int main()
{
	using namespace std;
	introduction();
	int choice;
	char ans = 'y';
	do {
		choice = menu_choice();
		if (choice == 1)
			imperial_to_metric();
		else
			metric_to_imperial();

		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program asks the user if they wish to convert\n"
		<< "from imperial to metric, or vice versa.  It then asks\n"
		<< "the user to inputs their values, and then outputs values\n"
		<< "that convert the user inputs to either imperial or metric measurements.\n";
}

int menu_choice()
{
	using namespace std;
	int choice = 0;
	while (choice < 1 || choice >2)
	{
		cout << "Select from the following options\n";
		cout << "1)  Convert from imperial to metric\n";
		cout << "2)  Convert from metric to imperial\n";
		cout << "Enter your choice:  ";
		cin >> choice;
	}
	return choice;
}

void imperial_to_metric()
{
	using namespace std;
	int feet, meters, centimeters, choice;
	double inches, converted;
	get_input_imperial(feet, inches);
	converted = calculate_from_imp(feet, inches);
	get_metric(converted, meters, centimeters);
	give_metric_output(feet, inches, meters, centimeters);
}

void metric_to_imperial()
{
	int feet, meters, centimeters;
	double inches, converted;
	get_input_metric(meters, centimeters);
	converted = calculate_from_metric(meters, centimeters);
	get_imperial(converted, feet, inches);
	give_imperial_output(meters, centimeters, feet, inches);
}

void get_input_imperial(int& feet, double& inches)
{
	using namespace std;
	cout << "Please enter your value in feet: ";
	cin >> feet;
	cout << "And now the value in inches: ";
	cin >> inches;
}

void get_input_metric(int& meters, int& centimeters)
{
	using namespace std;
	cout << "Please enter your value in meters: ";
	cin >> meters;
	cout << "And now the value in centimeters: ";
	cin >> centimeters;
}

double calculate_from_imp(int feet, double inches)
{
	double result = feet * FEET_TO_METERS;
	double result2 = (inches / INCHES_PER_FOOT) * FEET_TO_METERS;
	return result + result2;
}

double calculate_from_metric(int meters, double centimeters)
{
	double result = (meters + (centimeters / 100));
	return result / FEET_TO_METERS;
}

void get_metric(double conversion, int& meters, int& cm)
{
	cm = (conversion - (int)conversion) * 100;
	meters = (int)conversion;
}

void get_imperial(double conversion, int& feet, double& inches)
{
	feet = (int)conversion;
	inches = (conversion - feet) * INCHES_PER_FOOT;
}

void give_metric_output(int feet, double inches, int meters, int centimeters)
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

void give_imperial_output(int meters, int cm, int feet, double inches)
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

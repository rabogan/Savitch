#include<iostream>

const double FEET_TO_METERS = 0.3048;
const int INCHES_PER_FOOT = 12;
const double POUNDS_PER_KG = 2.2046;
const int OUNCES_PER_POUND = 16;

void introduction();
//Postcondition:  this prints out the purpose of the program to the user.

int len_or_weight();
//Precondition:  User needs to be ready to choice whether they want length or weight converted.
//Postcondition:  User enters 1 for lengths, 2 for weight


//***************************************CONVERTING LENGTHS******************************************
void convert_length();
//Precondition:  user has chosen '1' in the previous menu
//Postcondition:  this function runs through a number of other functions to return converted length

void convert_weight();
//Precondition:  user has chosen '2' in the previous menu
//Postcondition:  this function runs through a number of other functions to return converted weight

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

//****************************IF TWO IS SELECTED - CONVERTING WEIGHT****************************
int user_choice_weight();
//Precondition:  User is ready to input their choice.
//Postcondition:  returns a value of 1 (for imperial to metric) or 2 (for metric to imperial)

//***************************IMPERIAL TO METRIC FUNCTIONS-WEIGHT********************************
void imperial_to_metric_weight();
//Precondition:  user chose 1 in imperial choice.
//Postcondition:  runs through the gamut of functions below, converting imperial inputs into metric!

void get_imperial_input_weight(int& pounds, double& ounces);
//Precondition:  user is ready to enter their values in pounds and ounces
//Postcondition: values for pounds and ounce now match the user input for these variables.

double calculate_metric_values_weight(int pounds, double ounces);
//Precondition: pounds and ounces were already input by the user.
//Postcondition: returns a metric conversion of this, in kilograms.

void get_metric_values_weight(double metric_value, int& kilos, int& grams);
//Precondition:  metric_value was calculated previously.  Kilos and grams
//are call-by-reference values that this function will change.
//Postcondition:  returns having converted the value into kgs and grams

void output_metric_values_weight(int pounds, double ounces, int kilos, int grams);
//Precondition:  All of the values for the variables were calculated by previous functions
//Postcondition:  prints out the metric conversion to the user, restating the imperial inputs.


//******************METRIC TO IMPERIAL FUNCTIONS-WEIGHT********************************//
void metric_to_imperial_weight();
//Precondition:  the user has input this in the function user_choice.
//Postcondition:  This function calls various other functions (listed below),
//AND converts metric measurements into imperial values.

void get_metric_input_weight(int& kilos, int& grams);
//Precondition:  user is ready to enter their values in kilograms and grams
//Postcondition: values for kilos and grams now match the user input for these variables.

double calculate_imperial_values_weight(int kilos, int grams);
//Precondition: kilos and grams were already input by the user.
//Postcondition: returns an imperial conversion of this, in pounds.

void get_imperial_values_weight(double imperial_value, int& pounds, int& ounces);
//Precondition:  The raw imperial_value was calculated previously.  Pounds and ounces
//are call-by-reference values that this function will change.
//Postcondition:  returns having converted the value into pounds and ounces

void output_imperial_values_weight(int kilos, int grams, int pounds, int ounces);
//Precondition:  All of the values for the variables were calculated by previous functions
//Postcondition:  prints out the imperial conversion to the user, restating the metric inputs.

int main()
{
	using namespace std;
	introduction();
	int len_or_weig;
	int choice;
	char ans = 'y';
	do {
		int len_or_weig = len_or_weight();
		if (len_or_weig == 1)
			convert_length();
		else
			convert_weight();
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program asks the user if they wish to convert\n"
		<< "length or weight values.  It then asks the user\n"
		<< "to choose between converting imperial or metric measurements.\n"
		<< "Finally, it prints out the converted measurements.\n";
}

int len_or_weight()
{
	using namespace std;
	int choice = 0;
	while (choice < 1 || choice >2)
	{
		cout << "Please select from the following options:\n";
		cout << "1)  Convert length\n";
		cout << "2)  Convert weight\n";
		cout << "Enter your choice:  ";
		cin >> choice;
	}
	return choice;
}

void convert_length()
{
	using namespace std;
	cout << "Setting up length conversion............\n";
	int choice;
	choice = menu_choice();
	if (choice == 1)
		imperial_to_metric();
	else
		metric_to_imperial();
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

void convert_weight()
{
	using namespace std;
	cout << "Setting up weight conversion..................\n";
	int choice;
	choice = user_choice_weight();
	if (choice == 1)
		imperial_to_metric_weight();
	else
		metric_to_imperial_weight();
}

int user_choice_weight()
{
	using namespace std;
	int choice = 0;
	while (choice < 1 || choice>2)
	{
		cout << "Please enter your choice:  \n";
		cout << "1)  Convert imperial to metric\n";
		cout << "2)  Convert metric to imperial\n";
		cin >> choice;
	}
	return choice;
}

void imperial_to_metric_weight()
{
	int pounds, kilos, grams;
	double ounces;
	double metric_value;
	get_imperial_input_weight(pounds, ounces);
	metric_value = calculate_metric_values_weight(pounds, ounces);
	get_metric_values_weight(metric_value, kilos, grams);
	output_metric_values_weight(pounds, ounces, kilos, grams);
}

void get_imperial_input_weight(int& pounds, double& ounces)
{
	using namespace std;
	cout << "Please enter the number of pounds: ";
	cin >> pounds;
	cout << "And now the number of ounces: ";
	cin >> ounces;
}

double calculate_metric_values_weight(int pounds, double ounces)
{
	double result;
	double first = pounds / POUNDS_PER_KG;
	double second = (ounces / 16);
	second /= POUNDS_PER_KG;
	result = first + second;
	return result;
}

void get_metric_values_weight(double metric_value, int& kilos, int& grams)
{
	kilos = (int)metric_value;
	grams = (metric_value - (int)metric_value) * 1000;
}

void output_metric_values_weight(int pounds, double ounces, int kilos, int grams)
{
	using namespace std;
	cout << "The imperial measurements " << pounds << "lbs" << " " << ounces << "ozs\n"
		<< "convert into " << kilos << "kg" << " " << grams << "grams." << endl;
	cout << "Would you like to do another calculation?\n";
}

void metric_to_imperial_weight()
{
	int pounds, kilos, grams, ounces;
	double imperial_value;
	get_metric_input_weight(kilos, grams);
	imperial_value = calculate_imperial_values_weight(kilos, grams);
	get_imperial_values_weight(imperial_value, pounds, ounces);
	output_imperial_values_weight(kilos, grams, pounds, ounces);
}

void get_metric_input_weight(int& kilograms, int& grams)
{
	using namespace std;
	cout << "Please enter the number of kilograms: ";
	cin >> kilograms;
	cout << "And now the number of grams: ";
	cin >> grams;
}

double calculate_imperial_values_weight(int kilos, int grams)
{
	double result;
	double first = kilos * POUNDS_PER_KG;
	double second = grams * POUNDS_PER_KG * 0.001;
	result = first + second;
	return result;
}

void get_imperial_values_weight(double imperial_value, int& pounds, int& ounces)
{
	pounds = (int)imperial_value;
	double oz = imperial_value - pounds;
	ounces = oz * OUNCES_PER_POUND;
}

void output_imperial_values_weight(int kilos, int grams, int pounds, int ounces)
{
	using namespace std;
	cout << "The metric measurements " << kilos << "kg" << " " << grams << "g\n"
		<< "convert into " << pounds << "lbs" << " " << ounces << "oz." << endl;
	cout << "Would you like to do another calculation?\n";
}
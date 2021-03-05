#include<iostream>

const double POUNDS_PER_KG = 2.2046;
const int OUNCES_PER_POUND = 16;

void introduction();
//Postcondition:  explains the purpose of the program to the user.

int user_choice();
//Precondition:  User is ready to input their choice.
//Postcondition:  returns a value of 1 (for imperial to metric) or 2 (for metric to imperial)

//********************IMPERIAL TO METRIC FUNCTIONS********************************//
void imperial_to_metric();
//Precondition:  user chose 1 in imperial choice.
//Postcondition:  runs through the gamut of functions below, converting imperial inputs into metric!

void get_imperial_input(int& pounds, double& ounces);
//Precondition:  user is ready to enter their values in pounds and ounces
//Postcondition: values for pounds and ounce now match the user input for these variables.

double calculate_metric_values(int pounds, double ounces);
//Precondition: pounds and ounces were already input by the user.
//Postcondition: returns a metric conversion of this, in kilograms.

void get_metric_values(double metric_value, int& kilos, int& grams);
//Precondition:  metric_value was calculated previously.  Kilos and grams
//are call-by-reference values that this function will change.
//Postcondition:  returns having converted the value into kgs and grams

void output_metric_values(int pounds, double ounces, int kilos, int grams);
//Precondition:  All of the values for the variables were calculated by previous functions
//Postcondition:  prints out the metric conversion to the user, restating the imperial inputs.


//******************METRIC TO IMPERIAL FUNCTIONS********************************//
void metric_to_imperial();
//Precondition:  the user has input this in the function user_choice.
//Postcondition:  This function calls various other functions (listed below),
//AND converts metric measurements into imperial values.

void get_metric_input(int& kilos, int& grams);
//Precondition:  user is ready to enter their values in kilograms and grams
//Postcondition: values for kilos and grams now match the user input for these variables.

double calculate_imperial_values(int kilos, int grams);
//Precondition: kilos and grams were already input by the user.
//Postcondition: returns an imperial conversion of this, in pounds.

void get_imperial_values(double imperial_value, int& pounds, int& ounces);
//Precondition:  The raw imperial_value was calculated previously.  Pounds and ounces
//are call-by-reference values that this function will change.
//Postcondition:  returns having converted the value into pounds and ounces

void output_imperial_values(int kilos, int grams, int pounds, int ounces);
//Precondition:  All of the values for the variables were calculated by previous functions
//Postcondition:  prints out the imperial conversion to the user, restating the metric inputs.


int main()
{
	using namespace std;
	introduction();
	char ans = 'y';
	int choice;
	do
	{
		choice = user_choice();
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
	cout << "This program asks the user for the conversion they want.\n"
		<< "It then inputs measurements from the user, and converts\n"
		<< "these from either imperial to metric, or metric to imperial\n";
}

int user_choice() 
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

void imperial_to_metric()
{
	int pounds, kilos, grams;
	double ounces;
	double metric_value;
	get_imperial_input(pounds, ounces);
	metric_value = calculate_metric_values(pounds, ounces);
	get_metric_values(metric_value, kilos, grams);
	output_metric_values(pounds, ounces, kilos, grams);
}

void get_imperial_input(int& pounds, double& ounces)
{
	using namespace std;
	cout << "Please enter the number of pounds: ";
	cin >> pounds;
	cout << "And now the number of ounces: ";
	cin >> ounces;
}

double calculate_metric_values(int pounds, double ounces)
{
	double result;
	double first = pounds / POUNDS_PER_KG;
	double second = (ounces / 16);
	second /= POUNDS_PER_KG;
	result = first + second;
	return result;
}

void get_metric_values(double metric_value, int& kilos, int& grams)
{
	kilos = (int)metric_value;
	grams = (metric_value - (int)metric_value) * 1000;
}

void output_metric_values(int pounds, double ounces, int kilos, int grams)
{
	using namespace std;
	cout << "The imperial measurements " << pounds << "lbs" << " " << ounces << "ozs\n"
		<< "convert into " << kilos << "kg" << " " << grams << "grams." << endl;
	cout << "Would you like to do another calculation?\n";
}

void metric_to_imperial()
{
	int pounds, kilos, grams, ounces;
	double imperial_value;
	get_metric_input(kilos, grams);
	imperial_value = calculate_imperial_values(kilos, grams);
	get_imperial_values(imperial_value, pounds, ounces);
	output_imperial_values(kilos, grams, pounds, ounces);
}

void get_metric_input(int& kilograms, int& grams)
{
	using namespace std;
	cout << "Please enter the number of kilograms: ";
	cin >> kilograms;
	cout << "And now the number of grams: ";
	cin >> grams;
}

double calculate_imperial_values(int kilos, int grams)
{
	double result;
	double first = kilos * POUNDS_PER_KG;
	double second = grams * POUNDS_PER_KG * 0.001;
	result = first + second;
	return result;
}

void get_imperial_values(double imperial_value, int& pounds, int& ounces)
{
	pounds = (int)imperial_value;
	double oz = imperial_value - pounds;
	ounces = oz * OUNCES_PER_POUND;
}

void output_imperial_values(int kilos, int grams, int pounds, int ounces)
{
	using namespace std;
	cout << "The metric measurements " << kilos << "kg" << " " << grams << "g\n"
		<< "convert into " << pounds << "lbs" << " " << ounces << "oz." << endl;
	cout << "Would you like to do another calculation?\n";
}
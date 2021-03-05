#include<iostream>

const double POUNDS_PER_KG = 2.2046;
const int OUNCES_PER_POUND = 16;

void introduction();
//Postcondition:  explains the purpose of the program to the user.

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

void output_imperial_values(int kilos, int grams,int pounds, int ounces);
//Precondition:  All of the values for the variables were calculated by previous functions
//Postcondition:  prints out the imperial conversion to the user, restating the metric inputs.

int main()
{
	using namespace std;
	introduction();
	char ans = 'y';
	int pounds, kilos, grams, ounces;
	double imperial_value;
	do
	{
		get_metric_input(kilos, grams);
		imperial_value = calculate_imperial_values(kilos, grams);
		get_imperial_values(imperial_value, pounds, ounces);
		output_imperial_values(kilos,grams,pounds, ounces);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program inputs values in kilos and grams\n"
		<< "(metric measurements) from the user, and converts\n"
		<< "these inputs into pounds and ounces\n";
}

void get_metric_input(int& kilograms,int& grams)
{
	using namespace std;
	cout << "Please enter the number of kilograms: ";
	cin >> kilograms;
	cout << "And now the number of grams: ";
	cin >> grams;
}

double calculate_imperial_values(int kilos,int grams)
{
	double result;
	double first = kilos*POUNDS_PER_KG;
	double second = grams*POUNDS_PER_KG*0.001;
	result = first + second;
	return result;
}

void get_imperial_values(double imperial_value, int& pounds, int& ounces)
{
	pounds= (int)imperial_value;
	double oz = imperial_value - pounds;
	ounces = oz * OUNCES_PER_POUND;
}

void output_imperial_values(int kilos, int grams,int pounds, int ounces)
{
	using namespace std;
	cout << "The metric measurements " << kilos << "kg" << " " << grams << "g\n"
		<< "convert into " << pounds << "lbs" << " " << ounces << "oz." << endl;
	cout << "Would you like to do another calculation?\n";
}
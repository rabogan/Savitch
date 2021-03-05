#include<iostream>

const double POUNDS_PER_KG = 2.2046;
const int OUNCES_PER_POUND = 16;

void introduction();
//Postcondition:  explains the purpose of the program to the user.

void get_imperial_input(int &pounds, double &ounces);
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

int main()
{
	using namespace std;
	introduction();
	char ans = 'y';
	int pounds, kilos, grams;
	double ounces;
	double metric_value;
	do
	{
		get_imperial_input(pounds, ounces);
		metric_value = calculate_metric_values(pounds, ounces);
		get_metric_values(metric_value,kilos,grams);
		output_metric_values(pounds, ounces, kilos, grams);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program inputs values in pounds and ounces\n"
		<< "(imperial measurements) from the user, and converts\n"
		<< "these inputs into kilograms and grams\n";
}

void get_imperial_input(int& pounds, double& ounces)
{
	using namespace std;
	cout  << "Please enter the number of pounds: ";
	cin >> pounds;
	cout << "And now the number of ounces: ";
	cin >> ounces;
}

double calculate_metric_values(int pounds, double ounces)
{
	double result;
	double first = pounds / POUNDS_PER_KG;
	double second = (ounces / 16);
	second/=POUNDS_PER_KG;
	result = first+second;
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
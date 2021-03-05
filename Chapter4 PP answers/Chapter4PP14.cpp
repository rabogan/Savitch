#include <iostream>

void introduction();
//Postcondition:  this function explains the purpose of this program to the user

void get_input(int& temp, double& wind);
//Precondition:  user is ready to input values of temperature and wind speed
//Postcondition:  temp is set to a user-input temperature (in Celsius),
//and wind speed set to the user-input of wind speed (in meters per second).

double calculate_windchill(int temperature, double wind_speed);
//Precondition:  user has already input values of temperature and wind speed
//Postcondition:  returns a value for the windchill. If temperature is <=10,
//this is 0.   Otherwise, the calculation is performed

void give_output(int temperature, double wind_speed, double windchill);
//Precondition:  values for temperature and wind_speed were input by the user.
//and the windchill was calculated by the calculate windchill function
//Postcondition:  prints the windchill for the user.

int main()
{
	introduction();
	double windchill, wind_speed;
	int temperature;
	get_input(temperature, wind_speed);
	windchill = calculate_windchill(temperature, wind_speed);
	give_output(temperature, wind_speed, windchill);
}

void introduction()
{
	using namespace std;
	cout << "This program will get user input for values of\n"
		<< "temperature and wind speed, and use these to return\n"
		<< "a value for the windchill factor\n";
}

void get_input(int& temp, double& wind)
{
	using namespace std;
	cout << "Please enter your temperature: ";
	cin >> temp;
	cout << "Now, enter the wind speed: ";
	cin >> wind;
}

double calculate_windchill(int temperature, double wind_speed)  //Strictly speaking, it'd be preferable to use consts in this function!
{
	using namespace std;
	double windchill;
	double v1 = pow(wind_speed, 0.16);
	double v2 = pow(wind_speed, 0.016);
	if (temperature > 10)
	{
		cout << "At temperatures greater than 10, windchill has no effect\n";
		windchill = 0;
	}
	else
	{
		windchill = 13.12 + (0.6215 * temperature) - (11.37 * v1) + (0.3965 * temperature * v2);
	}
	return windchill;
}

void give_output(int temperature, double wind_speed, double windchill)
{
	using namespace std;
	cout << "For the values:\n"
		<< "Temperature:  " << temperature << "\nWind Speed:  " << wind_speed
		<< "\nWindchill = " << windchill << endl;
}
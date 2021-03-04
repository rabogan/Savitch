#include<iostream>

const int MAX_HOURS = 24;
const int MAX_MINUTES = 60;

void introduction();
//Postcondition: description of the program is written on the screen

void get_input(int& hrs, int& minutes, int& wait_time_h, int& wait_time_min);
//Precondition:  user is ready to input the current time
//Postcondition:  the values or hrs and minutes are set to the current time (24hr mode)
//and the wait_time_h and wait_time_min are the waiting times in hrs and minutes.

void calculate(int& hours, int& minutes, int wait_hours, int wait_minutes);
//Precondition: the values of hours and minutes are the current time, in 24hr clock format.
//AND the wait_hours/wait_minutes are integers denoting the amount of time one has to wait.
//Postcondition:  returns the time after the waiting period.

void give_output(int hours_out, int min_out);
//Precondition:  hours_out represents the time in hours, and min_out the time in minutes
//AFTER the addition of the waiting time.
//Postcondition: Prints out the new time!

int main()
{
	using namespace std;
	introduction();
	char ans = 'y';
	int hour_time, min_time, wait_hr, wait_min;
	do
	{
		get_input(hour_time, min_time, wait_hr, wait_min);
		calculate(hour_time, min_time, wait_hr, wait_min);
		give_output(hour_time, min_time);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program requests the current time (in 24hr format)"
		<< ", then a waiting time (in hours and minutes).\n"
		<< "It returns what the time will be after the waiting period\n"
		<< "Additionally, it runs on a loop dependent on user input\n";
}

void get_input(int& hrs, int& minutes, int& wait_time_h, int& wait_time_min)
{
	using namespace std;
	cout << "Enter the current time, in hours (24-hour format, please): ";
	cin >> hrs;
	cout << "Enter the current time, in minutes (24-hour format, please): ";
	cin >> minutes;
	cout << "Please enter the current waiting period, in hours: ";
	cin >> wait_time_h;
	cout << "And, now, in minutes: ";
	cin >> wait_time_min;
	cout << "The current time is " << hrs << ':' << minutes
		<< ", and there's a waiting time of " << wait_time_h << " hours and " << wait_time_min << " minutes." << endl;
}

void calculate(int& hours, int& minutes, int wait_hours, int wait_minutes)
{
	using namespace std;
	int remainder = 0;
	int new_minutes = minutes + wait_minutes;
	if (new_minutes >= MAX_MINUTES)  //This is true only if the input for minutes doesn't exceed 59!
	{
		remainder = 1;
		new_minutes = new_minutes % MAX_MINUTES;
	}
	minutes = new_minutes;

	int new_hours = hours + wait_hours + remainder;
	if (new_hours >= MAX_HOURS)
		new_hours = new_hours % MAX_HOURS;
	hours = new_hours;
}

void give_output(int hours_out, int min_out)
{
	using namespace std;
	cout << "The estimated time after waiting is " <<
		hours_out << ':';
	if (min_out < 10)
		cout << '0';

	cout << min_out << endl;
	cout << "Would you like to input again?\n";
}
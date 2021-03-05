#include<iostream>

const int MAX_HOURS = 12;
const int MAX_MINUTES = 60;

void introduction();
//Postcondition: description of the program is written on the screen

void get_input(int& hrs, int& minutes, char& meridiem, int& wait_time_h, int& wait_time_min);
//Precondition:  user is ready to input the current time (in 12hr format).
//Postcondition:  the values or hrs and minutes are set to the current time (12hr mode, with AM/PM)
//and the wait_time_h and wait_time_min are the waiting times in hrs and minutes.  The meridiem is
//a char indicating if it is AM or PM.

void calculate(int& hours, int& minutes, int wait_hours, int wait_minutes,  char& meridiem);
//Precondition: the values of hours and minutes are the current time, in 12hr clock format.
//AND the wait_hours/wait_minutes are integers denoting the amount of time one has to wait.
//The call-by-ref char meridiem indicates if the time should be AM or PM
//Postcondition:  returns the time after the waiting period, and also a char indicating if it is AM or PM.

void give_output(int hours_out, int min_out, char meridiem);
//Precondition:  hours_out represents the time in hours, and min_out the time in minutes
//AFTER the addition of the waiting time.
//Postcondition: Prints out the new time!

int main()
{
	using namespace std;
	introduction();
	char ans = 'y';
	int hour_time, min_time, wait_hr, wait_min;
	char meridiem;
	do
	{
		get_input(hour_time, min_time, meridiem, wait_hr, wait_min);
		calculate(hour_time, min_time, wait_hr, wait_min,meridiem);
		give_output(hour_time, min_time,meridiem);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program requests the current time (in 12hr format)"
		<< ", then a waiting time (in hours and minutes).  It's accurate up to about 10 hours.  After that, you're waiting too long, frankly!\n"
		<< "It returns what the time will be after the waiting period, in any case.\n"
		<< "Additionally, it runs on a loop dependent on user input\n";
}

void get_input(int& hrs, int& minutes, char&meridiem, int& wait_time_h, int& wait_time_min)
{
	using namespace std;
	cout << "Enter the current time, in hours (12-hour format, please): ";
	cin >> hrs;
	cout << "Enter the current time, in minutes (12-hour format, please): ";
	cin >> minutes;
	cout << "Is that AM or PM?   Type in am or pm: ";
	string input;
	cin >> input;
	if (input == "AM" || input == "am")
		meridiem = 'A';
	else
		meridiem = 'P';
	cout << "Please enter the current waiting period, in hours: ";
	cin >> wait_time_h;
	cout << "And, now, in minutes: ";
	cin >> wait_time_min;
	cout << "The current time is ";
	if (hrs < 10)
		cout << '0';
	cout << hrs << ':';
	if (minutes < 10)
		cout << '0';
	cout << minutes;
	if (meridiem == 'A')
		cout << "am";
	else
		cout << "pm";
	cout << ", and there's a waiting time of " << wait_time_h << " hours and " << wait_time_min << " minutes." << endl;
}

void calculate(int& hours, int& minutes, int wait_hours, int wait_minutes, char& meridiem)
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

	hours = hours % MAX_HOURS;  //Most important change here!!
	//It might also be useful to use a 'modulus' function on the waiting time, to prevent errors.

	if (hours + wait_hours >= MAX_HOURS && meridiem == 'A') //Basically, 12am is 0am, and 12pm in 0pm...if 12 is exceeded, we know to move from AM->PM or vice versa
		meridiem = 'P';

	else if (hours + wait_hours >= MAX_HOURS && meridiem == 'P')
		meridiem = 'A';

	int new_hours = hours + wait_hours + remainder;

	if (new_hours == 0)  //This is a special case, and converts any 0 back to 12.
	{
		new_hours = MAX_HOURS;
	}

	if (new_hours > MAX_HOURS)
	{
		new_hours = new_hours % MAX_HOURS;
	}

	hours = new_hours;
}

void give_output(int hours_out, int min_out, char meridiem)
{
	using namespace std;
	cout << "The estimated time after waiting is " <<
		hours_out << ':';
	if (min_out < 10)
		cout << '0';

	cout << min_out;
	if (meridiem == 'A')
		cout << " AM"<<endl;
	else
		cout << " PM"<<endl;
	cout << "Would you like to input again?\n";
}
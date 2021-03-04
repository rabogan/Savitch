#include<iostream>

const int THRESHOLD = 12;

void introduction();
//Postcondition: description of the program is written on the screen

void get_input(int& hours_in, int& minutes_in);
//Precondition: user inputs values in 24hr clock format
//Postcondition: returns a value of hours and minutes in the appropriate format (hrs 0-23, min 0-59)

int new_time(int hour_calculated, char& meridiem);
//Precondition:  hour is the 24hr clock format input for the hour
//meridiem is a call-by-reference formal parameter used to determine if it is AM or PM
//Postcondition:  returns a value for the hour calculated (converted to 12 hour format),
//AND changes the meridiem to indicate if it is AM or PM as necessary.

void give_output(int hours_out, int minutes_out, char meridiem_found);
//Precondition:hours_out is the 12 hour format for the hour, minutes_out is the same (for minutes),
//meridiem_found is a character indicating if it is AM or PM
//Postcondition:  prints out the 12hr version of the time on the screen (hrs, minutes, AM or PM)

int main()
{
	using namespace std;

	char ans = 'y';  //This makes it possible for the  user to do the loop until the end of the program
	introduction();
	do
	{
		int hour, minute;
		char meridiem;
		get_input(hour, minute);
		hour = new_time(hour, meridiem);
		give_output(hour, minute, meridiem);
		cin >> ans;
	} while (ans == 'y'||ans == 'Y');

	return 0;
}

//Uses iostream
void introduction()
{
	using namespace std;
	cout << "This program converts 24hr clock input into\n"
		<< "the 12hr clock format.\n";
}
//Uses iostream
void get_input(int& hours_in, int& minutes_in)
{
	using namespace std;
	cout << "Please enter the hour, in 24hr format:";
	cin >> hours_in;
	cout << "Now enter the minutes:";
	cin >> minutes_in;
}

void give_output(int hours_out, int minutes_out, char meridiem_found)
{
	using namespace std;
	cout << "The time now is " << hours_out << ':' << minutes_out << ' ';
	if (meridiem_found == 'A')
		cout << "AM\n";
	else
		cout << "PM\n";

	cout << "Would you like to run it again?  Enter Y/y to do so, or anything else to exit: ";
}

//Uses iostream
int new_time(int hour_calculated, char& meridiem)
{
	if (hour_calculated >= THRESHOLD)
		meridiem = 'P';
	else
		meridiem = 'A';

	if (hour_calculated > THRESHOLD)
		hour_calculated -= THRESHOLD;

	return hour_calculated;
}
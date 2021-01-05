#include<iostream>
using namespace std;
//Program which declares whether or not a meeting may go ahead
//If it's legal, it tells you how many additional people are allowed
//If it contravenes fire regulations, it tells you how many need to be excluded
//This program allows the user to enter the calculation as many times as they desire
int main()
{
	int max_capacity = 0;
	int attendee_number = 0;

	char check = 'y';

	while (check == 'y'||check =='Y')
	{
		cout << "What is the maximum capacity?\n";
		cin >> max_capacity;
		cout << "And how many will be attending this meeting?\n";
		cin >> attendee_number;

		if (attendee_number == max_capacity)
			cout << "Meeting allowed, but it is at maximum capacity!\n";
		else if (attendee_number < max_capacity)
			cout << "Meeting allowed, and you may have up to " << max_capacity - attendee_number << " additional attendees if you wish.\n";
		else
			cout << "Meeting verboten!   You will need to get rid of " << attendee_number - max_capacity << " more to be compliant with fire regulations.\n";
		cout << "Do you want another calculation?"<< endl << "Enter 'y' or 'Y' if so, and anything else to exit\n";
		cin >> check;
	}
	return 0;
}
#include<iostream>

const int QUARTERS = 25;
const int DIMES = 10;
const int PENNIES = 1;

void introduction();
//Postcondition:  prints out the purpose of this program to the user

void grab_input(int& cent_amount);
//Precondition: user ready to input a value between 1-99.
//Postcondition:  cent_amount is equal to the value the user input

void compute_coin(int coin_value, int& number, int& amount_left);
//Precondition: 0 < coin_value < 100; 0 <= amount_left <= 100
//Postcondition: number has been set equal to the maximum number of coins
//of denomination coin_value cents that can be obtained from amount_left cents.
//Amount_left is decreased by the value of the coins, that is, decreased by number*coin_value

void print_results(int quarter_total, int dime_total, int penny_total, int coin_value);
//Precondition:  quarter_total, dime_total, and penny_total are the numbers gleaned for the number of each coin.
//AND coin_value is the input from 1-99.
//Postcondition:  The results are printed out to the user in a presentable way

int main()
{
	using namespace std;
	char ans = 'y';
	introduction();
	int quarters, dimes, pennies, amount, amount_remaining, number;
	do {
		grab_input(amount);
		amount_remaining = amount;
		compute_coin(QUARTERS, number, amount_remaining);
		quarters = number;
		compute_coin(DIMES, number, amount_remaining);
		dimes = number;
		compute_coin(PENNIES, number, amount_remaining);
		pennies = number;
		print_results(quarters, dimes, pennies, amount);
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}

void introduction()
{
	using namespace std;
	cout << "This program will prompt the user for an input\n"
		<< "between 1 to 99 cents, and return a value in\n"
		<< "denominations of quarters, dimes, and pennies.\n";
}

void grab_input(int& cent_amount)
{
	using namespace std;
	cout << "Please enter your total to exchange,\n"
		<< "using a value between 1 and 99: \n";
	cin >> cent_amount;
}

void compute_coin(int coin_value, int& number, int& amount_left)
{
	number = amount_left / coin_value;
	amount_left = amount_left - (number * coin_value);
}

void print_results(int quarters, int dimes, int pennies, int amount_input)
{
	using namespace std;
	cout << amount_input << " cents can be given as " << quarters
		<< " quarter";
	if (quarters != 1)
		cout << 's';
	cout << ", " << dimes << " dime";
	if (dimes != 1)
		cout << 's';
	cout << ", and " << pennies;
	if (pennies != 1)
		cout << " pennies." << endl;
	else
		cout << " penny." << endl;

	cout << "Would you like to try again?  (y/n):";
}
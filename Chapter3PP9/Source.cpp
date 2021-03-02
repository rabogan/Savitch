#include<iostream>
using namespace std;

double hat_size(double h, double w)
{
	return ((w / h) * 2.9);
}

double jacket_size(double h, double w, double a)
{
	int extra = a / 10;
	double extrainch = ((double)extra - 3) / 8;

	double x = (h * w) / 288;
	if (a < 40)
		return x;
	else
		return x + extrainch;
}

double waist_size(double w, double a)
{
	double newage = ((a - 29) / 20);

	if ((int)a % 2 == 0)
	{
		newage += 0.05;
	}

	double size = w / 5.7;
	return size + newage;
}

void enter_values()
{
	char entry = 'y';
	while (entry != 'x')
	{
		cout << "Please give me the user height, weight and age:\n";
		double height = 0;
		double weight = 0;
		double age = 0;
		cin >> height >> weight >> age;

		cout << "Based on this, the hat size is " << hat_size(height, weight) << endl;
		cout << "The jacket size is " << jacket_size(height, weight, age) << endl;
		cout << "The waist size is " << waist_size(weight, age) << endl;
		cout << "Would you like to repeat this calculation?  Enter x to exit, or anything else to continue: ";
		cin >> entry;
		cout << endl;
	}
}

int main()
{
	enter_values();
	return 0;
}
#include<iostream>
using namespace std;

//Program calculating deadly amount of soda pop

int main()
{
	const double SWEETENER_CONTENT = 0.001;

	double deadly_amount = 0.00;
	double dieter_min_weight = 50.00;
	double dieter_weight = 200.00;
	double raw_weight = 200.00;
	double mouse_weight = 50.00;
	double new_deadly_amount = 1.00;
	cout << "Input how many milliliters of sweetener is deadly to the mouse:\n";
	cin >> deadly_amount;
	cout << "Liters of soda pop to kill a mouse of " << mouse_weight << " grams is "
		<< (deadly_amount / 1000) / SWEETENER_CONTENT << endl;

	while (dieter_weight>dieter_min_weight)
	{
		cout << "Enter the dieter's weight, in kilograms:";
		cin >> raw_weight;
		dieter_weight = raw_weight * 1000;
		cout << "Your guy is " << raw_weight << " kilograms." << endl;
		new_deadly_amount = deadly_amount* (dieter_weight / mouse_weight);
		cout << "It would take " << new_deadly_amount << " liters of soda pop to kill this person" << endl;
	}
	return 0;
}
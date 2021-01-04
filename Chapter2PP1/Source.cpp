#include<iostream>
using namespace std;

//Program reading the weight of a cereal box in ounces, outputing the weight in metric tons.
//It will also out the number of boxes needed to yield one metric ton of cereal.

int main()
{
	double const metric_ton = 35273.92;  //Number of ounces in a metric ton
	double weight = 0;
	cout << "Please enter the weight of your package, using ounces: ";
	while (weight >= 0)
	{
		cin >> weight;
		if (weight == 'x')
			break;
		double ton_weight = weight / metric_ton;
		double cereal_boxes = metric_ton / weight;

		cout << "For a box of weight " << weight << ", that's " << ton_weight << " metric tons, and "
			<< " it will need " << cereal_boxes << " boxes to make up one ton of the product" << endl;
	}
	return 0;
}
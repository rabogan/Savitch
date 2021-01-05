#include<iostream>
using namespace std;

/*Program reading in 10 whole numbers
1)  Outputs the sum of all numbers greater than zero
2)  Outputs the sum of all numbers less than or equal to zero
3)  Outputs the sum of all numbers
*/
int main()
{
	int num = 0;
	int positive_total = 0;
	int negative_total = 0;
	int total = 0;
	cout << "Please enter your 10 numbers:" << endl;
	int count = 0;

	while (count <10)
	{
	cin >> num;
	total += num;
	if (num > 0)
		positive_total += num;
	if (num <= 0)
		negative_total += num;
	++count;
	}
	cout << "Overall total: " << total << endl;
	cout << "Positive total: " << positive_total << endl;
	cout << "Negative total: " << negative_total << endl;
	return 0;
}
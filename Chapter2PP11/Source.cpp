#include<iostream>
using namespace std;

/*Program reading in 10 whole numbers
1)  Outputs the sum of all numbers greater than zero
2)  Outputs the sum of all numbers less than or equal to zero
3)  Outputs the sum of all numbers
4)  Additionally to the previous exercise, it outputs the averages for:
i)  All numbers entered
ii)  All positive numbers
iii)  All negative number
This inelegantly avoids division by zero.   Much better to use try/catch/throw for that :)
*/
int main()
{
	int num = 0;
	int positive_total = 0;
	int negative_total = 0;
	int total = 0;
	cout << "Please enter your 10 numbers:" << endl;
	int count = 0;
	int positive_count = 0;
	int negative_count = 0;

	while (count < 10)
	{
		cin >> num;
		total += num;
		if (num > 0)
		{
			positive_total += num;
			++positive_count;
		}
		if (num <= 0)
		{
			negative_total += num;
			++negative_count;
		}
		++count;
	}
	cout << "Overall total: " << total << endl;
	cout << "Overall average: " << total / count << endl;
	cout << "Positive total: " << positive_total << endl;
	if(positive_count!=0)
	cout << "Positive number average: " << positive_total / positive_count << endl;
	cout << "Negative total: " << negative_total << endl;
	if (negative_count!=0)
	cout << "Negative number average: " << negative_total / negative_count << endl;
	return 0;
}
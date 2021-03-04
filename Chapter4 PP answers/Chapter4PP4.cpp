//The point of this is not only to provide a calculation of the sd and average...
//but during the process, it's important to use a DRIVER PROGRAM to test input!!!

#include<iostream>

const int SCORES = 4;

void introduction();
//Postcondition:  Description of the program is printed on the screen.

void get_input(double& s1, double& s2, double& s3, double& s4);
//Precondition:  User is ready to input their four scores.
//Postcondition:  The values s1 thru s4 have been set equal to the numbers input by the user (whole integers only)

void calculation(double s1, double s2, double s3, double s4, double& avg, double& st_dev);
//Precondition:  We already have inputs s1-s4 from the user
//Postcondition:  average and standard_deviation have been calculated and returned to main

void give_output(double avg, double st_dev);
//Precondition:  the average and standard_deviation calculated by the calculation function.
//Postcondition:   prints the values calculated for the user.

int main()
{
	using namespace std;

	double score1, score2, score3, score4, average, standard_deviation;
	char ans = 'y';
	do
	{
		introduction();
		get_input(score1, score2, score3, score4);
		calculation(score1, score2, score3, score4, average, standard_deviation);
		give_output(average, standard_deviation);

		cin >> ans;
	} while (ans=='y'||ans=='Y');

	return 0;
}

void introduction()
{
	using namespace std;
	cout << "The purpose of this program is to\n"
		<< "collect four scores from the user\n"
		<< "and use them to calculate an average\n"
		<< "and standard deviation\n";
}

void get_input(double& s1, double& s2, double& s3, double& s4)
{
	using namespace std;
	cout << "Please enter your first score: ";
	cin >> s1;
	cout << "Please enter your second score: ";
	cin >> s2;
	cout << "Please enter your third score: ";
	cin >> s3;
	cout << "And now your final score: ";
	cin >> s4;
}

void calculation(double s1, double s2, double s3, double s4, double& avg, double& st_dev)
{
	using namespace std;
	double total = s1 + s2 + s3 + s4;
	cout << "The total of the values " << s1 << " " << s2
		<< " " << s3 << " and " << s4 << " is " << total << '.'<< endl;
	avg = total / SCORES;

	double a = (s1 - avg) * (s1 - avg);
	double b = (s2 - avg) * (s2 - avg);
	double c = (s3 - avg) * (s3 - avg);
	double d = (s4 - avg) * (s4 - avg);

	double total_2 = a + b + c + d;
	total_2 /= SCORES;
	st_dev = sqrt(total_2);
}

void give_output(double avg, double st_dev)
{
	using namespace std;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "The average is " << avg << endl
		<< "and the standard deviation is " << st_dev << endl;
	cout << "Would you like to go again? (y/n): ";
}
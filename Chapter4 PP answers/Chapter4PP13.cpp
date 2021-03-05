#include <iostream>

void introduction();
//Postcondition: informs the user of the purpose of the program

void get_input(int &a, int& b, int& c);
//Precondition: the user is ready to input three values
//Postcondition:  using call-by-reference, the three lengths are returned

void calculation(int a, int b, int c, double& area, int& perimeter);
//Precondition:  the user has input values for a, b, and c
//Postcondition:  using call-by-reference, values for the area and perimeter are returned

void give_output(int a, int b, int c, double& area, int& perimeter);
//Precondition:  values for a,b,c were input in get_input
//Precondition: values for area and perimeter were calculated into the previously called calculation function
//Postcondition:  Prints out the area and perimeter for the user.

int main()
{
	introduction();
	using namespace std;
	int a, b, c, perimeter;
	double area;
	get_input(a,b,c);
	calculation(a, b, c, area, perimeter);
	give_output(a, b, c, area, perimeter);
	return 0;
}

void introduction()
{
	using namespace std;
	cout << "This program will take three inputs from the user\n"
		<< "where each input represents the length of one side of a triangle\n"
		<< "It then outputs accurate results (where possible) for the area and perimeter\n";
}

void get_input(int& a, int& b, int& c)
{
	using namespace std;
	cout << "Please enter your first value: ";
	cin >> a;
	cout << "Please enter your second value: ";
	cin >> b;
	cout << "Please enter your third value: ";
	cin >> c;
}

void calculation(int a, int b, int c, double& area, int& perimeter)
{
	perimeter = a + b + c;
	double s = perimeter / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
}

void give_output(int a, int b, int c, double& area, int& perimeter)
{
	using namespace std;
	cout << "For values:\n" << "a: " << a << "\nb: " << b
		<< "\nc: " << c << "\nArea = " << area << " units squared\nPerimeter = " << perimeter << "units" << endl;
}
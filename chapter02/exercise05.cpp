#include <iostream>
using namespace std;

double C2F(double c);

int main()
{
	double C = 0.0;
	double F = 0.0;

	cout << "Please enter a Celsius value: ";
	cin >> C;

	F = C2F(C);

	cout << C << " degrees Celsius is " << F << " degrees Fahrenheit.";

	cin.get();
	cin.get();
	return 0;
}

double C2F(double C)
{
	return 1.8 * C + 32.0;
}

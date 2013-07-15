#include <iostream>
#include <cmath>
using namespace std;

const int inchesPerFoot(12);
const double metersPerInch(0.0254);
const double poundsPerKg(2.2);

int main()
{
	int inches(0);
	int feet(0);
	int pounds(0);
	double height(0.0);
	double weight(0.0);
	double bmi(0.0);
//Part 1
	cout << "Please enter your height in integer inches: __\b\b";
	cin >> inches;

	cout << "Your height is " << inches / inchesPerFoot << " feet and " << inches % inchesPerFoot << " inches.\n\n\n\n";
//Part 2
	cout << "Please enter your height in integer feet and inches:\n";
	cout << "Feet: __\b\b";
	cin >> feet;
	cout << "Inches: __\b\b";
	cin >> inches;
	cout << "Please enter your weight in integer pounds:\n";
	cout << "Pounds: ___\b\b\b";
	cin >> pounds;

	inches += feet * inchesPerFoot;
	height = inches * metersPerInch;
	weight = pounds / poundsPerKg;
	bmi = weight / pow(height, 2);

	cout << "Your BMI is " << bmi;

	cin.get();
	cin.get();
	return 0;
}

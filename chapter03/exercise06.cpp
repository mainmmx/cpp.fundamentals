#include <iostream>
using namespace std;

const double milesPerHundredKilometers(62.14);
const double gallonsPerLiter(1 / 3.875);

int main()
{
	double euStyle(0.0);
	double usStyle(0.0);

	cout << "Enter an automobile gasoline consumption figure in the European style (liters per 100 kilometers): ";
	cin >> euStyle;

	usStyle = milesPerHundredKilometers / (euStyle * gallonsPerLiter);

	cout << "An automobile gasoline consumption figure in the U.S.style (miles per gallon) is " << usStyle;

	cin.get();
	cin.get();
	return 0;
}

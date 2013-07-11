#include <iostream>
using namespace std;

const int amountAstronomicalUnitsInOneLightYear = 63240;

double LightYears2AstronomicalUnits(double lightYears);

int main()
{
	double lightYears = 0.0;
	double astronomicalUnits = 0.0;

	cout << "Enter the number of light years: ";
	cin >> lightYears;

	astronomicalUnits = LightYears2AstronomicalUnits(lightYears);

	cout << lightYears << " light years = " << astronomicalUnits << " astronomical units.";

	cin.get();
	cin.get();
	return 0;
}

double LightYears2AstronomicalUnits(double lightYears)
{
	return lightYears * amountAstronomicalUnitsInOneLightYear;
}

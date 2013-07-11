#include <iostream>
using namespace std;

const int amountMonthsInOneYear = 12;

int Years2Months(int y);

int main()
{
	int years = 0;
	int months = 0;

	cout << "Enter your age: ";
	cin >> years;

	months = Years2Months(years);

	cout << "Your age in months is " << months << ".";

	cin.get();
	cin.get();
	return 0;
}

int Years2Months(int y)
{
	return y * amountMonthsInOneYear;
}

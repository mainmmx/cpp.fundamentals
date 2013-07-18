#include <iostream>
using namespace std;

const int kSize = 3;

double min(double a, double b)
{
	return (a < b ? a : b);
}

int main()
{
	double incomeGrades[kSize] = {5000.0, 10000.0, 20000.0};
	double taxGrades[kSize] = {0.0, 0.1, 0.15};
	double income = 0.0, tax = 0.0;
	int i = 0;

	cout << "Enter income (tvarp): ";

	while ((cin >> income) && (income >= 0))
	{
		for (i = 0; (income > 0) && (i < kSize); ++i)
		{
			tax += taxGrades[i] * min (income, incomeGrades[i]);
			income -= incomeGrades[i];
		}

		if ((income > 0) && (i == kSize))
			tax += 0.2 * income;

		cout << "Tax is " << tax << " tvarp" << endl;

		tax = 0.0;
		cout << "Enter income: ";
	}

	cin.get();
	cin.get();
	return 0;
}


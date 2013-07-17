#include <iostream>
#include <string>
using namespace std;

const int kMonthsPerYear = 12;
const int kYears = 3;

int main()
{
	string months[kMonthsPerYear] = {"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"};
	int sales[kYears][kMonthsPerYear];
	int totalSum = 0;

	for (int i = 0; i < kYears; ++i)
	{
		cout << "Year " << (2000 + i) << endl;

		for (int j = 0; j < kMonthsPerYear; ++j)
		{
			cout << "Sales in " << months[j] << ": ";
			cin >> sales[i][j];
		}

		cout << endl;
	}

	for (int i = 0; i < kYears; ++i)
	{
		int sum = 0;

		for (int j = 0; j < kMonthsPerYear; ++j)
		{
			sum += sales[i][j];
		}

		cout << "Sales in " << (2000 + i) << " year: " << sum << endl;
		totalSum += sum;
	}

	cout << "Total sales: " << totalSum;

	cin.get();
	cin.get();
	return 0;
}

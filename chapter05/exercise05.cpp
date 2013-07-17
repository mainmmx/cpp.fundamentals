#include <iostream>
#include <string>
using namespace std;

const int kMonthsPerYear = 12;

int main()
{
	string months[kMonthsPerYear] = {"January", "February", "March", "April", "May", "June",
									 "July", "August", "September", "October", "November", "December"};
	int sales[kMonthsPerYear];
	int sum = 0;

	for (int i = 0; i < kMonthsPerYear; ++i)
	{
		cout << "Sales in " << months[i] << ": ";
		cin >> sales[i];
		sum += sales[i];
	}

	cout << "Total sales: " << sum;

	cin.get();
	cin.get();
	return 0;
}

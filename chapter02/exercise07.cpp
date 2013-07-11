#include <iostream>
using namespace std;

void PrintTime (int hours, int minutes);

int main()
{
	int hours = 0;
	int minutes = 0;

	cout << "Enter the number of hours: ";
	cin >> hours;

	cout << "Enter the number of minutes: ";
	cin >> minutes;

	PrintTime(hours, minutes);

	cin.get();
	cin.get();
	return 0;
}

void PrintTime (int hours, int minutes)
{
	cout << "Time: " << hours << ":" << minutes;
}

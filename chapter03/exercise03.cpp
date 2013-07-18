#include <iostream>
using namespace std;

const int secondsPerMinute = 60;
const int minutesPerHour = 60;
const int hoursPerDay = 24;

int main()
{
	long long totalSeconds = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	int days = 0;

	cout << "Enter the number of seconds: ";
	cin >> totalSeconds;

	seconds =  totalSeconds % secondsPerMinute;

	minutes = (totalSeconds / secondsPerMinute) % minutesPerHour;

	hours   = (totalSeconds / secondsPerMinute / minutesPerHour) % hoursPerDay;

	days    =  totalSeconds / secondsPerMinute / minutesPerHour / hoursPerDay;

	cout << totalSeconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	cin.get();
	cin.get();
	return 0;
}

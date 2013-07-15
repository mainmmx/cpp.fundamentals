#include <iostream>
using namespace std;

const int secondsPerMinute(60);
const int minutesPerHour(60);
const int hoursPerDay(24);

int main()
{
	long long fullSeconds(0);
	long long saveFullSeconds(0);
	int seconds(0);
	int minutes(0);
	int hours(0);
	int days(0);

	cout << "Enter the number of seconds: ";
	cin >> fullSeconds;
	saveFullSeconds = fullSeconds;

	fullSeconds -= (seconds = fullSeconds % secondsPerMinute);
	fullSeconds -= (minutes = fullSeconds / secondsPerMinute % minutesPerHour);
	fullSeconds -= (hours = fullSeconds / secondsPerMinute / minutesPerHour % hoursPerDay);
	days = fullSeconds / secondsPerMinute / minutesPerHour / hoursPerDay;

	cout << saveFullSeconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	cin.get();
	cin.get();
	return 0;
}

#include <iostream>
using namespace std;

const int secondsPerMinute(60);
const int minutesPerDegree(60);

int main()
{
	double degrees(0.0);
	double minutes(0.0);
	double seconds(0.0);
	double result(0.0);

	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;

	result = degrees + (minutes + (seconds / secondsPerMinute)) / minutesPerDegree;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << result << " degrees";

	cin.get();
	cin.get();
	return 0;
}

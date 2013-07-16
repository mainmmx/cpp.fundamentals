#include <iostream>
#include <array>
using namespace std;

const int kSize = 3;

int main()
{
	array<double, kSize> seconds;
	double sum = 0.0;
	int i = 0;

	cout << "Please enter " << kSize << " times for the 40-meter dash in seconds" << endl;
	for (int i = 0; i < kSize; i++)
	{
		cout << i + 1 << ": ";
		cin >> seconds[i];
		sum += seconds[i];
	}

	cout << endl << "The times are:" << endl;
	for (int i = 0; i < kSize; i++)
	{
		cout << seconds[i] << " seconds" << endl;
	}
	cout << "The average time is " << sum / kSize << " seconds";

	cin.get();
	cin.get();
	return 0;
}

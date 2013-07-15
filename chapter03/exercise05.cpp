#include <iostream>
using namespace std;

int main()
{
	double kilometers(0);
	double liters(0);

	cout << "How many kilometers you have driven? ";
	cin >> kilometers;
	cout << "How many liters of petrol you have used? ";
	cin >> liters;

	cout << "Your car has gotten " << 100.0 * liters / kilometers << " liters per 100 kilometers.";

	cin.get();
	cin.get();
	return 0;
}

#include <iostream>
#include <array>
using namespace std;

const int kArraySize = 10;

int main()
{
	array<double, kArraySize> donations;
	double donation = 0.0, avg = 0.0;
	int i = 0, count = 0;

	for (i = 0; i < kArraySize; )
	{
		cout << "Donation #" << i + 1 << ": ";

		if (!(cin >> donation))
			break;

		donations[i++] = donation;
	}

	for (int j = 0; j < i; ++j)
		avg += donations[j];

	if(i)
		avg /= i;

	for (int j = 0; j < i; ++j)
		if (donations[j] > avg)
			++count;

	cout << "Average donation is " << avg << endl;
	cout << count << " donations are larger than the average";

	cin.clear();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	double x,y,h;

	do
	{
		cout << "Enter X and Y (space separated): ";
		cin >> x >> y;

		h = ((x + y) == 0)
						? 0.0
						: 2.0 * x * y / (x + y);

		cout << "Harmonic = " << h << endl;
	}
	while ((0 != x) && (0 != y));

	cout << "Bye!";

	cin.get();
	cin.get();
	return 0;
}

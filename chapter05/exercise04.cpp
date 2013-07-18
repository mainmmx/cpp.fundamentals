#include <iostream>
using namespace std;

int main()
{
	int years = 0;
	double daphneInitial = 100;
	double daphne = daphneInitial;
	double cleo = 100;

	do
	{
		daphne += daphneInitial * 0.1;
		cleo += cleo * 0.05;

		++years;
	}
	while (cleo <= daphne);

	cout << "Years = " << years << endl;
	cout << "Daphne = " << daphne << endl;
	cout << "Cleo = " << cleo << endl;

	cin.get();
	return 0;
}

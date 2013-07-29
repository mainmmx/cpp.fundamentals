#include <iostream>
using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
	double total, choices, total2;

	cout << "Enter the total number of choices on the game card and "
			"the number of picks allowed.\n"
			"Also enter a range for meganumber picking (1-__):\n";
	while ((cin >> total >> choices >> total2) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices) * probability(total2, 1);
		cout << " of winning.\n";
		cout << "Next three numbers (q to quit): ";
	}

	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ;

	return result;
}

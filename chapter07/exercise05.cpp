#include <iostream>
using namespace std;

long int Factorial(int n);

int main()
{
	int n = 0;

	cout << "Input n (q to quit): ";
	while ((cin >> n) && (n >= 0))
	{
		cout << n << "! = " << Factorial(n) << endl;

		cout << "Input n (q to quit): ";
	}

	cout << "Bye!";
	cin.get();
	cin.get();
	return 0;
}

long int Factorial(int n)
{
	return ((0 == n)
					? 1
					: n * Factorial(n - 1));
}

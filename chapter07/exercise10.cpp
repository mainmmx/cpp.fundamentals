#include <iostream>
using namespace std;

const int amountOfFunctions = 3;

double calculate(double, double, double (*pf)(double, double));
double add(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

int main()
{
	double x, y;
	double (*pf[amountOfFunctions])(double, double) = {add, multiply, divide};
	const char * functionNames[amountOfFunctions] = {" add ", " multiply ", " divide "};

	cout << "\nEnter X and Y (q to quit): \n";
	while (cin >> x >> y)
	{
		for (int i = 0; i < amountOfFunctions; ++i)
		{
			cout << x << functionNames[i] << y << " = " << calculate(x, y, pf[i]) << endl;
		}

		cout << "\nEnter X and Y (q to quit): \n";
	}

	cin.get();
	cin.get();
	return 0;
}

double calculate(double x, double y, double (*pf)(double x, double y))
{
	return pf(x, y);
}

double add(double x, double y)
{
	return x + y;
}

double multiply(double x, double y)
{
	return x * y;
}

double divide(double x, double y)
{
	return (0 == y)
					? 0
					: x / y;
}

#include <iostream>
const int Max = 5;

double * fill_array(double ar[], double * limit);
void show_array(const double ar[], double * n);
void revalue(double r, double ar[], double * n);

int main()
{
	using namespace std;
	double properties[Max];

	double * size = fill_array(properties, properties+Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}

	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

double * fill_array(double ar[], double * limit)
{
	using namespace std;
	double temp;
	double * i;
	int j = 0;
	for (i = ar; i < limit; i++)
	{
		cout << "Enter value #" << ++j << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*i = temp;
	}
	return i;
}

void show_array(const double ar[], double * n)
{
	using namespace std;
	int j = 0;
	for (const double * i = ar; i < n; i++)
	{
		cout << "Property #" << ++j << ": $";
		cout << *i << endl;
	}
}

void revalue(double r, double ar[], double * n)
{
	for (double * i = ar; i < n; i++)
		*i *= r;
}

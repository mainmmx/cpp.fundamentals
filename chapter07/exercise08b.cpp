#include <iostream>
using namespace std;

const int Seasons = 4;

struct _expenses
{
	double items[Seasons];
};

const char * Snames[Seasons] =
{"Spring", "Summer", "Fall", "Winter"};

void fill(double pa[], int size);
void show(const double da[], int size);

int main()
{
	_expenses expenses;

	fill(expenses.items, Seasons);
	show(expenses.items, Seasons);

	cin.get();
	cin.get();
	return 0;
}

void fill(double pa[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}

void show(const double da[], int size)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < size; i++)
	{
		cout << Snames[i] << ": $" << da[i] << '\n';
		total += da[i];
	}
	cout << "Total: $" << total << '\n';
}

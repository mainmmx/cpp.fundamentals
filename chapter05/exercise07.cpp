#include <iostream>
#include <string>
using namespace std;

struct _car
{
	string make;
	int year;
};

int main()
{
	int size = 0;

	cout << "How many cars in catalog? ";
	cin >> size;
	cin.get();

	_car *cars = new _car[size];

	for (int i = 0; i < size; ++i)
	{
		cout << "Car #" << (i + 1) << ":" << endl;
		cout << "Please enter the make: ";
		getline(cin, cars[i].make);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
		cin.get();
	}

	cout << endl << "Here is your collection:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << cars[i].year << " " << cars[i].make << endl;
	}

	cin.get();
	delete [] cars;
	return 0;
}

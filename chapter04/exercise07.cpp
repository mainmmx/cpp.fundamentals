#include <iostream>
using namespace std;

const int kBufferSize = 100 + 1;

struct _pizza
{
	char companyName[kBufferSize];
	int diameter;
	double weight;
};

int main()
{
	_pizza pizza;

	cout << "CompanyName: ";
	cin.getline(pizza.companyName, kBufferSize);
	cout << "Diameter: ";
	cin >> pizza.diameter;
	cout << "Weight: ";
	cin >> pizza.weight;

	cout << endl;
	cout << "companyName: " << pizza.companyName << endl;
	cout << "diameter: " << pizza.diameter << endl;
	cout << "weight: " << pizza.weight << endl;

	cin.get();
	cin.get();
	return 0;
}

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
	_pizza *ps_pizza = new _pizza;

	cout << "Diameter: ";
	(cin >> ps_pizza->diameter).get();
	cout << "CompanyName: ";
	cin.getline(ps_pizza->companyName, kBufferSize);
	cout << "Weight: ";
	cin >> ps_pizza->weight;

	cout << endl;
	cout << "companyName: " << ps_pizza->companyName << endl;
	cout << "diameter: " << ps_pizza->diameter << endl;
	cout << "weight: " << ps_pizza->weight << endl;

	cin.get();
	cin.get();
	delete ps_pizza;
	return 0;
}

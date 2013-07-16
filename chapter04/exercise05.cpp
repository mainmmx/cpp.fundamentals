#include <iostream>
using namespace std;

struct CandyBar
{
	char brandName[100];
	double weight;
	int calories;
};

int main()
{
	CandyBar snack = {"Mocha Munch", 2.3, 350};

	cout << "brandName: " << snack.brandName << endl;
	cout << "weight: " << snack.weight << endl;
	cout << "calories: " << snack.calories << endl;

	cin.get();
	return 0;
}

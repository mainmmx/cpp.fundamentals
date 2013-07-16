#include <iostream>
using namespace std;

const int kSize = 3;

struct CandyBar
{
	char brandName[100];
	double weight;
	int calories;
};

int main()
{
	int i = 0;
	CandyBar snacks[kSize] = {{"Mocha Munch", 2.3, 350},
							  {"foo foo", 3.4, 340},
							  {"bar bar", 5.6, 560}};

	for (i = 0; i < kSize; i++)
	{
		cout << "brandName: " << snacks[i].brandName << endl;
		cout << "weight: " << snacks[i].weight << endl;
		cout << "calories: " << snacks[i].calories << endl << endl;
	}

	cin.get();
	return 0;
}

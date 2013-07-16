#include <iostream>
#include <cstring>
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
	CandyBar *snacks = new CandyBar[kSize];

	strcpy(snacks[0].brandName, "Mocha Munch");
	snacks[0].weight = 2.3;
	snacks[0].calories = 350;

	strcpy(snacks[1].brandName, "foo foo");
	snacks[1].weight = 3.4;
	snacks[1].calories = 340;

	strcpy(snacks[2].brandName, "bar bar");
	snacks[2].weight = 5.6;
	snacks[2].calories = 560;

	for (i = 0; i < kSize; i++)
	{
		cout << "brandName: " << snacks[i].brandName << endl;
		cout << "weight: " << snacks[i].weight << endl;
		cout << "calories: " << snacks[i].calories << endl << endl;
	}

	cin.get();
	delete[] snacks;
	return 0;
}

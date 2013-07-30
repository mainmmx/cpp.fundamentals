#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar
{
	char name[100];
	double weight;
	int calories;
};

void FillStruct(CandyBar & candy, const char * name = "Millennium Munch", double weight = 2.85, int calories = 350);
void ShowStruct(const CandyBar & candy);

int main()
{
	CandyBar candy;

	FillStruct(candy);
	ShowStruct(candy);

	FillStruct(candy, "Bar");
	ShowStruct(candy);

	FillStruct(candy, "123", 250);
	ShowStruct(candy);

	FillStruct(candy, "Foo", 150.0, 1000);
	ShowStruct(candy);

	cin.get();
	return 0;
}

void FillStruct(CandyBar & candy, const char * name, double weight, int calories)
{
	strcpy(candy.name, name);
	candy.weight = weight;
	candy.calories =calories;
}

void ShowStruct(const CandyBar & candy)
{
	cout << "\nCandyBar\n";
	cout << "Name: " << candy.name << endl;
	cout << "Weight: " << candy.weight << endl;
	cout << "Calories: " << candy.calories << endl;
}

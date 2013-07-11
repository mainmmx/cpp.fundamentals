#include <iostream>
using namespace std;

const int amountYardsInOneFurlong = 220;

int Furlongs2Yards(int f);

int main()
{
	int furlongs = 0;
	int yards = 0;

	cout << "Enter the distance in furlongs: ";
	cin >> furlongs;

	yards = Furlongs2Yards(furlongs);

	cout << furlongs << " furlongs are " << yards << " yards";

	cin.get();
	cin.get();
	return 0;
}

int Furlongs2Yards(int f)
{
	return f * amountYardsInOneFurlong;
}

#include <iostream>
using namespace std;

int main()
{
	long long worldPopulation(0);
	long long USAPopulation(0);

	cout << "Enter the world's population: ";
	cin >> worldPopulation;
	cout << "Enter the population of the US: ";
	cin >> USAPopulation;

	cout << "The population of the US is " << 100.0 * USAPopulation / worldPopulation << "% of the world population." << endl;
	cout << "You can use the Internet to get more recent figures.";

	cin.get();
	cin.get();
	return 0;
}

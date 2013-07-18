#include <iostream>
using namespace std;

const int kBufferSize = 101;

struct _contributor
{
	char name[kBufferSize];
	double contribution;
};

int main()
{
	int numberOfContributors = 0;
	int grandPatrons = 0;
	int patrons = 0;

	cout << "The number of contributors: ";
	cin >> numberOfContributors;

	_contributor *contributors = new _contributor[numberOfContributors];

	for (int i = 0; i < numberOfContributors; ++i)
	{
		cout << "\nContributor #" << i + 1 << endl;
		cout << "Name: ";
		cin.get();
		cin.getline(contributors[i].name, kBufferSize);
		cout << "Contribution: ";
		cin >> contributors[i].contribution;
	}

	cout << "\nGrand Patrons:\n";
	for (int i = 0; i < numberOfContributors; ++i)
	{
		if (contributors[i].contribution > 10000)
		{
			cout << contributors[i].name << endl;
			++grandPatrons;
		}
	}
	if (!grandPatrons)
		cout << "none.\n";

	cout << "\nPatrons:\n";
	for (int i = 0; i < numberOfContributors; ++i)
	{
		if (contributors[i].contribution <= 10000)
		{
			cout << contributors[i].name << endl;
			++patrons;
		}
	}
	if (!patrons)
		cout << "none.\n";

	cin.get();
	cin.get();
	delete [] contributors;
	return 0;
}

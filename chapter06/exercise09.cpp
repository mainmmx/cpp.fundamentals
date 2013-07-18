#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int kBufferSize = 101;
const char fileName[] = "exercise09.txt";

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
	ifstream inFile;
	char ch;

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << fileName << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	inFile >> numberOfContributors;

	_contributor *contributors = new _contributor[numberOfContributors];

	for (int i = 0; i < numberOfContributors; ++i)
	{
		inFile.get();
		inFile.getline(contributors[i].name, kBufferSize);
		inFile >> contributors[i].contribution;
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
	delete [] contributors;
	inFile.close();
	return 0;
}

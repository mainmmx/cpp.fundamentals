#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const char fileName[] = "exercise08.txt";

int main()
{
	ifstream inFile;
	int count = 0;
	char ch;

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << fileName << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	inFile.get(ch);
	while (inFile.good())
	{
		++count;
		inFile.get(ch);
	}

	cout << "Number of characters in the file " << fileName << " is " << count;

	cin.get();
	inFile.close();
	return 0;
}

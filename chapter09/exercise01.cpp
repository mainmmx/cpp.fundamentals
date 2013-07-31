#include <iostream>
#include"golf.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int size = 0;
	int realsize = 0;

	cout << "\nEnter size of array: ";
	cin >> size;

	golf *golfs = new golf[size];

	for (realsize = 0; realsize < size; ++realsize)
	{
		cout << "\nItem #" << realsize + 1;

		if (0 == setgolf(golfs[realsize]))
		{
			break;
		}
	}

	cout << "\nInitial values:";
	showarr(golfs, realsize);

	for (int i = 0; i < realsize; ++i)
	{
		handicap(golfs[i], i);
	}

	cout << "\n\nChanged values:";
	showarr(golfs, realsize);

	cout << "\n\nDone.";
	cin.get();
	delete[] golfs;
	return 0;
}

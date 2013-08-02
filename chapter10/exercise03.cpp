#include <iostream>
#include "Golf.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int size = 0;
	int realsize = 0;

	cout << "\nEnter size of array: ";
	cin >> size;

	Golf *golfs = new Golf[size];

	for (realsize = 0; realsize < size; ++realsize)
	{
		cout << "\nItem #" << realsize + 1;

		if (0 == golfs[realsize].setgolf())
		{
			break;
		}
	}

	cout << "\nInitial values:";
	golfs[0].showarr(realsize);

	for (int i = 0; i < realsize; ++i)
	{
		golfs[i].sethandicap(i);
	}

	cout << "\n\nChanged values:";
	golfs[0].showarr(realsize);

	cout << "\n\nDone.";
	cin.get();
	delete[] golfs;
	return 0;
}

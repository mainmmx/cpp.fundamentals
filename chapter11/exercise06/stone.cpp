#include "stonewt.h"
#include <iostream>
#include <cfloat>

const int arraySize = 6;
const int initializedItems = 3;

int main()
{
	Stonewt array[arraySize] = { 100, {200, 3.4}, 500 };
	Stonewt minObj(DBL_MAX), maxObj(0);
	Stonewt cmpObj(11, 0.0);
	int cmpNumber = 0;
	double pounds = 0.0;

	for (int i = 0; i < arraySize; ++i)
	{
		if (i >= initializedItems)
		{
			std::cout << "Item #" << i + 1 << " in pounds: ";
			if (!(std::cin >> pounds))
				break;
			array[i] = Stonewt(pounds);
		}

		if (array[i] > maxObj)
			maxObj = array[i];

		if (array[i] < minObj)
			minObj = array[i];

		if (array[i] >= cmpObj)
			++cmpNumber;
	}

	std::cout << "Max = ";
	maxObj.show_stn();

	std::cout << "Min = ";
	minObj.show_stn();

	std::cout << "Number of items, which are bigger than 11 stounes = " << cmpNumber;

	return 0;
}

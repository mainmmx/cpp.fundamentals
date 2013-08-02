#include <iostream>
#include "Sales.h"

using namespace SALES;

int main()
{
	Sales sales1;
	Sales sales2;
	double array[QUARTERS] = {15.6, 36.6, 26.1, 40};

	sales1.set();
	sales2 = Sales(array, 3);

	std::cout << "\nStructure #1";
	sales1.show();
	std::cout << "\nStructure #2";
	sales2.show();

	std::cout << "\n\nDone!";
	std::cin.get();
	return 0;
}

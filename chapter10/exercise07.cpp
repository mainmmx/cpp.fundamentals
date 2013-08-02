#include "Plorg.h"
#include <iostream>

int main()
{
	Plorg plorg;

	std::cout << "\n\nInitial values:";
	plorg.show();

	std::cout << "\n\nCI = 100:";
	plorg.setCI(100);
	plorg.show();

	std::cout << "\n\nCI = 18:";
	plorg.setCI(18);
	plorg.show();

	std::cout << "\n\nDone.";
	std::cin.get();
	return 0;
}

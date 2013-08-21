#include "Cow.h"
#include <iostream>

int main()
{
	Cow cow1;
	Cow cow2("cow2", "hobby2", 123.45);

	std::cout << "\nInitial state\n";
	std::cout << "\ncow1:";
	cow1.ShowCow();
	std::cout << "\ncow2:";
	cow2.ShowCow();

	std::cout << "\ncow1 = cow2\n";
	cow1 = cow2;

	std::cout << "\ncow1:";
	cow1.ShowCow();
	std::cout << "\ncow2:";
	cow2.ShowCow();

	std::cout << "\nCow cow3 = cow2\n";
	Cow cow3 = cow2;

	std::cout << "\ncow2:";
	cow2.ShowCow();
	std::cout << "\ncow3:";
	cow3.ShowCow();

	return 0;
}

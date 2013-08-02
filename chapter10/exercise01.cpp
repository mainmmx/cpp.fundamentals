#include <iostream>
#include "BankAccount.h"

int main()
{
	{
		BankAccount bankAccount1;
		BankAccount bankAccount2 ("Mr. Crowley", "1234567890", 1000.5);

		bankAccount1.show();
		bankAccount2.show();

		bankAccount2.inc(36.6);
		bankAccount2.show();

		bankAccount2.dec(123.45);
		bankAccount2.show();
	}

	std::cout << "\n\nDone!";
	std::cin.get();
	return 0;
}

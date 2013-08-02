#include "Stack.h"
#include <iostream>
#include <string>

void fillInfo(Item & item);
void showInfo(const Item & item);

int main()
{
	using std::cout;
	using std::cin;
	using std::string;

	Stack stack;
	Item item;
	string command = "";
	double sum = 0.0;

	do
	{
		cout << "\nAllowed commands: push, pop, quit (There are " << stack.getFreeSpace() << " free cells in the stack)\n";
		getline(cin, command);
		if ("push" == command)
		{
			fillInfo(item);

			if (stack.push(item))
			{
				cout << "The item has been inserted successfully";
			}
			else
			{
				cout << "The item hasn't been inserted! The stack is FULL!";
			}
		}
		else if ("pop" == command)
		{
			if (stack.pop(item))
			{
				cout << "The item has been extracted successfully";

				showInfo(item);

				sum += item.payment;

				cout << "\nSum = " << sum;
			}
			else
			{
				cout << "There is no item to pop it! The stack is EMPTY!";
			}
		}
		else if ("quit" == command)
		{
			break;
		}
		else
		{
			cout << "\nUnrecognized command";
		}
	}
	while (true);

	cout << "\n\nDone.";
	cin.get();
	return 0;
}

void fillInfo(Item & item)
{
	using std::cout;
	using std::cin;

	double payment;

	cout << "Fullname = ";
	cin.getline(item.fullname, 35);

	cout << "Payment = ";
	while (!(cin >> payment))
	{
		cin.clear();
		cin.get();
		cout << "Payment = ";
	}
	cin.get();

	item.payment = payment;
}

void showInfo(const Item & item)
{
	using std::cout;

	cout << "\nFullname = " << item.fullname;
	cout << "\nPayment = " << item.payment;
}

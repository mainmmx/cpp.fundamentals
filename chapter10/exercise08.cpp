#include "List.h"
#include <iostream>
#include <string>

void fillInfo(Item & item);
void showInfo(const Item & item);

inline void square(Item & item){ item *= item; }

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	List list;
	Item item;
	string command = "";

	do
	{
		cout << "\nAllowed commands: push, isempty, isfull, visit, show, quit (There are " << list.getFreeSpace() << " free cells in the list): ";
		getline(cin, command);
		if ("push" == command)
		{
			fillInfo(item);

			if (list.push(item))
			{
				cout << "\nThe item has been inserted successfully\n";
			}
			else
			{
				cout << "\nThe item hasn't been inserted! The list is FULL!\n";
			}
		}
		else if ("isempty" == command)
		{
			cout << (list.isempty() ? "Yes" : "No") << endl;
		}
		else if ("isfull" == command)
		{
			cout << (list.isfull() ? "Yes" : "No") << endl;
		}
		else if ("visit" == command)
		{
			list.visit(square);
		}
		else if ("show" == command)
		{
			std::cout << "\nList:\t";
			list.show();
			std::cout << std::endl;
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

	double value;

	cout << "Value = ";
	while (!(cin >> value))
	{
		cin.clear();
		cin.get();
		cout << "Value = ";
	}
	cin.get();

	item = value;
}

void showInfo(const Item & item)
{
	std::cout << "\nValue = " << item;
}

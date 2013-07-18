#include <iostream>
using namespace std;

const int kBufferkArraySize = 101;
const int kArraySize = 5;

// Benevolent Order of Programmers name structure
struct bop
{
	char fullname[kBufferkArraySize]; // real name
	char title[kBufferkArraySize]; // job title
	char bopname[kBufferkArraySize]; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
	bop members[kArraySize] =
	{
			{"Wimp Macho", "Middle Programmer", "BUTCH", 0},
			{"Raki Rhodes", "Junior Programmer", "DEADMAN", 1},
			{"Celia Laiter", "QA Tester", "MIPS", 2},
			{"Hoppy Hipman", "Analyst Trainee", "AMD", 1},
			{"Pat Hand", "Senior Programmer", "LOOPY", 2},
	};

	char ch;

	cout << "Benevolent Order of Programmers Report\n"
			"a. display by name    b. display by title\n"
			"c. display by bopname d. display by preference\n"
			"q. quit\n"
			"Enter your choice: ";

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'a':
			for (int i = 0; i < kArraySize; ++i)
				cout << members[i].fullname << endl;
			break;
		case 'b':
			for (int i = 0; i < kArraySize; ++i)
				cout << members[i].title << endl;
			break;
		case 'c':
			for (int i = 0; i < kArraySize; ++i)
				cout << members[i].bopname << endl;
			break;
		case 'd':
			for (int i = 0; i < kArraySize; ++i)
			{
				switch (members[i].preference)
				{
				case 0:
					cout << members[i].fullname << endl;
					break;
				case 1:
					cout << members[i].title << endl;
					break;
				case 2:
					cout << members[i].bopname << endl;
					break;
				default:
					break;
				}
			}
			break;
		case 'q':
			cout << "Bye!";
			break;
		default:
			cout << "Please enter a a, b, c, d or q: ";
			continue;
		}

		if (ch == 'q')
			break;

		cout << "Next choice: ";
	}

	cin.get();
	cin.get();
	return 0;
}

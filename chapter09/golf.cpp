#include <iostream>
#include"golf.h"
#include<cstring>

void setgolf(golf & g, const char * name, int hc)
{
	memset(g.fullname, 0, sizeof (char));
	strncpy(g.fullname, name, Len - 1);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cout;
	using std::cin;

	char fullname[Len] = "";
	int handicap = 0;

	cin.get();

	cout << "\nFullname : ";
	cin.get(fullname, Len);

	if ('\0' == fullname[0])
	{
		return 0;
	}
	else
	{
		cout << "Handicap : ";
		if (cin >> handicap)
		{
			setgolf(g, fullname, handicap);

			return 1;
		}
	}

	return 0;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	using std::cout;

	cout << "\t\t" << g.fullname << "\t\t" << g.handicap;
}

void showarr(const golf arr[], const int & n)
{
	using std::cout;

	for (int i = 0; i < n; ++i)
	{
		cout << "\nItem #" << i + 1;
		showgolf(arr[i]);
	}
}

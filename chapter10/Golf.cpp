/*
 * Golf.cpp
 *
 *  Created on: Aug 1, 2013
 *      Author: maksym.mykhailov
 */

#include "Golf.h"
#include <iostream>
#include <cstring>

Golf::Golf()
{
	memset(m_fullname, 0, sizeof (char));
	m_handicap = 0;
}

Golf::~Golf() {}

Golf::Golf(const char * name, int hc)
{
	memset(m_fullname, 0, sizeof (char));
	strncpy(m_fullname, name, LEN);
	m_handicap = hc;
}

int Golf::setgolf()
{
	using std::cout;
	using std::cin;

	char fullname[LEN] = "";
	int handicap = 0;

	cin.get();

	cout << "\nFullname : ";
	cin.get(fullname, LEN);

	if ('\0' == fullname[0])
	{
		return 0;
	}
	else
	{
		cout << "Handicap : ";
		if (cin >> handicap)
		{
			*this = Golf(fullname, handicap);

			return 1;
		}
	}

	return 0;
}

void Golf::sethandicap(int hc)
{
	m_handicap = hc;
}

void Golf::showgolf() const
{
	using std::cout;

	cout << "\t\t" << m_fullname << "\t\t" << m_handicap;
}

void Golf::showarr(int n) const
{
	using std::cout;

	for (int i = 0; i < n; ++i)
	{
		cout << "\nItem #" << i + 1;
		(this + i)->showgolf();
	}
}

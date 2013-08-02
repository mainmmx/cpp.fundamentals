/*
 * Person.cpp
 *
 *  Created on: Aug 1, 2013
 *      Author: maksym.mykhailov
 */

#include "Person.h"
#include <cstring>
#include <iostream>

//Person::Person() {}

Person::Person(const std::string & ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
	fname[LIMIT] = '\0';
}

Person::~Person() {}

void Person::Show() const
{
	std::cout << fname << " " << lname;
}

void Person::FormalShow() const
{
	std::cout << lname << ", " << fname;
}

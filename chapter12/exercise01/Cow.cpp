/*
 * Cow.cpp
 *
 *  Created on: 21 рту. 2013 у.
 *      Author: maksym.mykhailov
 */

#include "Cow.h"
#include <iostream>
#include <cstring>

Cow::Cow() : name{0}, hobby(NULL), weight(0.0)
{
	hobby = new char[1];
	hobby[0] = '\0';

}

Cow::Cow(const char * nm, const char * ho, double wt) : name{0}, hobby(NULL), weight(0.0)
{
	strncpy(name, nm, nameLen);
	name[nameLen] = '\0';

	hobby = new char[strlen(ho) + 1];
	strncpy(hobby, ho, strlen(ho));
	hobby[strlen(ho)] = '\0';

	weight = wt;
}

Cow::Cow(const Cow & c) : name{0}, hobby(NULL), weight(0.0)
{
	strncpy(name, c.name, nameLen);
	name[nameLen] = '\0';

	hobby = new char [strlen(c.hobby) + 1];
	strncpy(hobby, c.hobby, strlen(c.hobby));
	hobby[strlen(c.hobby)] = '\0';

	weight = c.weight;}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
		return *this;

	strncpy(name, c.name, nameLen);
	name[nameLen] = '\0';

	delete [] hobby;
	hobby = new char [strlen(c.hobby) + 1];
	strncpy(hobby, c.hobby, strlen(c.hobby));
	hobby[strlen(c.hobby)] = '\0';

	weight = c.weight;

	return *this;
}

void Cow::ShowCow() const
{
	std::cout <<	"\nName = " << name <<
					"\nHobby = " << hobby <<
					"\nWeight = " << weight << std::endl;
}

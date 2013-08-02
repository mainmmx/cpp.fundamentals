/*
 * Plorg.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#include "Plorg.h"
#include <cstring>
#include <iostream>

Plorg::Plorg(const char * name)
{
	memset(m_name, 0, sizeof(char));
	strncpy(m_name, name, LEN);
	m_name[LEN] = '\0';
	m_ci = DEFAULT_CI;

}

Plorg::~Plorg()
{
	;
}

void Plorg::setCI(int ci)
{
	m_ci = ci;
}

void Plorg::show() const
{
	std::cout << "\nName = " << m_name;
	std::cout << "\nCI = " << m_ci;
}

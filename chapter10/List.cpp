/*
 * List.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#include "List.h"
#include <iostream>

List::List()
{
	top = 0;
	std::cout << "\n\nNew list has been created\n";
}

List::~List()
{
	;
}

bool List::isempty() const
{
	return top == 0;
}

bool List::isfull() const
{
	return top == MAX;
}

bool List::push(const Item & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

void List::visit(void (*pf)(Item &))
{
	for (int i = 0; i < top; ++i)
	{
		pf(items[i]);
	}
}

void List::show() const
{
	for (int i = 0; i < top; ++i)
	{
		std::cout << items[i] << "\t";
	}
}

/*
 * Move.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#include "Move.h"
#include <iostream>

Move::Move(double a, double b)
{
	x = a;
	y = b;

}

Move::~Move()
{
	;
}

void Move::showmove() const
{
	using std::cout;

	cout << "\nX = " << x << "\tY = " << y;
}

Move Move::add(const Move & m) const
{
	double newx = m.x + this->x;
	double newy = m.y + this->y;

	Move *newobj = new Move(newx, newy);

	return *newobj;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

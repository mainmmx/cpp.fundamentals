/*
 * complex0.h
 *
 *  Created on: 20 рту. 2013 у.
 *      Author: maksym.mykhailov
 */

#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex0
{
private:
	double m_real;
	double m_imgn;
public:
	complex0();
	complex0(double r, double i);
	~complex0();
	complex0 operator+(const complex0 & c) const;
	complex0 operator-(const complex0 & c) const;
	complex0 operator*(const complex0 & c) const;
	friend complex0 operator*(double x, const complex0 & c);
	complex0 operator~() const;
	friend std::ostream & operator<<(std::ostream & os, const complex0 & c);
	friend std::istream & operator>>(std::istream & is, complex0 & c);
};

#endif /* COMPLEX0_H_ */

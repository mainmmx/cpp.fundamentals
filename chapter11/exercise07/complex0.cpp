/*
 * complex0.cpp
 *
 *  Created on: 20 рту. 2013 у.
 *      Author: maksym.mykhailov
 */

#include "complex0.h"

complex0::complex0() : m_real(0.0), m_imgn(0.0)
{
	;

}

complex0::complex0(double r, double i) : m_real(0.0), m_imgn(0.0)
{
	m_real = r;
	m_imgn = i;
}

complex0::~complex0()
{
	;
}

complex0 complex0::operator+(const complex0 & c) const
{
	return complex0(m_real + c.m_real,
					m_imgn + c.m_imgn);
}

complex0 complex0::operator-(const complex0 & c) const
{
	return complex0(m_real - c.m_real,
					m_imgn - c.m_imgn);
}

complex0 complex0::operator*(const complex0 & c) const
{
	return complex0(((m_real * c.m_real) - (m_imgn * c.m_imgn)),
					((m_real * c.m_imgn) + (m_imgn * c.m_real)));
}

complex0 operator*(double x, const complex0 & c)
{
	return complex0(x * c.m_real,
					x * c.m_imgn);
}

complex0 complex0::operator~() const
{
	return complex0(m_real,
					-m_imgn);
}

std::ostream & operator<<(std::ostream & os, const complex0 & c)
{
	std::cout << "(" << c.m_real << "," << c.m_imgn << "i)";

	return os;
}

std::istream & operator>>(std::istream & is, complex0 & c)
{
	double r = 0.0, i = 0.0;

	std::cout << "real: ";
	if (!(std::cin >> r))
		return is;

	std::cout << "imaginary: ";
	if (!(std::cin >> i))
		return is;

	c = complex0(r, i);

	return is;
}

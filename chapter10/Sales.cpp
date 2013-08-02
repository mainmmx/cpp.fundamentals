/*
 * Sales.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#include "Sales.h"
#include <iostream>

namespace SALES
{
	Sales::Sales()
	{
		for (int i = 0; i < QUARTERS; ++i)
			m_sales[i] = 0.0;

		m_average = 0.0;
		m_max = 0.0;
		m_min = 0.0;
	}

	Sales::Sales(const double ar[], int n)
	{
		const int size = min(QUARTERS, n);
		double min = ar[0];
		double max = ar[0];
		double sum = ar[0];
		double avg = 0;

		for (int i = 0; i < QUARTERS; ++i)
		{
			m_sales[i] = 0;
		}

		for (int i = 0; i < size; ++i)
		{
			m_sales[i] = ar[i];
		}

		for (int i = 1; i < QUARTERS; ++i)
		{
			sum += m_sales[i];

			if (m_sales[i] < min)
			{
				min = m_sales[i];
			}

			if (m_sales[i] > max)
			{
				max = m_sales[i];
			}
		}

		avg = sum / QUARTERS;

		m_average = avg;
		m_max = max;
		m_min = min;
	}

	Sales::~Sales()
	{
		;
	}


	void Sales::set()
	{
		double values[QUARTERS] = {0};
		int i = 0;

		std::cout << "Input sales for 4 quarters (q to interrupt)\n";

		for (i = 0; i < QUARTERS; ++i)
		{
			std::cout << "Quarter #" << i + 1 << ": ";

			if (!(std::cin >> values[i]))
			{
				break;
			}
		}

		*this = Sales(values, i);
	}

	void Sales::show() const
	{
		std::cout << "\nSales =\t";
		for (int i = 0; i < QUARTERS; ++i)
			std::cout << "\t" << m_sales[i];

		std::cout << "\nAverage =\t" << m_average;
		std::cout << "\nMax =\t\t" << m_max;
		std::cout << "\nMin =\t\t" << m_min << std::endl;
	}
}

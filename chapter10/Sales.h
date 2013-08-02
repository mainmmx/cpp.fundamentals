/*
 * Sales.h
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#ifndef SALES_H_
#define SALES_H_

namespace SALES
{
	const int QUARTERS = 4;

	class Sales
	{
	private:
		double m_sales[QUARTERS];
		double m_average;
		double m_max;
		double m_min;

	public:
		Sales();
		Sales(const double ar[], int n);
		~Sales();
		void set();
		void show() const;
		inline int min(int a, int b) { return a < b ? a : b; }
	};
}

#endif /* SALES_H_ */

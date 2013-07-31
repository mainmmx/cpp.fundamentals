#include<iostream>
#include"sales.h"

using namespace std;

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		const int size = min(QUARTERS, n);
		double min = ar[0];
		double max = ar[0];
		double sum = ar[0];
		double avg = 0;

		for (int i = 0; i < QUARTERS; ++i)
		{
			s.sales[i] = 0;
		}

		for (int i = 0; i < size; ++i)
		{
			s.sales[i] = ar[i];
		}

		for (int i = 1; i < QUARTERS; ++i)
		{
			sum += s.sales[i];

			if (s.sales[i] < min)
			{
				min = s.sales[i];
			}

			if (s.sales[i] > max)
			{
				max = s.sales[i];
			}
		}

		avg = sum / QUARTERS;

		s.average = avg;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales & s)
	{
		double values[QUARTERS] = {0};
		int i = 0;

		cout << "Input sales for 4 quarters (q to interrupt)\n";

		for (i = 0; i < QUARTERS; ++i)
		{
			cout << "Quarter #" << i + 1 << ": ";

			if (!(cin >> values[i]))
			{
				break;
			}
		}

		setSales(s, values, i);
	}

	void showSales(const Sales & s)
	{
		cout << "\nSales =\t";
		for (int i = 0; i < QUARTERS; ++i)
			cout << "\t" << s.sales[i];

		cout << "\nAverage =\t" << s.average;
		cout << "\nMax =\t\t" << s.max;
		cout << "\nMin =\t\t" << s.min << endl;
	}
}

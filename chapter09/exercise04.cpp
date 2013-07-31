#include <iostream>
#include"sales.h"

using namespace std;
using namespace SALES;

int main()
{
	Sales sales1;
	Sales sales2;
	double array[QUARTERS] = {15.6, 36.6, 26.1, 40};

	setSales(sales1);
	setSales(sales2, array, 3);

	cout << "\nStructure #1";
	showSales(sales1);
	cout << "\nStructure #2";
	showSales(sales2);

	cout << "\n\nDone!";
	cin.get();
	return 0;
}

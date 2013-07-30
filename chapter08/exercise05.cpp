#include <iostream>
using namespace std;

const int kArraySize = 5;

template <typename T>
T max5(const T array[])
{
	T max = array[0];

	for (int i = 1; i < kArraySize; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return max;
}

template <typename T>
void show5(const T array[])
{
	for (int i = 0; i < kArraySize; ++i)
	{
		cout << array[i] << '\t';
	}
}

int main()
{
	const int array1[kArraySize] = {5, -9, 0, 100, 37};
	const double array2[kArraySize] = {3.7, -8.4, 0.6, 1.09, 36.6};

	int max1 = max5(array1);
	double max2 = max5(array2);

	cout << "\narray1 of int   : ";
	show5(array1);

	cout << "\narray2 of double: ";
	show5(array2);

	cout << "\nmax1 = " << max1;
	cout << "\nmax2 = " << max2;

	cout << "\n\nDone!";
	cin.get();
	return 0;
}

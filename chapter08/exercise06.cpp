#include <iostream>
#include <cstring>
using namespace std;

const int kArrayOfIntSize = 6;
const int kArrayOfDoubleSize = 4;
const int kArrayOfStringsSize = 5;



template <typename T>
T maxn(const T array[], const int & n);

template <typename T>
char* maxn(const T * array[], const int & n);

template <>
char* maxn(const char * array[], const int & n);



template <typename T>
void shown(const T array[], const int & n);

template <typename T>
void shown(const T * array[], const int & n);

template <>
void shown(const char * array[], const int & n);



int main()
{
	const int arrayOfInt[kArrayOfIntSize] = {6, 0, -4, 18, 27, 14};
	const double arrayOfDouble[kArrayOfDoubleSize] = {6.3, -9.48, 36.6, 18.45};
	const char *arrayOfStrings[kArrayOfStringsSize] =
	{
			"Yesterday, all my troubles seemed so far away",
			"Now it looks as though they're here to stay",
			"Oh, I believe in yesterday",
			"Suddenly, I'm not half the man I used to be",
			"There's a shadow hanging over me."
	};

	int maxInt = maxn(arrayOfInt, kArrayOfIntSize);
	double maxDouble = maxn(arrayOfDouble, kArrayOfDoubleSize);
	char *maxString = maxn(arrayOfStrings, kArrayOfStringsSize);

	cout << "\narray1 of int   : ";
	shown(arrayOfInt, kArrayOfIntSize);

	cout << "\narray2 of double: ";
	shown(arrayOfDouble, kArrayOfDoubleSize);

	cout << "\narray3 of char* : \n";
	shown(arrayOfStrings, kArrayOfStringsSize);

	cout << "\nmax1 = " << maxInt;
	cout << "\nmax2 = " << maxDouble;
	cout << "\nmax3 = " << hex << int(maxString) << dec << " : " << maxString << "\t\t\t(length = " << strlen(maxString) << ")";

	cout << "\n\nDone!";
	cin.get();
	return 0;
}

template <typename T>
T maxn(const T array[], const int & n)
{
	T max = array[0];

	for (int i = 1; i < n; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return max;
}

//template <typename T>
//char* maxn(const T * array[], const int & n)
//{
//	;
//}

template <>
char* maxn(const char * array[], const int & n)
{
	int max = int(array[0]);
	int maxlen = strlen(array[0]);

	for (int i = 1; i < n; ++i)
	{
		if (strlen(array[i]) > maxlen)
		{
			max = int(array[i]);
		}
	}

	return (char*)max;
}

template <typename T>
void shown(const T array[], const int & n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << '\t';
	}
}

//template <typename T>
//void shown(const T * array[], const int & n)
//{
//	;
//}

template <>
void shown(const char * array[], const int & n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << hex << int(array[i]) << dec << " : " << array[i] << "\t\t\t(length = " << strlen(array[i]) << ")\n";
	}
}

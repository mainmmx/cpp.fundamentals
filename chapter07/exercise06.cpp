#include <iostream>
using namespace std;

const int kArraySize = 10;

int Fill_array(double array[], int maxSize);
void Show_array(const double array[], int size);
void Reverse_array(double array[], int size);

int main()
{
	double array[kArraySize] = {0};
	int size = 0;

	size = Fill_array(array, kArraySize);

	cout << "\nInitial state: \n";
	Show_array(array, size);

	Reverse_array(array + 1, size - 2);

	cout << "\n\nState after reversing: \n";
	Show_array(array, size);

	cin.get();
	cin.get();
	return 0;
}


int Fill_array(double array[], int maxSize)
{
	int i = 0, value = 0;

	cout << "Enter values up to " << kArraySize << " items (or q to interrupt):\n";

	for (i = 0; i < maxSize; ++i)
	{
		cout << "Value #" << i + 1 << ": ";
		if (!(cin >> value))
		{
			break;
		}
		array[i] = value;
	}

	return i;
}

void Show_array(const double array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << '\t';
	}
}

void Reverse_array(double array[], int size)
{
	double temp;

	for (int i = 0; i < size / 2; ++i)
	{
		temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
}

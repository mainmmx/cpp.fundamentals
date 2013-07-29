#include <iostream>
using namespace std;

const int kArraySize = 10;

int FillArray(int results[], int maxSize);
double CalcAvg(const int results[], int size);
void PrintResult(const int results[], int size, double avg);

int main()
{
	int results[kArraySize] = {0};
	int resultsCount = 0;
	double avg = 0.0;

	resultsCount = FillArray(results, kArraySize);
	avg = CalcAvg(results, resultsCount);
	PrintResult(results, resultsCount, avg);

	cin.clear();
	cin.get();
	cin.get();
	return 0;
}

int FillArray(int results[], int maxSize)
{
	int i = 0, result = 0;

	cout << "Enter results up to " << kArraySize << " values (or q to interrupt):\n";

	for (i = 0; i < maxSize; ++i)
	{
		cout << "Result #" << i + 1 << ": ";
		if (!(cin >> result))
		{
			break;
		}
		results[i] = result;
	}

	return i;
}

double CalcAvg(const int results[], int size)
{
	double avg = 0.0;
	double sum = 0.0;

	for (int i = 0; i < size; ++i)
	{
		sum += results[i];
	}

	avg = (0 == size)
					? 0
					:sum / size;

	return avg;
}

void PrintResult(const int results[], int size, double avg)
{
	cout << "\nResults:\t";

	for (int i = 0; i < size; ++i)
	{
		cout << results[i] << '\t';
	}

	cout << "\nAverage value is: " << avg;
}

#include <iostream>
using namespace std;

int main()
{
	int rows = 0;

	cout << "Enter number of rows: ";
	cin >> rows;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			cout << ((j < rows - i - 1) ? '.' : '*');
		}
		cout << endl;
	}

	cin.get();
	cin.get();
	return 0;
}

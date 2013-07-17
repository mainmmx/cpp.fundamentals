#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;

	do
	{
		cout << "Enter a number: ";
		cin >> n;
		cout << "The cumulative sum is " << (sum += n) << endl;
	}
	while (n);

	cin.get();
	cin.get();
	return 0;
}

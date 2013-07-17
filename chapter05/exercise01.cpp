#include <iostream>
using namespace std;

int main()
{
	int a, b, sum;

	cout << "Enter smaller integer value: ";
	cin >> a;
	cout << "Enter bigger integer value: ";
	cin >> b;

	for (sum = 0 ; a <= b; ++a)
		sum += a;

	cout << "Sum is " << sum;

	cin.get();
	cin.get();
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "";
	int total = 0;

	cout << "Enter words (to stop, type the word done):" << endl;

	do
	{
		++total;
		cin >> str;
	}
	while (str != "done");

	cout << "You entered a total of " << --total << " words.";

	cin.get();
	cin.get();
	return 0;
}

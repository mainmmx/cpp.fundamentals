#include <iostream>
#include <cstring>
using namespace std;

const int kBufferSize = 101;

int main()
{
	char str[kBufferSize] = "";
	int total = 0;

	cout << "Enter words (to stop, type the word done):" << endl;

	do
	{
		++total;
		cin >> str;
	}
	while (strcmp(str, "done"));

	cout << "You entered a total of " << --total << " words.";

	cin.get();
	cin.get();
	return 0;
}

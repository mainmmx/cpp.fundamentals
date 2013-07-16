#include <iostream>
#include <cstring>
using namespace std;

const int kBufferSize = 100 + 1;

int main()
{
	char firstName[kBufferSize] = "";
	char lastName[kBufferSize] = "";
	char resultString[kBufferSize] = "Here is the information in a single string: ";

	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;

	strcat (resultString, lastName);
	strcat (resultString, ", ");
	strcat (resultString, firstName);

	cout << resultString;

	cin.get();
	cin.get();
	return 0;
}

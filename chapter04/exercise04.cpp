#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstName = "";
	string lastName = "";
	string resultString = "Here is the information in a single string: ";

	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;

	resultString += lastName + ", " + firstName;

	cout << resultString;

	cin.get();
	cin.get();
	return 0;
}

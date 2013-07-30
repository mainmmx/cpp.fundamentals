#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{

	string str;

	cout << "Enter a string (q to quit): ";
	while ((getline(cin, str)) && (str != "q"))
	{
		for (int i = 0; i < str.length(); ++i)
		{
			str[i] = toupper(str[i]);
		}

		cout << str << endl;

		cout << "Next string (q to quit): ";
	}

	cout << "Bye!";
	cin.get();
	return 0;
}

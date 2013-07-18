#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char ch;

	while (cin.get(ch) && (ch != '@'))
	{
		if (isdigit(ch))
			continue;

		cout << (ch = isupper(ch) ? tolower(ch) : toupper(ch));
	}

	cin.get();
	cin.get();
	return 0;
}

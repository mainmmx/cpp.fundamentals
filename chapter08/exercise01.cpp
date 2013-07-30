#include <iostream>
using namespace std;

static int count = 0;
const char *str = "Foo Bar";

void PrintStr(const char * str);
void PrintStr(const char * str, int n);

int main()
{
	PrintStr(str);
	PrintStr(str, 0);
	PrintStr(str, 10);

	cin.get();
	return 0;
}

void PrintStr(const char * str)
{
	cout << str << endl;

	++count;
}

void PrintStr(const char * str, int n)
{
	if (0 != n)
	{
		for (int i = 0; i < count; ++i)
		{
			cout << str << endl;
		}
	}

	++count;
}

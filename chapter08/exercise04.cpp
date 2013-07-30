#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
	char * str;
	int ct;
};

void set(stringy & structure, const char * text);
void show(const stringy & structure, const int & count = 1);
void show(const char * str, const int & count = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);

	show(beany);
	show(beany, 2);

	testing[0] = 'D';
	testing[1] = 'u';

	show(testing);
	show(testing, 3);

	show("\nDone!");
	cin.get();
	return 0;
}

void set(stringy & structure, const char * text)
{
	memset(&structure, 0, sizeof(stringy));

	structure.str = new char[strlen(text) + 1];

	if (0 != structure.str) {
		strcpy(structure.str, text);
		structure.ct = strlen(structure.str);
	}
}

void show(const stringy & structure, const int & count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << endl << structure.str;
	}
}

void show(const char * str, const int & count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << endl << str;
	}
}

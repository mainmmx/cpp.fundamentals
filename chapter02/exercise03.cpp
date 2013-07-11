#include <iostream>
using namespace std;

void PrintSentence1();
void PrintSentence2();

int main()
{
	PrintSentence1();
	PrintSentence1();

	PrintSentence2();
	PrintSentence2();

	cin.get();
	return 0;
}

void PrintSentence1()
{
	cout << "Three blind mice" << endl;
}

void PrintSentence2()
{
	cout << "See how they run" << endl;
}

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int kBufferSize = 101;

bool IsVowel (char ch);

int main()
{
	int vowels = 0;
	int consonants = 0;
	int others = 0;
	char buffer[kBufferSize] = "";

	cout << "Enter words (q to quit):\n";
	cin >> buffer;

	while (strcmp(buffer, "q"))
	{
		if (isalpha(buffer[0]))
			IsVowel(buffer[0]) ? ++vowels : ++consonants;
		else
			++others;

		cin >> buffer;
	}

	cout << vowels << " words beginning with vowels\n";
	cout << consonants << " words beginning with consonants\n";
	cout << others << " others";

	cin.get();
	cin.get();
	return 0;
}

bool IsVowel (char ch)
{
	switch(ch)
	{
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		return true;
	default:
		break;
	}

	return false;
}

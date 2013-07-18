#include <iostream>
using namespace std;

int main()
{
	char ch;

	cout << "Please enter one of the following choices:\n"
			"c) carnivore p) pianist\n"
			"t) tree g) game\n";

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'c':
			cout << "A tiger is a carnivore.";
			break;
		case 'p':
			cout << "Ludwig van Beethoven is a pianist.";
			break;
		case 't':
			cout << "A maple is a tree.";
			break;
		case 'g':
			cout << "A football is a game.";
			break;
		default:
			cout << "Please enter a c, p, t, or g: ";
			continue;
		}

		cout << "\nBye!";
		break;
	}

	cin.get();
	cin.get();
	return 0;
}

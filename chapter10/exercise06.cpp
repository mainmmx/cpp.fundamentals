#include "Move.h"
#include <iostream>

int main()
{
	using std::cout;

	Move move1;
	Move move2(1,2);
	Move move3(3,4);

	cout << "\n\nItem1";
	move1.showmove();

	cout << "\n\nItem2";
	move2.showmove();

	cout << "\n\nItem3";
	move3.showmove();

	move1 = move2.add(move3);
	cout << "\n\nItem1 = Item2 + Item3";
	move1.showmove();

	cout << "\n\nReseting of Item1";
	move1.reset();
	move1.showmove();

	return 0;
}

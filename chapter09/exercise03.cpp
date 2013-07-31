#include <iostream>
#include <cstring>
#include <new>

using namespace std;

const int kBufferSize = 1024;
char buffer[kBufferSize];

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
//part 1
	chaff *pchaff1 = new (buffer) chaff[2];

	strcpy(pchaff1[0].dross, "Foo");
	pchaff1[0].slag = 1;

	strcpy(pchaff1[1].dross, "Bar");
	pchaff1[1].slag = 2;

	for (int i = 0; i < 2; ++i)
	{
		cout << "\nItem #" << i + 1 << " :\t" << pchaff1[i].dross << "\t" << pchaff1[i].slag;
	}
//part 2
	cout << endl;

	chaff *pchaff2 = new chaff[2];

	strcpy(pchaff2[0].dross, "FooFoo");
	pchaff2[0].slag = 11;

	strcpy(pchaff2[1].dross, "BarBar");
	pchaff2[1].slag = 22;

	for (int i = 0; i < 2; ++i)
	{
		cout << "\nItem #" << i + 1 << " :\t" << pchaff2[i].dross << "\t" << pchaff2[i].slag;
	}

	cout << "\n\nDone!";
	cin.get();
	delete[] pchaff2;
	return 0;
}

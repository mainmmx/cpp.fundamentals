#include <iostream>
using namespace std;

struct _box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void PrintStruct(const _box box);
void CalcVolume (_box *box);

int main()
{
	_box box = {"Foo Bar", 10.0, 20.5, 30.8, 0.0};

	CalcVolume(&box);
	PrintStruct(box);

	cin.get();
	return 0;
}

void CalcVolume (_box *box)
{
	box->volume = box->height * box->width * box->length;
}

void PrintStruct(const _box box)
{
	cout << "Box's parameters:\n";
	cout << "Maker = " << box.maker << endl;
	cout << "Height = " << box.height << endl;
	cout << "Width = " << box.width << endl;
	cout << "Length = " << box.length << endl;
	cout << "Volume = " << box.volume << endl;
}

#include <stdio.h>

typedef struct
{
	int hh;
	int mm;
	int ss;
	int fr;
} _label;

char *format(int frameNumber, char *label);

int main()
{
	const int arraySize = 13;
	const int test[arraySize] = { 0, 29, 30, 1799, 1800, 1801, 3597, 3598, 5396, 17981, 17982, 19781, 19782 };
	const int labelSize = 11; //"00:00:00;00"
	char label[labelSize + 1] = "";

	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d - %s\n", test[i], format(test[i], label));
	}

	return 0;
}

char *format(int frameNumber, char *label)
{
	_label s_label = {0};

	int _10MinPeriod = frameNumber / 17982;
	s_label.hh = _10MinPeriod / 6;
	s_label.mm = (_10MinPeriod % 6) * 10;

	int totalFramesInLast10Min = frameNumber % 17982;

	for (int i = 0; i < totalFramesInLast10Min; ++i)
	{
		++s_label.fr;

		if (s_label.fr == 30)
		{
			++s_label.ss;
			s_label.fr = 0;
		}

		if (s_label.ss == 60)
		{
			++s_label.mm;
			s_label.ss = 0;
			s_label.fr = 2;
		}
	}

	sprintf(label, "%.2d:%.2d:%.2d;%.2d", s_label.hh, s_label.mm, s_label.ss, s_label.fr);

	return label;
}

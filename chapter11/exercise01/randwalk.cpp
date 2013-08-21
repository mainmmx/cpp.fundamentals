#include <iostream>
#include <fstream> /* MY EDIT */
#include <cstdlib>
#include <ctime>
#include "vect.h"
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
/* MY EDIT { */
	ofstream outFile;
	outFile.open("out.txt");
/* MY EDIT } */
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl; /* MY EDIT */

		while (result.magval() < target)
		{
			outFile << steps << ": " << result << endl; /* MY EDIT */

			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
				"has the following location:\n";
		cout << result << endl;
/* MY EDIT { */
		outFile << "After " << steps << " steps, the subject "
				"has the following location:\n";
		outFile << result << endl;
/* MY EDIT } */
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
				<< result.magval()/steps << endl;
/* MY EDIT { */
		outFile << " or\n" << result << endl;
		outFile << "Average outward distance per step = "
				<< result.magval()/steps << endl;
/* MY EDIT } */
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	outFile.close(); /* MY EDIT */
	return 0;
}

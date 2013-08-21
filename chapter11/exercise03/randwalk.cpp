// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include <limits.h> /* MY EDIT */
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

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
/* MY EDIT { */
		cout << "Enter trials' count: ";
		int n;
		if (!(cin >> n))
			break;

		unsigned long stepsMax = 0;
		unsigned long stepsMin = ULONG_MAX;
		unsigned long stepsSum = 0;

		for (int i = 0; i < n; ++i)
		{
			steps = 0;
			result.reset(0.0, 0.0);
/* MY EDIT } */
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
/* MY EDIT { */
			stepsSum += steps;

			if (steps > stepsMax)
				stepsMax = steps;

			if (steps < stepsMin)
				stepsMin = steps;
		}

		double stepsAvg = stepsSum / n;

		cout << "\nMax = " << stepsMax <<
				"\nMin = " << stepsMin <<
				"\nAvg = " << stepsAvg << endl;
		//		cout << "After " << steps << " steps, the subject "
		//				"has the following location:\n";
		//		cout << result << endl;
		//		result.polar_mode();
		//		cout << " or\n" << result << endl;
		//		cout << "Average outward distance per step = "
		//				<< result.magval()/steps << endl;
		//		steps = 0;
		//		result.reset(0.0, 0.0);
/* MY EDIT } */
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}

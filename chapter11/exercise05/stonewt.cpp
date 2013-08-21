// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode form /*= DBL_LBS*/) /**/
{
	mode = form; /**/
	stone = int (lbs) / Lbs_per_stn;    // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode form /*= STN*/) /**/
{
	mode = form; /**/
	stone = stn;
	pds_left = lbs;
	pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
	mode = STN; /**/
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
//void Stonewt::show_stn() const
//{
//	cout << stone << " stone, " << pds_left << " pounds\n";
//}
//
// show weight in pounds
//void Stonewt::show_lbs() const
//{
//	cout << pounds << " pounds\n";
//}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
	if (s.mode == Stonewt::STN)
	{
		os << s.stone << " stone, " << s.pds_left << " pounds\n";
	}
	else if (s.mode == Stonewt::INT_LBS)
	{
		os << s.pounds << " pounds\n"; /*!!!*/
	}
	else if (s.mode == Stonewt::DBL_LBS)
	{
		os << s.pounds << " pounds\n";
	}
	else
	{
		os << "Vector object mode is invalid";
	}

	return os;
}

// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
	Stonewt incognito = 275; // uses constructor to initialize
	Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
/**/
//	incognito.show_stn();
	incognito.mode_stn();
	cout << incognito;
/**/
	cout << "The detective weighed ";
/**/
//	wolfe.show_stn();
	wolfe.mode_stn();
	cout << wolfe;
/**/
	cout << "The President weighed ";
/**/
//	taft.show_lbs();
	taft.mode_dbl_lbs();
	cout << taft;
/**/
	incognito = 276.8;      // uses constructor for conversion
	taft = 325;             // same as taft = Stonewt(325);
	cout << "After dinner, the celebrity weighed ";
/**/
//	incognito.show_stn();
	incognito.mode_stn();
	cout << incognito;
/**/
	cout << "After dinner, the President weighed ";
/**/
//	taft.show_lbs();
	taft.mode_dbl_lbs();
	cout << taft;
/**/
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
/**/
//		st.show_stn();
//		st.mode_stn(); /*!!!*/
		cout << st;
/**/
	}
}

// stock20.cpp -- augmented version
#include <iostream>
#include <string.h> /**/
#include "stock20.h"
using namespace std;
// constructors
Stock::Stock()        // default constructor
{
	company = NULL; /**/
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
/**/
//	company = co;
	int len = co.length();
	company = new char[len + 1];
	strncpy(company, co.data(), len);
	company[len] = '\0';
/**/
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
				<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

/**/
Stock::Stock(const Stock & s)
{
	int len = strlen(s.company);
	company = new char[len + 1];
	strncpy(company, s.company, len);
	company[len] = '\0';

	shares = s.shares;

	share_val = s.share_val;

	total_val = s.total_val;
}
/**/

// class destructor
Stock::~Stock()        // quiet class destructor
{
	delete [] company; /**/
}

// other methods
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
				<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
				<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
				<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

//void Stock::show() const
//{
//	using std::cout;
//	using std::ios_base;
//	// set format to #.###
//	ios_base::fmtflags orig =
//			cout.setf(ios_base::fixed, ios_base::floatfield);
//	std::streamsize prec = cout.precision(3);
//
//	cout << "Company: " << company
//			<< "  Shares: " << shares << '\n';
//	cout << "  Share Price: $" << share_val;
//	// set format to #.##
//	cout.precision(2);
//	cout << "  Total Worth: $" << total_val << '\n';
//
//	// restore original format
//	cout.setf(orig, ios_base::floatfield);
//	cout.precision(prec);
//}

/**/
std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	// set format to #.###
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = os.precision(3);

	os <<	"Company: " << s.company <<
			" Shares: " << s.shares << '\n' <<
			" Share Price: $" << s.share_val;

	// set format to #.##
	os.precision(2);
	os << "  Total Worth: $" << s.total_val << '\n';

	// restore original format
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}

Stock & Stock::operator=(const Stock & s)
{
	if (this == &s)
		return *this;

	delete [] company;
	int len = strlen(s.company);
	company = new char[len + 1];
	strncpy(company, s.company, len);
	company[len] = '\0';

	shares = s.shares;

	share_val = s.share_val;

	total_val = s.total_val;

	return *this;
}
/**/

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

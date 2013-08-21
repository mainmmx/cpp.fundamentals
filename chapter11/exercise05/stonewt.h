// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
public:
	enum Mode {STN, INT_LBS, DBL_LBS}; /**/
private:
	Mode mode; /**/
	enum {Lbs_per_stn = 14};      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
public:
	Stonewt(double lbs, Mode form = DBL_LBS);          // constructor for double pounds /**/
	Stonewt(int stn, double lbs, Mode form = STN); // constructor for stone, lbs /**/
	Stonewt();                    // default constructor
	~Stonewt();
/**/
//	void show_lbs() const;        // show weight in pounds format
//	void show_stn() const;        // show weight in stone format
	void mode_stn() { mode = STN; }				// set mode to STN
	void mode_int_lbs() { mode = INT_LBS; }		// set mode to INT_LBS
	void mode_dbl_lbs() { mode = DBL_LBS; }		// set mode to DBL_LBS
	Stonewt operator+(const Stonewt & b) const { return Stonewt(pounds + b.pounds); }
	Stonewt operator-(const Stonewt & b) const { return Stonewt(pounds - b.pounds); }
	Stonewt operator-() const { return Stonewt(-pounds); }
	Stonewt operator*(double n) const { return Stonewt(pounds * n); }
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
/**/
};
#endif

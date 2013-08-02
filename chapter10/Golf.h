/*
 * Golf.h
 *
 *  Created on: Aug 1, 2013
 *      Author: maksym.mykhailov
 */

#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
	static const int LEN = 40;
	char m_fullname[LEN];
	int m_handicap;
public:
	Golf();
	Golf(const char * name, int hc);
	~Golf();
	int setgolf();
	void sethandicap(int hc);
	void showgolf() const;
	void showarr(int n) const;
};

#endif /* GOLF_H_ */

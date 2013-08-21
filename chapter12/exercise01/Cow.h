/*
 * Cow.h
 *
 *  Created on: 21 рту. 2013 у.
 *      Author: maksym.mykhailov
 */

#ifndef COW_H_
#define COW_H_

class Cow {
	static const int nameLen = 19;
	char name[nameLen + 1];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; // display all cow data
};

#endif /* COW_H_ */

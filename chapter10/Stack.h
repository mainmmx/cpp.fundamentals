/*
 * Stack.h
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#ifndef STACK_H_
#define STACK_H_

struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	Stack();
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
	inline int getFreeSpace() { return MAX - top; }
};

#endif /* STACK_H_ */

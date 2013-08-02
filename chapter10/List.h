/*
 * List.h
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class List
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	List();
	~List();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	void visit(void (*pf)(Item &));
	void show() const;
	inline int getFreeSpace() { return MAX - top; }
};

#endif /* LIST_H_ */

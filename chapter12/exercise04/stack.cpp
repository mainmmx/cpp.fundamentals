// stack.cpp -- Stack member functions

#include "stack.h"
#include <iostream> /**/

/**/
//Stack::Stack()    // create an empty stack
//{
//	top = 0;
//}

Stack::Stack(int n /*= MAX*/) : pitems(NULL), size(0), top(0)
{
	size = n;
	pitems = new Item[size];
}

Stack::Stack(const Stack & st) : pitems(NULL), size(0), top(0)
{
	size = st.size;

	pitems = new Item[size];
	for(int i = 0; i < size; ++i)
		pitems[i] = st.pitems[i];

	top = st.top;
}

Stack::~Stack()
{
	delete [] pitems;
}
/**/

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == /*MAX*/size;
}

bool Stack::push(const Item & item) 
{
	if (top < /*MAX*/size)
	{
/**/
//		items[top++] = item;
		pitems[top++] = item;

/**/
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
/**/
//		item = items[--top];
		item = pitems[--top];
/**/
		return true;
	}
	else
		return false;
}

/**/
Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
		return *this;

	size = st.size;

	delete [] pitems;
	pitems = new Item[size];
	for(int i = 0; i < size; ++i)
		pitems[i] = st.pitems[i];

	top = st.top;

	return *this;
}
/**/

/*
 * Plorg.h
 *
 *  Created on: Aug 2, 2013
 *      Author: maksym.mykhailov
 */

#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	static const int LEN = 20;
	static const int DEFAULT_CI = 50;
	char m_name[LEN];
	int m_ci;
public:
	Plorg(const char * name = "Plorga");
	~Plorg();
	void setCI(int ci);
	void show() const;
};

#endif /* PLORG_H_ */

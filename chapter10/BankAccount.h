/*
 * BankAccount.h
 *
 *  Created on: Jul 31, 2013
 *      Author: maksym.mykhailov
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include<string>

class BankAccount
{
private:
	std::string m_name;
	std::string m_number;
	double m_balance;
public:
	BankAccount();
	BankAccount(const std::string & name, const std::string & number, double balance = 0.0);
	~BankAccount();
	void show() const;
	void inc(double sum);
	void dec(double sum);
};

#endif /* BANKACCOUNT_H_ */

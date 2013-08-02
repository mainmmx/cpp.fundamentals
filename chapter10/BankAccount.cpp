/*
 * BankAccount.cpp
 *
 *  Created on: Jul 31, 2013
 *      Author: maksym.mykhailov
 */

#include <iostream>
#include <string>
#include "BankAccount.h"

BankAccount::BankAccount()
{
	std::cout << "\nThis is constructor BankAccount::BankAccount()\n";

	m_name = "";
	m_number = "";
	m_balance = 0.0;
}

BankAccount::BankAccount(const std::string & name, const std::string & number, double balance)
{
	std::cout << "\nThis is constructor BankAccount::BankAccount(const std::string & name, const std::string & number, double balance)\n";

	m_name = name;
	m_number = number;
	m_balance = balance;
}

BankAccount::~BankAccount()
{
	std::cout << "\nThis is destructor BankAccount::~BankAccount()\n";
}

void BankAccount::show() const
{
	std::cout << "\nBankAccount:";
	std::cout << "\nm_name = " << m_name;
	std::cout << "\nm_number = " << m_number;
	std::cout << "\nm_balance = " << m_balance << std::endl;
}

void BankAccount::inc(double sum)
{
	std::cout << "\ninc balance for " << sum;

	m_balance += sum;
}

void BankAccount::dec(double sum)
{
	std::cout << "\ndec balance for " << sum;

	m_balance -= sum;
}

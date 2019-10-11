#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "SmartDate.h"
#include <vector>
#include "../Utils/StringUtils.h"

using namespace std;

class Transaction
{
	bool operator==(const Transaction &rhs);
public:
	Transaction(string who, SmartDate when, double amount) :
		m_sCustomer(who),
		m_date(when),
		m_dAmount(amount) {}
	Transaction(string transaction);

public:
	string who() { return m_sCustomer; }
	SmartDate when() { return m_date; }
	double amount() { return m_dAmount; }

private:
	string m_sCustomer;
	SmartDate m_date;
	double m_dAmount = 0.0;
};

bool Transaction::operator==(const Transaction &rhs)
{
	if (m_sCustomer == rhs.m_sCustomer && m_date == rhs.m_date && m_dAmount == rhs.m_dAmount)
		return true;

	return false;
}

inline Transaction::Transaction(string transaction) :
	m_date(SmartDate(2000, 1, 1))
{
	vector<string> vec = StringUtils::split(transaction, " ");
	m_sCustomer = vec.at(0);
	m_date = vec.at(1);
	m_dAmount = stod(vec.at(2));
}

#endif // !TRANSACTION_H

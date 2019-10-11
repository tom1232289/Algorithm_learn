#pragma once

#ifndef COUNTER_H
#define COUNTER_H

#include <string>

using namespace std;

class Counter
{
public:
	Counter(string id) :
		m_sName(id) {}

public:
	void increment() { ++m_iCount; }
	int tally() { return m_iCount; }

private:
	string m_sName;
	int m_iCount = 0;
};

#endif // !COUNTER_H

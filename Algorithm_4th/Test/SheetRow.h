#pragma once

#ifndef SHEET_ROW_H
#define SHEET_ROW_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class SheetRow
{
public:
	SheetRow(string name, int firstValue, int secondValue) :
		m_sName(name),
		m_iFirstValue(firstValue),
		m_iSecondValue(secondValue),
		m_dThridValue(m_iFirstValue / m_iSecondValue) {
	
		int i = 0;
	}

public:
	void print(ostream &os) {
		os << m_sName << "\t" << m_iFirstValue << "\t" << m_iSecondValue << "\t" << fixed << setprecision(3) << m_dThridValue;
	}

private:
	string m_sName;
	int m_iFirstValue = 0;
	int m_iSecondValue = 0;
	double m_dThridValue = 0.0;
};

#endif // !SHEET_ROW_H

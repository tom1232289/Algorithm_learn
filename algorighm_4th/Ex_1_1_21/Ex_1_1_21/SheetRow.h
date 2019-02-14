#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class CSheetRow
{
public:
	void print(ostream &os) {
		os << sName << " ";
		os << fixed << setprecision(0) << i << " ";
		os << fixed << setprecision(0) << j << " ";
		os << fixed << setprecision(3) << k;
	}
public:
	string sName;
	double i;
	double j;
	double k;
};
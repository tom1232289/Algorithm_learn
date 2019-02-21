#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class CAccumulate
{
public:
	ostream & print(ostream &os);
public:
	void addDataValue(double val) {
		++N;
		total += val;
	}
	double mean() { return total / N; }
private:
	int N = 0;
	double total = 0;
};
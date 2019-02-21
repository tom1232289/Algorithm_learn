#pragma once

#include <iostream>
#include <QPainter>
#include <string>

using namespace std;

class CVisualAccumulator
{
public:
	CVisualAccumulator(int trials, double max, QPainter &painter);
public:
	void addDataValue(double value);
	double mean() { return m_total / N; }
	ostream &print(ostream &os);
private:
	int N = 0;
	double m_total = 0.0;
	double m_max = 0.0;
	QPainter & m_painter;
};
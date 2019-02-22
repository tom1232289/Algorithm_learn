#pragma once

class Interval1D
{
public:
	Interval1D(double low, double high);
public:
	double length();
	bool contains(double x);
	bool intersect(Interval1D &rhs);
	double getmin() { return min; }
	double getmax() { return max; }
private:
	double min = 0.0;
	double max = 0.0;
};
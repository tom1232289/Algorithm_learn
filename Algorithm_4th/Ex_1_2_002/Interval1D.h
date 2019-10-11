#pragma once

#ifndef INTERVAL1D_H
#define INTERVAL1D_H

// 直线上间隔
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

#endif // !INTERVAL1D_H

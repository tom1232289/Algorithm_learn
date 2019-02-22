#include "Interval1D.h"
#include <algorithm>

Interval1D::Interval1D(double low, double high) :
	min(low),
	max(high)
{
	if (min > max)
		std::swap(min, max);
}

double Interval1D::length()
{
	return max - min;
}

bool Interval1D::contains(double x)
{
	return (x >= min) && (x <= max);
}

bool Interval1D::intersect(Interval1D &rhs)
{
	if (this->min > rhs.max)
		return false;
	if (this->max < rhs.min)
		return false;
	return true;
}
#pragma once

#include <vector>

using namespace std;

class CHistogramInfo
{
public:
	CHistogramInfo(size_t n, double l, double r,vector<double> dvec);
public:
	size_t N = 0;
	double left = 0.0;
	double right = 0.0;
	double interval = 0.0;
	vector<double> dvec;
	vector<double> statistics;
};
#include "HistogramInfo.h"

CHistogramInfo::CHistogramInfo(size_t n, double l, double r, vector<double> dvec) :
	N(n),
	left(l),
	right(r),
	interval((right - left) / N),
	dvec(dvec),
	statistics(N + 1, 0)
{
	for (auto c : dvec) {
		double remain = c - left;
		int idx = remain / interval;
		++statistics[idx];
	}
}
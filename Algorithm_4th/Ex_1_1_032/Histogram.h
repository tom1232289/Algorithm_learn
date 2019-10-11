#pragma once

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

using namespace std;

class HistogramInfo
{
public:
	double left = 0;
	double right = 0;
	int count = 0;
};

class Histogram
{
public:
	static vector<HistogramInfo> GenerateHistograms(int N, double l, double r);
	static void ComputeHistogramsCount(vector<double> &digits, vector<HistogramInfo> &his);
	static vector<double> randomDigitals(double l, double r);
};

vector<HistogramInfo> Histogram::GenerateHistograms(int N, double l, double r)
{
	double interval = (r - l) / N;
	HistogramInfo hi;
	hi.left = l;
	hi.right = hi.left + interval;
	vector<HistogramInfo> his;
	his.emplace_back(hi);

	while (hi.right < r) {
		hi.left = hi.right;
		hi.right = hi.left + interval;
		his.emplace_back(hi);
	}

	return his;
}

void Histogram::ComputeHistogramsCount(vector<double> &digits, vector<HistogramInfo> &his)
{
	for (auto iter = his.begin(); iter != his.end(); ++iter) {
		for (auto c : digits) {
			if (c >= iter->left && c < iter->right) {
				++iter->count;
			}
		}
	}
}

vector<double> Histogram::randomDigitals(double l, double r)
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_real_distribution<double> distribution(l, r);
	uniform_int_distribution<int> distribution_int(0, 10000);
	vector<double> digitals;
	size_t len = distribution_int(gen);
	for (int i = 0; i < len; ++i) {
		digitals.emplace_back(distribution(gen));
	}

	return digitals;
}

#endif // !HISTOGRAM_H

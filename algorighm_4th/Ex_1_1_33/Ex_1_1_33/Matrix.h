#pragma once

#include <vector>

using namespace std;

class CMatrix
{
public:
	static double dot(vector<double> &x, vector<double> &y);
	static vector<vector<double>> multiple(vector<vector<double>> &a, vector<vector<double>> &b);
	static vector<vector<double>> transpose(vector<vector<double>> &a);
	static vector<vector<double>> mult(vector<vector<double>> &a, vector<double> &x);
	static vector<vector<double>> mult(vector<double> &y, vector<vector<double>> &a);
};
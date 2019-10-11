#include "Matrix.h"

double CMatrix::dot(vector<double>& x, vector<double>& y)
{
	// 点乘必须是向量a的长度等于向量b的长度才能运算
	if (x.size() != y.size())
		exit(-1);

	double ret = 0.0;
	for (size_t i = 0; i < x.size(); ++i) {
		ret += x[i] * y[i];
	}
	return ret;
}

vector<vector<double>> CMatrix::multiple(vector<vector<double>>& a, vector<vector<double>>& b)
{
	// a的列数必须等于b的行数
	if (a[0].size() != b.size())
		exit(-1);

	vector<vector<double>> ret(a.size(), vector<double>(b[0].size()));
	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < b[0].size(); ++j) {
			for (size_t k = 0; k < b.size(); ++k) {
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return ret;
}

vector<vector<double>> CMatrix::transpose(const vector<vector<double>>& a)
{
	vector<vector<double>> ret(a[0].size(), vector<double>(a.size()));
	for (size_t i = 0; i < a[0].size(); ++i) {
		for (size_t j = 0; j < a.size(); ++j) {
			ret[i][j] = a[j][i];
		}
	}
	return ret;
}

vector<vector<double>> CMatrix::mult(vector<vector<double>>& a, vector<double>& x)
{
	vector<vector<double>> x2(1, vector<double>(x));	// 将向量转变为只有一行的二维数组
	auto x3 = transpose(x2);
	return multiple(a, x3);
}

vector<vector<double>> CMatrix::mult(vector<double> &y, vector<vector<double>> &a)
{
	vector<vector<double>> y2(1, vector<double>(y));	
	return multiple(y2, a);
}
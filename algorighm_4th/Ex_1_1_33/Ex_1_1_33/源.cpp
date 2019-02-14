#include "Matrix.h"

int main()
{
	vector<double> x = { 1,2,3 };
	vector<double> y = { 4,5,6 };
	auto temp = CMatrix::dot(x, y);

	vector<vector<double>> a = { {1,2,3},{4,5,6} };
	vector<vector<double>> b = { {1,4},{2,5},{3,6} };
	auto temp2 = CMatrix::multiple(a, b);

	auto temp3 = CMatrix::transpose(a);

	vector<double> x1 = { 0,1 };
	auto temp4 = CMatrix::mult(b, x1);

	vector<double> y1 = { 1,2,3,4 };
	auto temp5 = CMatrix::mult(y1, b);

	return 0;
}
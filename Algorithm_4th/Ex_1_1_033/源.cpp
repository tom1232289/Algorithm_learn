#include "Matrix.h"
#include <iostream>

using namespace std;

template <typename T>
void printArray2(const vector<vector<T>> &vec2)
{
	size_t M = vec2.size();
	size_t N = vec2.at(0).size();
	cout << " ";
	for (int i = 0; i < N; ++i) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int i = 0; i < M; ++i) {
		cout << i << "\t";
		for (int j = 0; j < N; ++j) {
			cout << vec2[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	vector<double> x = { 1,2,3 };
	vector<double> y = { 4,5,6 };
	cout << CMatrix::dot(x, y) << endl;

	vector<vector<double>> a = {
		{ 1,2,3 },
		{ 4,5,6 }
	};
	vector<vector<double>> b = {
		{ 1,4 },
		{ 2,5 },
		{ 3,6 }
	};
	auto array2_multiple = CMatrix::multiple(a, b);
	printArray2(array2_multiple);
	cout << endl;

	auto array2_trans = CMatrix::transpose(a);
	printArray2(array2_trans);
	cout << endl;

	vector<double> x1 = { 0,1 };
	auto array2_mult1 = CMatrix::mult(b, x1);
	printArray2(array2_mult1);
	cout << endl;

	vector<double> y1 = { 1,2,3 };
	auto array2_mult2 = CMatrix::mult(y1, b);
	printArray2(array2_mult2);
	cout << endl;

	return 0;
}
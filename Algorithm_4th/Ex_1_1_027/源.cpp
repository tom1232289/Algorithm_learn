#include <iostream>
#include <vector>

using namespace std;

const int ROW = 100;
const int COLUMN = 50;
vector<vector<double>> g_binoArray(ROW + 1, vector<double>(COLUMN + 1, -1.0));

double binomialOptimization(int N, int k, double p)
{
	if (N < 0 || k < 0) {
		return 0.0;
	}

	if (N == 0 && k == 0) {
		if (g_binoArray[0][0] == -1.0) {
			g_binoArray[0][0] = 1.0;
		}
	}
	else {
		if (g_binoArray[N][k] == -1.0) {
			g_binoArray[N][k] = (1.0 - p) * binomialOptimization(N - 1, k, p) + p * binomialOptimization(N - 1, k - 1, p);
		}
	}

	return g_binoArray[N][k];
}

int main()
{
	cout << binomialOptimization(100, 50, 0.25) << endl;

	return 0;
}
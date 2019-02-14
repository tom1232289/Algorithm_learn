#include <iostream>
#include <algorithm>

using namespace std;

const int binom_N = 101;
const int binom_K = 51;
double binom[binom_N][binom_K] = {};

double binomial(int N, int k, double p)
{
	if (N < 0 || k < 0)
		return 0.0;
	else if (N == 0 && k == 0) {
		if (binom[N][k] == -1.0)
			binom[N][k] = 1.0;
	}
	else {
		if (binom[N][k] == -1.0)
			binom[N][k] = (1.0 - p)*binomial(N - 1, k, p) + p * binomial(N - 1, k - 1, p);
	}
	return binom[N][k];
}

int main()
{
	fill(binom[0], binom[0] + binom_N * binom_K, -1.0);
	double temp = binomial(100, 50, 0.25);

	return 0;
}
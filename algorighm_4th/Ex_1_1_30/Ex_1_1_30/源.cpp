#include <iostream>
#include <vector>

using namespace std;

int gcd(int p, int q)
{
	if (q == 0)
		return p;
	int r = p % q;
	return gcd(q, r);
}

vector<vector<bool>> CreateBoolArray(int N)
{
	vector<vector<bool>> b2vec(N, vector<bool>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (gcd(i, j) == 1)
				b2vec[i][j] = true;
			else
				b2vec[i][j] = false;
		}
	}
	return b2vec;
}

int main()
{
	const int N = 3;
	auto temp = CreateBoolArray(N);

	return 0;
}
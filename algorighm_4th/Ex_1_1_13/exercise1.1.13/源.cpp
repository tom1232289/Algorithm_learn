#include <iostream>

using namespace std;

int main()
{
	const int M = 2, N = 3;
	int a[M][N] = { 1,2,3,4,5,6 };
	int b[N][M] = { 0 };
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			b[j][i] = a[i][j];
		}
	}

	return 0;
}
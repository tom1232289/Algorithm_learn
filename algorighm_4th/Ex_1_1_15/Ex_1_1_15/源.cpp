#include <iostream>

using namespace std;

int * histogram(int a[], int M)
{
	int *b = new int(M);
	for (int i = 0; i < M; ++i) {
		int k = 0;
		for (int j = 0; j < M; ++j) {
			if (a[j] == i)
				++k;
		}
		b[i] = k;
	}
	return b;
}

int main()
{
	const int M = 3;
	int a[M] = { 1,2,1 };
	int *b = histogram(a, M);
	int sum = 0;
	for (int i = 0; i < M; ++i) {
		cout << b[i] << endl;
		sum += b[i];
	}
	cout << sum << endl;

	delete b;

	system("pause");
	return 0;
}
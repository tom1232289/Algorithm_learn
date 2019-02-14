#include <iostream>

using namespace std;

long F(int N)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	return F(N - 1) + F(N - 2);
}

const int M = 100;
static double fib[M];
double FibonacciOptimization(int N)
{
	if (N == 0)
		fib[0] = 0;
	else if (N == 1)
		fib[1] = 1;
	else
		fib[N] = fib[N - 1] + fib[N - 2];
	return fib[N];
}

int main()
{
	for (int N = 0; N < 100; N++) {
		cout << N << " " << FibonacciOptimization(N) << endl;
	}

	system("pause");
	return 0;
}
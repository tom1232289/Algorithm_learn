#include <iostream>
#include <vector>
#include <string>

using namespace std;

double Fibonacci(int N)	// long²»¹»´æ£¬»»³Édouble
{
	if (N == 0) return 0;
	if (N == 1) return 1;
	return Fibonacci(N - 1) + Fibonacci(N - 2);
}

const int M = 100;
vector<double> g_dvecFib(M, 0);

double FibonacciOptimization(int N)
{
	if (N == 0) {
		g_dvecFib[0] = 0;
	}
	else if (N == 1) {
		g_dvecFib[1] = 1;
	}
	else {
		g_dvecFib[N] = g_dvecFib[N - 1] + g_dvecFib[N - 2];
	}
	return g_dvecFib[N];
}

int main()
{
	string str;
	for (int N = 0; N < M; N++) {
		str = to_string(N) + " " + to_string(FibonacciOptimization(N));
		cout << str << endl;
	}
	cout << endl;

	return 0;
}
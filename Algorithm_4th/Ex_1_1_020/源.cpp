// 编写一个递归的静态方法计算ln(N!) 的值。

#include <iostream>
#include <cmath>	// 直接用到math库

using namespace std;

double factorial(const int N)
{
	if (N == 0 || N == 1) {
		return 1;
	}
	else {
		return N*factorial(N - 1);
	}
}

double ln(double N)
{
	double a = factorial(N);
	return log(a);
}

int main()
{
	long double a = ln(170);
	cout << a << endl;

	return 0;
}
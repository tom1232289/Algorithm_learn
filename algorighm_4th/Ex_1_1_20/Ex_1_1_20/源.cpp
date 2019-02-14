#include <iostream>
#include <cmath>

using namespace std;

long double factorial(int M)
{
	if (M == 0 || M == 1)
		return 1;
	else
		return M * factorial(M - 1);
}

long double ln(double N)
{
	auto a = factorial(N);
	return log(a);
}

int main()
{
	long double a = ln(170);
	cout << a << endl;

	system("pause");
	return 0;
}
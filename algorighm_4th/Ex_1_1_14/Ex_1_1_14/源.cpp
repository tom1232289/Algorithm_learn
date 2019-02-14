#include <iostream>

using namespace std;

int lg(const int N)
{
	int k = 0, result = 1;
	while (result <= N) {
		result *= 2;
		++k;
	}
	return k - 1;
}

int main()
{
	int a = 1025;
	cout << lg(a) << endl;

	system("pause");
	return 0;
}
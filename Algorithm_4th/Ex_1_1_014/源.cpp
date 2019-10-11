// 编写一个静态方法lg()，接受一个整型参数N，返回不大于log2N 的最大整数。不要使用Math 库。

#include <iostream>

using namespace std;

int lg(const int N)
{
	int ret = 0;
	int result = 1;		// log2N的结果
	while (result <= N) {
		result *= 2;
		++ret;
	}
	return ret - 1;
}

int main()
{
	int i;
	cin >> i;
	cout << lg(i) << endl;

	return 0;
}
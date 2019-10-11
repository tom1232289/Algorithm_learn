// 给出使用欧几里德算法计算105 和24 的最大公约数的过程中得到的一系列p 和q 的值。扩展该算法中的代码得到一个程序Euclid，从命令行接受两个参数，计算它们的最大公约数并打印出每次调用递归方法时的两个参数。使用你的程序计算1 111 111 和1 234 567 的最大公约数。

#include <iostream>

using namespace std;

int Euclid(int p, int q)
{
	cout << p << " " << q << endl;
	if (q == 0)
		return p;
	int r = p % q;
	return Euclid(q, r);
}

int main()
{
	int ret = Euclid(1111111, 1234567);
	cout << endl;
	cout << ret << endl;

	return 0;
}
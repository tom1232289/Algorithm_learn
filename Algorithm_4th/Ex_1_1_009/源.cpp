//编写一段代码，将一个正整数N 用二进制表示并转换为一个String 类型的值s。
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int N = 10;
	string str;
	for (int n = N; n > 0; n /= 2) {
		str = to_string(n % 2) + str;
	}
	cout << str << endl;

	return 0;
}
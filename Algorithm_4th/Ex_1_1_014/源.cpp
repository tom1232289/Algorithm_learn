// ��дһ����̬����lg()������һ�����Ͳ���N�����ز�����log2N �������������Ҫʹ��Math �⡣

#include <iostream>

using namespace std;

int lg(const int N)
{
	int ret = 0;
	int result = 1;		// log2N�Ľ��
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
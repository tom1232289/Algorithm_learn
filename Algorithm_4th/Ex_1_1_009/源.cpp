//��дһ�δ��룬��һ��������N �ö����Ʊ�ʾ��ת��Ϊһ��String ���͵�ֵs��
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
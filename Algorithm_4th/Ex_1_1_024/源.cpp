// ����ʹ��ŷ������㷨����105 ��24 �����Լ���Ĺ����еõ���һϵ��p ��q ��ֵ����չ���㷨�еĴ���õ�һ������Euclid���������н��������������������ǵ����Լ������ӡ��ÿ�ε��õݹ鷽��ʱ������������ʹ����ĳ������1 111 111 ��1 234 567 �����Լ����

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
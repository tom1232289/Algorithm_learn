// ��ֵ����ΪBinarySearch �����һ����̬����rank()��������һ������һ�������������飨���ܴ����ظ�������Ϊ����������������С�ڸü���Ԫ���������Լ�һ�����Ƶķ���count() �����������е��ڸü���Ԫ�ص�������ע�⣺���i ��j �ֱ���rank(key, a) ��count(key, a)�ķ���ֵ����ôa[i..i + j - 1] �������������к�key ��ȵ�Ԫ�ء�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
size_t rank(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	auto iter = vec.begin();
	for (; iter != vec.end(); ++iter) {
		if (*iter >= key)
			break;
	}
	return iter - vec.begin();
}

template <typename T>
size_t count(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	size_t cnt = 0;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		if (*iter == key)
			++cnt;
		else if (*iter > key)
			break;
	}
	return cnt;
}

int main()
{
	vector<int> ivec = { 3,2,1,3,3,6,3,2,5,2 };
	const int key = 5;
	cout << ::rank(key, ivec) << endl;
	cout << ::count(key, ivec) << endl;

	return 0;
}
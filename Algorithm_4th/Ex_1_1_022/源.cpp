#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ʹ��1.1.6.4 ���е�rank() �ݹ鷽������ʵ�� BinarySearch �����ٸ÷����ĵ��á�ÿ���÷���������ʱ����ӡ�����Ĳ��� low �� high �����յݹ�������������ʾ��Ϊ�ݹ鷽�����һ������������ݹ����ȡ�

// ���ֲ��ң��ݹ�棩
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec)
{
	return BinarySearch(key, vec, 0, vec.size() - 1, 1);
}

template <typename T>
int BinarySearch(const T &key, const vector<T> &vec, int low, int high, int deep)
{
	// ���key������a[]�У�������������С��lo�Ҳ������hi
	if (low > high)
		return -1;
	int mid = low + (high - low) / 2;
	for (size_t i = 0; i < deep; ++i) {
		cout << " ";
	}
	cout << "low:" << low << " high:" << high << endl;
	if (key < vec[mid])
		return BinarySearch(key, vec, low, mid - 1, deep + 1);
	else if (key > vec[mid])
		return BinarySearch(key, vec, mid + 1, high, deep + 1);
	else
		return mid;
}

int main()
{
	vector<int> ivec = { 2,4,2,76,1,4,8,3 };
	sort(ivec.begin(), ivec.end());
	// ��ȡ��ֵ������������ڰ������������ӡ
	int val;
	while (cin >> val) {
		if (BinarySearch(val, ivec) < 0) {
			cout << val << endl;
		}
	}

	return 0;
}
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 使用1.1.6.4 节中的rank() 递归方法重新实现 BinarySearch 并跟踪该方法的调用。每当该方法被调用时，打印出它的参数 low 和 high 并按照递归的深度缩进。提示：为递归方法添加一个参数来保存递归的深度。

// 二分查找（递归版）
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec)
{
	return BinarySearch(key, vec, 0, vec.size() - 1, 1);
}

template <typename T>
int BinarySearch(const T &key, const vector<T> &vec, int low, int high, int deep)
{
	// 如果key存在于a[]中，它的索引不会小于lo且不会大于hi
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
	// 读取键值，如果不存在于白名单中则将其打印
	int val;
	while (cin >> val) {
		if (BinarySearch(val, ivec) < 0) {
			cout << val << endl;
		}
	}

	return 0;
}
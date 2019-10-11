#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 二分查找
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec)
{
	// 数组必须是有序的
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		// 被查找的键要么不存在，要么必然存在于ivec[low...high]之中
		int mid = low + (high - low) / 2;
		if (key < vec.at(mid)) {
			high = mid - 1;
		}
		else if (vec.at(mid) < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
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
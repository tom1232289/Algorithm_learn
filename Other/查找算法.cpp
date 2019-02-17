#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 二分查找
template <typename T>
int BinarySearch(T key, vector<T> &vec)
{
	// 数组必须是有序的
	sort(vec.begin(), vec.end());
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {	// =号是保证查找的是数组中最后一个元素
		// 被查找的键要么不存在，要么必然存在于vec[low...high]之中
		int mid = low + (high - low) / 2;
		if (key < vec[mid])
			high = mid - 1;
		else if (key > vec[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	vector<int> ivec2{ 1,1,1,1,1,1 };
	cout << BinarySearch(1, ivec2) << endl;

	return 0;
}

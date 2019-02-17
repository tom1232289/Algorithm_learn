#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 二分查找
template <typename T>
int BinarySearch(T key, vector<T> a)
{
	// 数组必须是有序的
	int low = 0;
	int high = a.size() - 1;
	while (low <= high) {
		// 被查找的键要么不存在，要么必然存在于a[low...high]之中
		int mid = low + (high - low) / 2;
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	vector<int> ivec{ 0,1,2,3,4,5 };
	sort(ivec.begin(), ivec.end());
	auto temp = BinarySearch(4, ivec);

	return 0;
}

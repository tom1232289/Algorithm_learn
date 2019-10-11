// 修改 BinarySearch（请见 1.1.10.1 节中的二分查找代码），使用 Counter 统计在有查找中被检查的键的总数并在查找全部结束后打印该值。提示：在 main() 中创建一个 Counter 对象并将它作为参数传递给 rank()。

#include "Counter.h"
#include <vector>
#include <iostream>

// 二分查找
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec, Counter &counter)
{
	// 数组必须是有序的
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		counter.increment();
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
	vector<int> ivec = { 1,2,4,5,3,4,23 };
	Counter counter("BinarySearch");
	BinarySearch(4, ivec, counter);
	cout << counter.tally() << endl;

	return 0;
}
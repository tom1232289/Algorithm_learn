// 二分查找与暴力查找。根据1.1.10.4 节给出的暴力查找法编写一个程序BruteForceSearch，在你的计算机上比较它和BinarySearch 处理largeW.txt 和largeT.txt 所需的时间。

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

/// 二分查找
template <typename T>
int BinarySearch(T &key, vector<T> &vec)
{
	// 数组必须是有序的
// 	sort(vec.begin(), vec.end());
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		// 被查找的键要么不存在，要么必然存在于a[low...high]之中
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

/// 暴力查找
template <typename T>
int BruteForceSearch(T &key, const vector<T> &vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == key)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "输入文件数量错误" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "读取输入文件失败" << endl;
		return -1;
	}
	int itemp;
	vector<int> ivec;
	while (in >> itemp) {
		ivec.push_back(itemp);
	}
	sort(ivec.begin(), ivec.end());

	int iSearch = 507386;

	// 测试二分查找
	auto start = system_clock::now();
	cout << BinarySearch(iSearch, ivec) << endl;
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "cost " << duration.count() << " microseconds" << endl;

	// 测试暴力查找
	start = system_clock::now();
	cout << BruteForceSearch(iSearch, ivec) << endl;
	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "cost " << duration.count() << " microseconds" << endl;

	// 测试结果显示：
	// 1.在数组已排序的情况下，二分查找要比暴力查找快的多。
	// 2.如果数组没有排序，二分查找需要比暴力查找多一个排序的操作，总体时间要比暴力查找慢的多。(仅测试largeT.txt和largeW.txt)

	return 0;
}
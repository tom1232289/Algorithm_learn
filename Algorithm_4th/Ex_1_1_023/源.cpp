// 为BinarySearch 的测试用例添加一个参数：+ 打印出标准输入中不在白名单上的值；-，则打印出标准输入中在白名单上的值。

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int BinarySearch(int key, const vector<int> &vec)
{
	// 数组必须是有序的
	int lo = 0;
	int hi = vec.size() - 1;
	while (lo <= hi) {
		// 被查找的键要么不存在，要么必然存在于a[lo..hi]之中
		int mid = lo + (hi - lo) / 2;
		if (key < vec[mid])
			hi = mid - 1;
		else if (key > vec[mid])
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cerr << "输入文件个数错误" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法读取输入文件" << endl;
		return -1;
	}
	vector<int> whitelist;
	string line;
	while (getline(in, line)) {
		int word;
		istringstream is(line);
		while (is >> word) {
			whitelist.push_back(word);
		}
	}
	sort(whitelist.begin(), whitelist.end());

	int i = 0;
	while (cin >> i) {
		if ((BinarySearch(i, whitelist) < 0) && (string)argv[2] == "+") {
			cout << i << " ";
		}
		else if ((BinarySearch(i, whitelist) >= 0) && (string)argv[2] == "-")
			cout << i << " ";
	}

	system("pause");
	return 0;
}
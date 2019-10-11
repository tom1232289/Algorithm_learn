// 删除重复元素。修改BinarySearch 类中的测试用例来删去排序之后白名单中的所有重复元素。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// STL
// int main()
// {
// 	vector<int> ivec = { 2,2,3,1,2,1,2,1,3,1,2 };
//
// 	sort(ivec.begin(), ivec.end());
// 	auto iter = unique(ivec.begin(), ivec.end());
// 	ivec.erase(iter, ivec.end());
//
// 	for (auto c : ivec)
// 		cout << c << " ";
// 	cout << endl;
//
// 	system("pause");
// 	return 0;
// }

// 手撸
int main()
{
	vector<int> ivec = { 2,2,3,1,2,1,2,1,3,1,2 };
	sort(ivec.begin(), ivec.end());

	vector<int> ivecTemp;
	ivecTemp.push_back(*(ivec.begin()));
	for (auto iter = ivec.begin() + 1; iter != ivec.end(); ++iter) {
		if (*iter != *(iter - 1)) {
			ivecTemp.push_back(*iter);
		}
	}

	for (auto c : ivecTemp)
		cout << c << " ";
	cout << endl;

	return 0;
}
// 编写一个静态方法histogram()，接受一个整型数组a[] 和一个整数M 为参数并返回一个大小为M的数组，其中第i个元素的值为整数i在参数数组中出现的次数。如果a[]中的值均在0到M - 1之间，返回数组中所有元素之和应该和a.length 相等。

#include <iostream>
#include <vector>

using namespace std;

vector<int> histogram(vector<int> &vec)
{
	size_t M = vec.size();
	vector<int> retVec(M, 0);
	for (size_t i = 0; i < M; ++i) {
		int iTimes = 0;
		for (size_t j = 0; j < M; ++j) {
			if (vec[j] == i) {
				++iTimes;
			}
		}
		retVec[i] = iTimes;
	}
	return retVec;
}

int main()
{
	vector<int> ivec = { 1,1,3,2,1,2 };
	vector<int> ivec2 = histogram(ivec);
	for (auto iter = ivec2.begin(); iter != ivec2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
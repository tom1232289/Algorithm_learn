// 等值键。为BinarySearch 类添加一个静态方法rank()，它接受一个键和一个整型有序数组（可能存在重复键）作为参数并返回数组中小于该键的元素数量，以及一个类似的方法count() 来返回数组中等于该键的元素的数量。注意：如果i 和j 分别是rank(key, a) 和count(key, a)的返回值，那么a[i..i + j - 1] 就是数组中所有和key 相等的元素。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
size_t rank(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	auto iter = vec.begin();
	for (; iter != vec.end(); ++iter) {
		if (*iter >= key)
			break;
	}
	return iter - vec.begin();
}

template <typename T>
size_t count(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	size_t cnt = 0;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		if (*iter == key)
			++cnt;
		else if (*iter > key)
			break;
	}
	return cnt;
}

int main()
{
	vector<int> ivec = { 3,2,1,3,3,6,3,2,5,2 };
	const int key = 5;
	cout << ::rank(key, ivec) << endl;
	cout << ::count(key, ivec) << endl;

	return 0;
}
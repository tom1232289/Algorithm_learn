#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
size_t rank(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	return count_if(vec.begin(), vec.end(), [&](const T &t) {
		return t < key;
	});
}

template <typename T>
size_t count(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	return count_if(vec.begin(), vec.end(), [&](const T &t) {
		return t == key;
	});
}

//int main()
//{
//	vector<int> ivec = { 3,2,1,3,3,6,3,2,5,2 };
//	const int key = 5;
//	cout << ::rank(key, ivec) << endl;
//	cout << ::count(key, ivec) << endl;
//
//	return 0;
//}
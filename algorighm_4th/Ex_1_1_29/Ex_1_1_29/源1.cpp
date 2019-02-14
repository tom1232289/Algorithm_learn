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
	const int key = 0;
	auto temp = ::rank(key, ivec);
	auto temp2 = ::count(key, ivec);

	return 0;
}
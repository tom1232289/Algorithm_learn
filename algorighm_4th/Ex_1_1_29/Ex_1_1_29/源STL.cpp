#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Less_than_key
{
public:
	Less_than_key(const T &key) {
		m_key = key;
	}
	bool operator()(const T &t) {
		return t < m_key;
	}
private:
	T m_key;
};
template <typename T>
size_t rank(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	return count_if(vec.begin(), vec.end(), Less_than_key<T>(key));
}

template <typename T>
class Equal_to_key
{
public:
	Equal_to_key(const T &key) {
		m_key = key;
	}
	bool operator()(const T &t) {
		return t == m_key;
	}
private:
	T m_key;
};
template <typename T>
size_t count(const T &key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
	return count_if(vec.begin(), vec.end(), Equal_to_key<T>(key));
}

int main()
{
	vector<int> ivec = { 3,2,1,3,3,6,3,2,5,2 };
	const int key = 0;
	auto temp = ::rank(key, ivec);
	auto temp2 = ::count(key, ivec);

	return 0;
}
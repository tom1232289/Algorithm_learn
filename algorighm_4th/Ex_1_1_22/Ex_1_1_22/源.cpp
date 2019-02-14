#include <iostream>
#include <vector>

using namespace std;

static int k = 0;

int rank(int key, vector<int> &a, int lo, int hi)
{
	if (lo > hi)
		return -1;
	int mid = lo + (hi - lo) / 2;
	if (key < a[mid]) {
		++k;
		return ::rank(key, a, lo, mid - 1);
	}
	else if (key > a[mid]) {
		++k;
		return ::rank(key, a, mid + 1, hi);
	}
	else
		return mid;
}

int rank(int key, vector<int> &a)
{
	return ::rank(key, a, 0, a.size() - 1);
}

int main()
{
	vector<int> a = { 0,1,2,3,4,5,6,7,8,9 };
	auto b = ::rank(0, a);

	return 0;
}
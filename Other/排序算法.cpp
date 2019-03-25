#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int p, int q)
{
	if (q == 0)
		return p;
	int r = p % q;
	return gcd(q, r);
}

template <typename T>
T abs(T x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

bool isPrime(int N)
{
	for (int i = 2; i <= sqrt(N); ++i) {
		if (N%i == 0)
			return false;
	}
	return true;
}

double BisectionSqrt(double N)
{
	double a = 0.0, b = N + 0.25, m = 0.0;
	while (true) {
		m = (a + b) / 2;
		if (m - a < DBL_EPSILON || b - m < DBL_EPSILON)
			break;
		if ((m*m - N)*(a*a - N) < 0)
			b = m;
		else
			a = m;
	}
	return m;
}

double NewtonSqrt(double N)
{
	double x0 = N, x1 = 0.0, xx = x0;
	while (true) {
		x1 = (x0*x0 + N) / (2 * x0);
		if (fabs(x1 - x0) <= DBL_EPSILON)
			break;
		if (xx == x1)
			break;
		xx = x0;
		x0 = x1;
	}
	return x1;
}

template <typename T>
void bubble_sort(vector<T> &vec)
{
	for (int i = 0; i < vec.size() - 1; ++i) {
		for (int j = 0; j < vec.size() - 1 - i; ++j) {
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
			}
		}
	}
}

template <typename T>
void selection_sort(vector<T> &vec)
{
	for (int i = 0; i < vec.size() - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		std::swap(vec[i], vec[min]);
	}
}

template <typename T>
void insert_sort(vector<T> &vec)
{
	for (int i = 1; i < vec.size(); ++i) {
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}
}

template <typename T>
void quick_sort_recursive(vector<T> &vec, int start, int end)
{
	if (start >= end)
		return;
	T mid = vec[end];
	int left = start, right = end - 1;
	while (left < right) {
		while (left < right && vec[left] <= mid) {
			left++;
		}
		while (left < right && vec[right] > mid) {
			right--;
		}
		std::swap(vec[left], vec[right]);
	}
	if (vec[left] > vec[end])
		std::swap(vec[left], vec[end]);
	else
		left++;
	quick_sort_recursive(vec, start, left - 1);
	quick_sort_recursive(vec, left + 1, end);
}

template <typename T>
void quick_sort(vector<T> &vec)
{
	quick_sort_recursive(vec, 0, vec.size() - 1);
}

int main()
{
	vector<int> ivec{ 6,5,3,1,8,7,2,4 };
	quick_sort(ivec);
	for (auto c : ivec)
		cout << c << " ";
	cout << endl;

	system("pause");
	return 0;
}

// ���ƥ�䡣��дһ��ʹ��BinarySearch �ĳ������������н���һ�����Ͳ���T������ֱ����N = 10^3��10^4��10^5 ��10^6 ������ʵ������T �飺����������СΪN �����6 λ���������鲢�ҳ�ͬʱ���������������е���������������ӡһ����񣬶���ÿ��N������T ��ʵ���и�������ƽ��ֵ��

#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T>
int BinarySearch(T key, vector<T> &vec)
{
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
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

void randomMatch(const int T, int N, vector<int> &ivecCount)
{
	ivecCount.clear();
	for (int i = 0; i < T; ++i) {
		// ���������������
		vector<size_t> ivec1(N), ivec2(N);
		random_device rd;
		mt19937_64 generator(rd());
		uniform_int_distribution<size_t> distribution(100000, 1000000);
		for (auto &c : ivec1) {
			c = distribution(generator);
		}
		for (auto &c : ivec2) {
			c = distribution(generator);
		}

		// ������һ�������в��� Ҳ����һ�������е�Ԫ�� �ĸ���
		size_t count = 0;
		for (auto c : ivec1) {
			if (BinarySearch(c, ivec2) != -1)
				++count;
		}

		// ��count����vector����
		ivecCount.push_back(count);
	}
}

// ��ӡÿ��ʵ����ͬʱ���������������Ԫ�ص�������ƽ����
void print(vector<int> &ivec)
{
	double sum = 0;
	for (auto c : ivec) {
		cout << c << " ";
		sum += c;
	}
	double avg = sum / ivec.size();
	cout << endl << avg << endl;
}

int main()
{
	const int T = 97;
	int N = pow(10, 3);
	vector<int> ivecCount;

	randomMatch(T, N, ivecCount);
	print(ivecCount);
	cout << endl;

	N = pow(10, 4);
	randomMatch(T, N, ivecCount);
	print(ivecCount);
	cout << endl;

	N = pow(10, 5);
	randomMatch(T, N, ivecCount);
	print(ivecCount);
	cout << endl;

	N = pow(10, 6);
	randomMatch(T, N, ivecCount);
	print(ivecCount);
	cout << endl;

	return 0;
}

// ���н����
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0
//
//0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0
//0.185567
//
//4 3 4 2 1 2 3 1 1 1 5 5 2 0 4 1 1 3 3 1 3 2 1 2 4 0 4 1 1 0 3 0 5 1 2 1 0 2 3 0 2 2 6 3 0 3 2 1 2 2 2 0 3 6 0 1 1 2 2 2 1 1 0 1 3 0 0 0 4 1 1 2 2 0 1 2 0 2 1 4 4 2 0 4 1 3 3 2 0 1 1 2 1 5 4 3 1
//1.92784
//
//11 29 24 16 21 28 19 20 23 15 24 16 22 14 33 20 25 18 38 18 12 20 26 16 29 28 12 17 24 22 19 22 16 15 22 23 26 25 20 23 18 24 19 36 17 8 20 18 16 25 22 19 36 18 20 23 30 20 24 20 21 27 24 25 22 46 20 11 18 14 16 17 22 18 28 14 22 26 22 20 25 18 22 20 30 31 25 14 29 24 20 14 13 21 21 22 26
//21.567
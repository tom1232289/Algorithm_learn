// 随机匹配。编写一个使用BinarySearch 的程序，它从命令行接受一个整型参数T，并会分别针对N = 10^3、10^4、10^5 和10^6 将以下实验运行T 遍：生成两个大小为N 的随机6 位正整数数组并找出同时存在于两个数组中的整数的数量。打印一个表格，对于每个N，给出T 次实验中该数量的平均值。

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
		// 随机生成两个数组
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

		// 在其中一个数组中查找 也在另一个数组中的元素 的个数
		size_t count = 0;
		for (auto c : ivec1) {
			if (BinarySearch(c, ivec2) != -1)
				++count;
		}

		// 将count存入vector数组
		ivecCount.push_back(count);
	}
}

// 打印每次实验中同时存在于两个数组的元素的数量和平均数
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

// 运行结果：
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
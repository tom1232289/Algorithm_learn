#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T>
int BinarySearch(T key, vector<T> &vec)
{
	sort(vec.begin(), vec.end());
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

void randomMatch(const int T,int N,vector<int> &ivecCount)
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
// 			if (BinarySearch(c, ivec2) != -1)
// 				++count;
			// ��������̫����,����STL��find����(����ʱ���Ա���Release�棬����)
			auto iter = find(ivec2.begin(), ivec2.end(), c);
			if (iter != ivec2.end())
				++count;
		}

		// ��count����vector����
		ivecCount.push_back(count);
	}
}

// ��ӡivecCount��ƽ����
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

	system("pause");
	return 0;
}
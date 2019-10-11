// 糟糕的打乱。假设在我们的乱序代码中你选择的是一个0 到N - 1 而非i 到N - 1 之间的随机整数。证明得到的结果并非均匀地分布在N!种可能性之间。用上一题中的测试检验这个版本。

#include <iostream>
#include <vector>
#include <random>

using namespace std;

// 将数组乱序
void shuffle(vector<double> &a)
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dis(0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		// 将a[i]和a[i..N-1]中任意一个元素交换
// 		uniform_int_distribution<> dis(0, a.size() - 1 - i);
// 		int r = i + dis(gen);
		int r = dis(gen);
		std::swap(a[i], a[r]);
	}
}

int main()
{
	const int M = 5;
	const int N = 1000;
	vector<double> dvec(M);
	vector<vector<double>> i2vec(M, vector<double>(M));
	for (int i = 0; i < N; ++i) {
		for (size_t i = 0; i < dvec.size(); ++i) {
			dvec[i] = i;
		}
		shuffle(dvec);

		for (size_t j = 0; j < dvec.size(); ++j) {
			++i2vec[dvec[j]][j];	// 打乱后i行的值落到j列的次数增1
		}
	}

	for (auto i : i2vec) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
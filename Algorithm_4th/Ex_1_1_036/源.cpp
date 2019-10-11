// 乱序检查。通过实验检查表1.1.10 中的乱序代码是否能够产生预期的效果。编写一个程序ShuffleTest，接受命令行参数M 和N，将大小为M 的数组打乱N 次且在每次打乱之前都将数组重新初始化为a[i] = i。打印一个M×M 的表格，对于所有的列j，行i 表示的是i 在打乱后落到j 的位置的次数。数组中的所有元素的值都应该接近于N / M。

#include <iostream>
#include <vector>
#include <random>

using namespace std;

// 将数组乱序
void shuffle(vector<double> &a)
{
	random_device rd;
	mt19937_64 gen(rd());
	for (int i = 0; i < a.size(); ++i) {
		// 将a[i]和a[i..N-1]中任意一个元素交换
		uniform_int_distribution<> dis(0, a.size() -1 - i);
		int r = i + dis(gen);
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
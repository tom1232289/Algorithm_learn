// ���Ĵ��ҡ����������ǵ������������ѡ�����һ��0 ��N - 1 ����i ��N - 1 ֮������������֤���õ��Ľ�����Ǿ��ȵطֲ���N!�ֿ�����֮�䡣����һ���еĲ��Լ�������汾��

#include <iostream>
#include <vector>
#include <random>

using namespace std;

// ����������
void shuffle(vector<double> &a)
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dis(0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		// ��a[i]��a[i..N-1]������һ��Ԫ�ؽ���
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
			++i2vec[dvec[j]][j];	// ���Һ�i�е�ֵ�䵽j�еĴ�����1
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
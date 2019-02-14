#include <iostream>
#include <vector>
#include <random>
#include <windows.h>
#include <conio.h>

using namespace std;

void shuffle(vector<double> &a)
{
	int N = a.size();
	random_device rd;
	mt19937_64 gen(rd());
	for (int i = 0; i < N; ++i) {
		uniform_real_distribution<> dis(0, N);
		// 将a[i]和a[i..N-1]中任意一个元素交换
		int r = /*i +*/ dis(gen);
		std::swap(a[i], a[r]);
	}
}

int main()
{
// 	HWND my_consle = GetForegroundWindow();
// 	ShowWindow(my_consle, SW_MINIMIZE);

	const int M = 4;
	const int N = 5;
	vector<double> a(M);
	vector<vector<int>> i2vec(M, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (size_t i = 0; i < a.size(); ++i) {
			a[i] = i;
		}
		shuffle(a);

		for (size_t j = 0; j < a.size(); ++j) {
			++i2vec[a[j]][j];
		}
	}

	for (auto i : i2vec) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
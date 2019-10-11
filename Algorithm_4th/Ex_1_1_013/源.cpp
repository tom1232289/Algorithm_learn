// 编写一段代码，打印出一个M 行N 列的二维数组的转置（交换行和列）。

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printArray2(const vector<vector<T>> &vec2)
{
	size_t M = vec2.size();
	size_t N = vec2.at(0).size();
	cout << " ";
	for (int i = 0; i < N; ++i) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int i = 0; i < M; ++i) {
		cout << i << "\t";
		for (int j = 0; j < N; ++j) {
			cout << vec2[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T>
vector<vector<T>> transposeArray2(const vector<vector<T>> &vec2)
{
	size_t M = vec2.size();
	size_t N = vec2.at(0).size();
	vector <vector<T>> retVec2(M, vector<T>(N, T()));
	for (size_t i = 0; i < M; ++i) {
		for (size_t j = 0; j < N; ++j) {
			retVec2[i][j] = vec2[j][i];
		}
	}
	return retVec2;
}

int main()
{
	const int M = 4;
	const int N = 4;
	vector<vector<int>> ivec2 = {
		{ 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 }
	};
	printArray2(ivec2);

	cout << "------Transpose------" << endl;

	vector<vector<int>> ivec2_2 = transposeArray2(ivec2);

	printArray2(ivec2_2);

	return 0;
}
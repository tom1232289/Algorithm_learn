// ������ϰ����дһ�γ��򣬴���һ��N��N �Ĳ�������a[][]�����е�i ��j ����ʱ��û����ͬ���ӣ���a[i][j] Ϊtrue������Ϊfalse��

#include <iostream>
#include <vector>

using namespace std;

int gcd(int p, int q)
{
	if (q == 0)
		return p;
	int r = p % q;
	return gcd(q, r);
}

bool isCoprime(int p, int q)
{
	if (gcd(p, q) == 1)
		return true;
	else
		return false;
}

vector<vector<bool>> CreateBoolArray(int N)
{
	vector<vector<bool>> b2vec(N, vector<bool>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			b2vec[i][j] = isCoprime(i, j);
		}
	}
	return b2vec;
}

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

int main()
{
	const int N = 10;
	auto boolArray2 = CreateBoolArray(N);
	printArray2(boolArray2);

	return 0;
}
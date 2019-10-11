#include <iostream>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

const int SIDES = 6;
const int TIMES = 10000000;

double myRound(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

double myRound(double value, int scale)
{
	double base = 1;
	for (int i = 0; i < scale; i++)
	{
		base = 10 * base;
	}
	return myRound(value * base) / base;
}

map<int, double> AccurateDist()
{
	map<int, double> dist;
	for (int i = 1; i <= SIDES; ++i) {
		for (int j = 1; j <= SIDES; ++j) {
			dist[i + j] += 1.0;
		}
	}
	for (int k = 2; k <= 2 * SIDES; ++k) {
		dist[k] /= 36.0;
	}
	return dist;
}

int main()
{
	map<int, double> accurateDist = AccurateDist();

	map<int, double> dist;

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dis(1, 6);
	for (int i = 0; i < TIMES; ++i) {
		int iFirst = dis(gen);
		int iSecond = dis(gen);
		++dist[iFirst + iSecond];
	}

	cout << "-------" << endl;
	cout << "1~6出现的频率：" << endl;
	for (auto c : dist) {
		cout << c.first << ":" << c.second << endl;
	}

	for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
		iter->second /= TIMES;
	}
	cout << "-------" << endl;
	cout << "1~6出现的概率：" << endl;
	for (auto c : dist) {
		cout << c.first << ":" << c.second << endl;
	}

	cout << "-------" << endl;
	for (auto iter1 = accurateDist.begin(), iter2 = dist.begin(); iter1 != accurateDist.end(), iter2 != dist.end(); ++iter1) {
		if (iter1->first == iter2->first) {
			if (myRound(iter1->second, 3) == myRound(iter2->second, 3)) {
				cout << iter1->first << "吻合" << endl;
			}
			else {
				cout << iter1->first << "不吻合" << endl;
			}
		}
		++iter2;
	}

	return 0;
}
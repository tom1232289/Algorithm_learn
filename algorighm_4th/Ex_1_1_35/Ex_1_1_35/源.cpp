#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

const int SIDES = 6;

vector<double> AccurateDist()
{
	vector<double> dist(2 * SIDES + 1);
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
	auto accurateDist = AccurateDist();

	vector<double> dist(2 * SIDES + 1);

	const int Lower = 1;
	const int Upper = 6;
	int N = 100000000;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; ++i) {
		int a = (rand() % (Upper - Lower + 1)) + Lower;
		int b = (rand() % (Upper - Lower + 1)) + Lower;
		int sum = a + b;
		++dist[sum];
	}

	for (size_t i = 2; i < dist.size(); ++i) {
		dist[i] /= N;
	}

	for (size_t i = 0; i < dist.size(); ++i) {
		if (accurateDist[i] - dist[i] >= 0.0001) {
			ofstream out;
			out.open("D://1.txt", ios::app);
			if (out.is_open()) {
				out << "1" << endl;
				out.close();
			}
			break;
		}
	}

	return 0;
}
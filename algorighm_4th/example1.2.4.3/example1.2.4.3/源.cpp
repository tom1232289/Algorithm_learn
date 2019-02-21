#include "Accumulator.h"
#include <random>

int main()
{
	const int T = 1000;
	random_device rd;
	mt19937_64 generator(rd());
	uniform_real_distribution<double> distribution(0, 1);

	CAccumulate a;
	for (int i = 0; i < T; ++i) {
		a.addDataValue(distribution(generator));
	}
	a.print(cout);
	cout << endl;

	system("pause");
	return 0;
}
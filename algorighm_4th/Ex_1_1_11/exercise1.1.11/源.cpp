#include <iostream>

using namespace std;

int main()
{
	const int i = 2, j = 2;
	bool b[i][j] = { 0,0,1,0 };
	for (int ii = 0; ii < i; ++ii) {
		for (int jj = 0; jj < j; ++jj) {
			if (b[ii][jj]) {
				cout << ii + 1 << "行" << jj + 1 << "列" << "*" << endl;
			}
			else
				cout << ii + 1 << "行" << jj + 1 << "列" << " " << endl;
		}
	}

	system("pause");
	return 0;
}
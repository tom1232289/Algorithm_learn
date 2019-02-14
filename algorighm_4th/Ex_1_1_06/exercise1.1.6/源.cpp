#include <iostream>

using namespace std;

int main()
{
	int f = 0, g = 1;
	for (int i = 0; i <= 15; ++i) {
		cout << f << endl;
		cout << g << endl << endl;
		f = f + g;
		g = f - g;
	}

	system("pause");
	return 0;
}
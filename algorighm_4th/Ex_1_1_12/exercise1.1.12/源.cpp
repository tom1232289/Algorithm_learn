#include <iostream>

using namespace std;

int main()
{
	int a[10] = {};
	for (int i = 0; i < 10; ++i) {
		a[i] = 9 - i;
	}
	for (int i = 0; i < 10; ++i) {
		a[i] = a[a[i]];
	}
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << endl;
	}

	system("pause");
	return 0;
}
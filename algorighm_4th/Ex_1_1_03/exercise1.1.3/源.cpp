#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	if (a == b && a == c)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	system("pause");
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	double x = 0.0, y = 0.0;
	cin >> x >> y;
	if (x >= 0 && x <= 1 && y >= 0 && y <= 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}
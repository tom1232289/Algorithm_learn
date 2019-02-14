#include <iostream>
#include <string>

using namespace std;

string exR1(int n)
{
	if (n <= 0)
		return "";
	return exR1(n - 3) + to_string(n) + exR1(n - 2) + to_string(n);
}

int main()
{
	cout << exR1(6) << endl;

	system("pause");
	return 0;
}
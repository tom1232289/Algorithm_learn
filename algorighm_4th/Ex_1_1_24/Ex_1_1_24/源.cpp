#include <iostream>

using namespace std;

int Euclid(int p, int q)
{
	cout << p << " " << q << endl;
	if (q == 0)
		return p;
	int r = p % q;
	return Euclid(q, r);
}

int main()
{
	int ret = Euclid(1111111, 1234567);
	cout << endl;
	cout << ret << endl;

	system("pause");
	return 0;
}
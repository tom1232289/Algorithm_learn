#include <iostream>
#include <string>

using namespace std;

string toBinaryString(size_t N)
{
	string s;
	for (int n = N; n > 0; n /= 2)
		s = to_string((n % 2)) + s;
	return s;
}

int main()
{
	size_t N = 8;
	string s;
	s = toBinaryString(N);
	cout << s << endl;

	system("pause");
	return 0;
}
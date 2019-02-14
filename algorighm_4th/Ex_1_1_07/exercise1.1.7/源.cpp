#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string str = "c";
	if (str == "a") {
		double t = 9.0;
		while (abs(t - 9.0 / t) > .001)
			t = (9.0 / t + t) / 2.0;
		cout << fixed << setprecision(5) << t << endl;
	}
	else if (str == "b") {
		int sum = 0;
		for (int i = 1; i < 1000; ++i)
			for (int j = 0; j < i; ++j)
				sum++;
		cout << sum << endl;
	}
	else if (str == "c") {
		int sum = 0;
		for (int i = 1; i < 1000; i *= 2)
			for (int j = 0; j < 1000; j++)
				sum++;
		cout << sum << endl;
	}

	system("pause");
	return 0;
}
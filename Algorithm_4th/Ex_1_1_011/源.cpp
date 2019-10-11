// 编写一段代码，打印出一个二维布尔数组的内容。其中，使用* 表示真，空格表示假。打印出行号和列号。

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int ROW = 2;
	const int COLUMN = 2;
	bool b[ROW][COLUMN] = { 0,0,1,0 };
	string str;
	for (size_t i = 0; i < COLUMN; i++) {
		cout << " \t" << i;
	}
	cout << endl;
	for (size_t i = 0; i < ROW; ++i) {
		cout << i << "\t";
		for (size_t j = 0; j < COLUMN; ++j) {
			str = b[i][j] ? "*" : " ";
			cout << str << "\t";
		}
		cout << endl;
	}

	return 0;
}
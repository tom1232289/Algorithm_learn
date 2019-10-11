// 编写一个 Interval1D 的用例，从命令行接受一个整数 N。从标准输入中读取 N 个间隔（每个间隔由一对double 值定义）并打印出所有相交的间隔对。

#include "Interval1D.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "输入文件数量错误" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法读取输入文件" << endl;
		return -1;
	}

	// 构造间隔对
	vector<Interval1D> interval1dVec;
	string line;
	while (getline(in, line)) {
		istringstream ss(line);
		double d1 = 0.0, d2 = 0.0;
		while (ss >> d1 >> d2) {
			interval1dVec.push_back(Interval1D(d1, d2));
		}
	}

	// 打印相交的间隔对
	for (auto iteri = interval1dVec.begin(); iteri != interval1dVec.end(); ++iteri) {
		for (auto iterj = iteri + 1; iterj != interval1dVec.end(); ++iterj) {
			if (iteri->intersect(*iterj)) {
				cout << "this two couple are intersect:[" 
					<< fixed << setprecision(2) << iteri->getmin() << ", " << fixed << setprecision(2) << iteri->getmax() << "]" 
					<< " and [" << fixed << setprecision(2) << iterj->getmin() << ", " << fixed << setprecision(2) << iterj->getmax() << "]" << endl;
			}
		}
	}

	return 0;
}
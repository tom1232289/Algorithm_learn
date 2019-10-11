// ��дһ�� Interval1D ���������������н���һ������ N���ӱ�׼�����ж�ȡ N �������ÿ�������һ��double ֵ���壩����ӡ�������ཻ�ļ���ԡ�

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
		cerr << "�����ļ���������" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷���ȡ�����ļ�" << endl;
		return -1;
	}

	// ��������
	vector<Interval1D> interval1dVec;
	string line;
	while (getline(in, line)) {
		istringstream ss(line);
		double d1 = 0.0, d2 = 0.0;
		while (ss >> d1 >> d2) {
			interval1dVec.push_back(Interval1D(d1, d2));
		}
	}

	// ��ӡ�ཻ�ļ����
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
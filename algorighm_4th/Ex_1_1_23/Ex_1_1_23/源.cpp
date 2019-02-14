#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int BinarySearch(int key, vector<int> &a)
{
	// ��������������
	int lo = 0;
	int hi = a.size() - 1;
	while (lo <= hi) {
		// �����ҵļ�Ҫô�����ڣ�Ҫô��Ȼ������a[lo..hi]֮��
		int mid = lo + (hi - lo) / 2;
		if (key < a[mid])
			hi = mid - 1;
		else if (key > a[mid])
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cerr << "�����ļ���������" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷���ȡ�����ļ�" << endl;
		return -1;
	}
	vector<int> whitelist;
	string line;
	while (getline(in, line)) {
		int word;
		istringstream is(line);
		while (is >> word) {
			whitelist.push_back(word);
		}
	}
	sort(whitelist.begin(), whitelist.end());

	int i = 0;
	while (cin >> i) {
		if ((BinarySearch(i, whitelist) < 0) && (string)argv[2] == "+") {
			cout << i << " ";
		}
		else if ((BinarySearch(i, whitelist) >= 0) && (string)argv[2] == "-")
			cout << i << " ";
	}

	system("pause");
	return 0;
}
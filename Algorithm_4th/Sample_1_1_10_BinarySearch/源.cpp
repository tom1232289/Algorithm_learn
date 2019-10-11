#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ���ֲ���
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec)
{
	// ��������������
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		// �����ҵļ�Ҫô�����ڣ�Ҫô��Ȼ������ivec[low...high]֮��
		int mid = low + (high - low) / 2;
		if (key < vec.at(mid)) {
			high = mid - 1;
		}
		else if (vec.at(mid) < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int main()
{
	vector<int> ivec = { 2,4,2,76,1,4,8,3 };
	sort(ivec.begin(), ivec.end());
	// ��ȡ��ֵ������������ڰ������������ӡ
	int val;
	while (cin >> val) {
		if (BinarySearch(val, ivec) < 0) {
			cout << val << endl;
		}
	}

	return 0;
}
// ���ֲ����뱩�����ҡ�����1.1.10.4 �ڸ����ı������ҷ���дһ������BruteForceSearch������ļ�����ϱȽ�����BinarySearch ����largeW.txt ��largeT.txt �����ʱ�䡣

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

/// ���ֲ���
template <typename T>
int BinarySearch(T &key, vector<T> &vec)
{
	// ��������������
// 	sort(vec.begin(), vec.end());
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		// �����ҵļ�Ҫô�����ڣ�Ҫô��Ȼ������a[low...high]֮��
		int mid = low + (high - low) / 2;
		if (key < vec[mid])
			high = mid - 1;
		else if (key > vec[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/// ��������
template <typename T>
int BruteForceSearch(T &key, const vector<T> &vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == key)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "�����ļ���������" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "��ȡ�����ļ�ʧ��" << endl;
		return -1;
	}
	int itemp;
	vector<int> ivec;
	while (in >> itemp) {
		ivec.push_back(itemp);
	}
	sort(ivec.begin(), ivec.end());

	int iSearch = 507386;

	// ���Զ��ֲ���
	auto start = system_clock::now();
	cout << BinarySearch(iSearch, ivec) << endl;
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "cost " << duration.count() << " microseconds" << endl;

	// ���Ա�������
	start = system_clock::now();
	cout << BruteForceSearch(iSearch, ivec) << endl;
	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "cost " << duration.count() << " microseconds" << endl;

	// ���Խ����ʾ��
	// 1.�����������������£����ֲ���Ҫ�ȱ������ҿ�Ķࡣ
	// 2.�������û�����򣬶��ֲ�����Ҫ�ȱ������Ҷ�һ������Ĳ���������ʱ��Ҫ�ȱ����������Ķࡣ(������largeT.txt��largeW.txt)

	return 0;
}
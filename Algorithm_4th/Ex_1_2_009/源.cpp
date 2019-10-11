// �޸� BinarySearch����� 1.1.10.1 ���еĶ��ֲ��Ҵ��룩��ʹ�� Counter ͳ�����в����б����ļ����������ڲ���ȫ���������ӡ��ֵ����ʾ���� main() �д���һ�� Counter ���󲢽�����Ϊ�������ݸ� rank()��

#include "Counter.h"
#include <vector>
#include <iostream>

// ���ֲ���
template <typename T>
int BinarySearch(const T &key, const vector<T> &vec, Counter &counter)
{
	// ��������������
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high) {
		counter.increment();
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
	vector<int> ivec = { 1,2,4,5,3,4,23 };
	Counter counter("BinarySearch");
	BinarySearch(4, ivec, counter);
	cout << counter.tally() << endl;

	return 0;
}
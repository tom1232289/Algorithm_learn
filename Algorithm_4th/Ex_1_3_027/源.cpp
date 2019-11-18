// ��дһ������max()������һ��������׽����Ϊ���������������м����Ľڵ��ֵ���������м���Ϊ���������������Ϊ���򷵻� 0��

#include "../Test/SinglyLinkedList.h"

using namespace std;

template <typename T>
T max(SinglyLinkedList<T> &sll)
{
	T ret = *(sll.begin());
	for (auto iter = sll.begin(); iter != sll.end(); ++iter) {
		if (*iter > ret) {
			ret = *iter;
		}
	}

	return ret;
}

int main()
{
	SinglyLinkedList<int> sll;
	sll.insert(sll.size(), 1);
	sll.insert(sll.size(), 2);
	sll.insert(sll.size(), 2);
	sll.insert(sll.size(), 3);
	sll.insert(sll.size(), 2);
	sll.insert(sll.size(), 2);

	auto temp = ::max(sll);

	cout  << temp << endl;

	return 0;
}
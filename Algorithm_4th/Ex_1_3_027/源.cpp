// 编写一个方法max()，接受一条链表的首结点作为参数，返回链表中键最大的节点的值。假设所有键均为正整数，如果链表为空则返回 0。

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
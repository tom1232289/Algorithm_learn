// 编写一个函数，接受一条链表的首结点作为参数，（破坏性地）将链表反转并返回结果链表的首结点。

#include "../Test/SinglyLinkedList.h"

// H->A->B->C->D
// H->B->A->C->D
// H->C->B->A->D
// H->D->C->B->A

template <typename T>
bool ReverseLinkedList(SinglyLinkedList<T> &sll)
{
	auto *pHead = sll.getHead();
	if (pHead == nullptr)
		return false;

	auto *pPreFirst = pHead->pNext;
	if (pPreFirst == nullptr)
		return false;
	sll.setTail(pPreFirst);

	auto *pNode = pPreFirst->pNext;
	while (pNode != nullptr) {
		pPreFirst->pNext = pNode->pNext;
		pNode->pNext = pHead->pNext;
		pHead->pNext = pNode;

		pNode = pPreFirst->pNext;
	}

	return true;
}

int main()
{
	SinglyLinkedList<int> sll;
	sll.insert(sll.size(), 1);
	sll.insert(sll.size(), 2);
	sll.insert(sll.size(), 3);
	ReverseLinkedList(sll);

	return 0;
}
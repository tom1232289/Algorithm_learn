// 双向链表

#pragma once

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

template <typename T>
class DoubleLinkedList
{
	// 双向链表节点
	class Node {
	public:
		Node(T t = T()) :
			value(t) {}

	public:
		T value = T();
		Node *pPre = nullptr;
		Node *pNext = nullptr;
	};

public:
	DoubleLinkedList() :
		m_pHead(new Node) {}
	~DoubleLinkedList();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	Node * insert(size_t index, T t);
	T erase(int index);

private:
	Node *getNode(size_t index);

private:
	size_t m_iCount = 0;
	Node *m_pHead = nullptr;
};

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
	}
}

template <typename T>
typename DoubleLinkedList<T>::Node * DoubleLinkedList<T>::getNode(size_t index)
{
	if (index < 0 || index > m_iCount) {
		LogError("getNode: out of range");
	}

	Node *pNode = m_pHead;
	int iTemp = 0;
	while (pNode != nullptr && iTemp < index) {
		pNode = pNode->pNext;
		++iTemp;
	}
	return pNode;
}

template <typename T>
typename DoubleLinkedList<T>::Node * DoubleLinkedList<T>::insert(size_t index, T t)
{
	Node *pNode = getNode(index);
	if (pNode == nullptr) {
		LogError("insert: getNode return nullptr");
	}

	Node *pNewNode = new Node(t);
	pNewNode->pNext = pNode->pNext;
	if (pNode->pNext != nullptr) {
		pNewNode = pNode->pNext->pPre;
	}
	pNode->pNext = pNewNode;
	pNewNode->pPre = pNode;

	++m_iCount;

	return pNewNode;
}

template <typename T>
T DoubleLinkedList<T>::erase(int index)
{
	Node *pNode = nullptr;
	if (index == 0) {
		pNode = m_pHead;
	}
	else {
		Node *pNode = getNode(index - 1);
	}
	if (pNode == nullptr) {
		LogError("erase:getNode return nullptr");
	}

	Node *pDelNode = pNode->pNext;
	if (pDelNode == nullptr) {
		LogError("erase:index out of range");
	}
	pNode->pNext = pDelNode->pNext;
	if (pDelNode->pNext != nullptr) {
		pDelNode->pNext->pPre = pNode;
	}
	T ret = pDelNode->value;
	delete pDelNode; pDelNode = nullptr;

	--m_iCount;

	return ret;
}

#endif	// !DOUBLE_LINKED_LIST
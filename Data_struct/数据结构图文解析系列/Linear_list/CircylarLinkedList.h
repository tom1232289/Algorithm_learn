#pragma once

#ifndef CIRCYLARLINKEDLIST_H
#define CIRCYLARLINKEDLIST_H

#include "CircylarLinkedListNode.h"

template <typename T>
class CircylarLinkedList {
public:
	CircylarLinkedList();
	~CircylarLinkedList();

	bool IsEmpty() const;
	size_t size() const;

	CircylarLinkedListNode<T> *getHead() const;

	CircylarLinkedListNode<T> *getNode(int index) const;
	T getValue(int index) const;

	CircylarLinkedListNode<T> *insert(int index, T t);
	CircylarLinkedListNode<T> *insertFront(T t);
	CircylarLinkedListNode<T> *insertLast(T t);

	T deleteN(int index);
	T deleteFront();
	T deleteLast();

public:
	CircylarLinkedListNode<T> *pHead = nullptr;
	int count = 0;
	CircylarLinkedListNode<T> *pTemp = nullptr;
};

#endif	// !CIRCYLARLINKEDLIST_H

template<typename T>
inline CircylarLinkedList<T>::CircylarLinkedList()
{
	pHead = new CircylarLinkedListNode<T>(0, nullptr);
	pTemp = new CircylarLinkedListNode<T>(0, nullptr);
	pHead->pNext = pTemp;
	pTemp->pNext = pHead;
}

template<typename T>
inline CircylarLinkedList<T>::~CircylarLinkedList()
{
	CircylarLinkedListNode<T> *pNode = pHead->pNext;
	while (pNode != pHead) {
		CircylarLinkedListNode<T> *pTempDel = pNode;
		pNode = pNode->pNext;
		if (pTempDel == pTemp)
			pTemp = nullptr;
		delete pTempDel;
	}
	if (pHead) {
		delete pHead;
		pHead = nullptr;
	}
	if (pTemp) {
		delete pTemp;
		pTemp = nullptr;
	}
}

template<typename T>
inline bool CircylarLinkedList<T>::IsEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t CircylarLinkedList<T>::size() const
{
	return count;
}

template<typename T>
inline CircylarLinkedListNode<T>* CircylarLinkedList<T>::getHead() const
{
	return pHead;
}

template<typename T>
inline CircylarLinkedListNode<T>* CircylarLinkedList<T>::getNode(int index) const
{
	if (index < 0 || index > count) {
		cerr << "getNode error" << endl;
		return nullptr;
	}
	CircylarLinkedListNode<T>* pNode = pHead;
	for (int nTemp = 0; nTemp != index; ++nTemp) {
		pNode = pNode->pNext;
		if (!pNode) {
			cerr << "getNode error" << endl;
			return nullptr;
		}
	}
	return pNode;
}

template<typename T>
inline T CircylarLinkedList<T>::getValue(int index) const
{
	return getNode(index)->value;
}

template<typename T>
inline CircylarLinkedListNode<T>* CircylarLinkedList<T>::insert(int index, T t)
{
	if (index == 0) {
		return insertFront(t);
	}
	CircylarLinkedListNode<T> *pNode = getNode(index);
	if (!pNode) {
		cerr << "insert error" << endl;
		return nullptr;
	}
	CircylarLinkedListNode<T> *newNode = new CircylarLinkedListNode<T>(t, pNode->pNext);
	pNode->pNext = newNode;
	++count;
	return newNode;
}

template<typename T>
inline CircylarLinkedListNode<T>* CircylarLinkedList<T>::insertFront(T t)
{
	CircylarLinkedListNode<T> *newNode = new CircylarLinkedListNode<T>(t, pHead);
	pHead->pNext = newNode;
	++count;
	return newNode;
}

template<typename T>
inline CircylarLinkedListNode<T>* CircylarLinkedList<T>::insertLast(T t)
{
	return insert(count, t);
}

template<typename T>
inline T CircylarLinkedList<T>::deleteN(int index)
{
	CircylarLinkedListNode<T> *preNode = getNode(index - 1);
	if (!preNode) {
		cerr << "deleteN error" << endl;
		return 0;
	}
	CircylarLinkedListNode<T> *delNode = preNode->pNext;
	if (!delNode || (delNode == pHead)) {
		cerr << "deleteN error" << endl;
		return 0;
	}
	preNode->pNext = delNode->pNext;
	T temp = delNode->value;
	delete delNode;
	--count;
	return temp;
}

template<typename T>
inline T CircylarLinkedList<T>::deleteFront()
{
	return deleteN(1);
}

template<typename T>
inline T CircylarLinkedList<T>::deleteLast()
{
	return deleteN(count);
}

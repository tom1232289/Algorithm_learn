#pragma once

#ifndef SINGLYLINKED_H
#define SINGLYLINKED_H

#include "SinglyLinkedNode.h"

template <typename T>
class SinglyLinkedList {
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	bool isEmpty() const;
	size_t size() const;
	SinglyLinkedNode<T> *getHead() const;

	SinglyLinkedNode<T> *getNode(int index) const;
	T getValue(int index) const;

	SinglyLinkedNode<T> *insert(int index, T t);
	SinglyLinkedNode<T> *insertFront(T t);
	SinglyLinkedNode<T> *insertLast(T t);

	T deleteN(int index);
	T deleteFront();
	T deleteLast();

public:
	SinglyLinkedNode<T> * pHead = nullptr;
	int count = 0;
};

#endif	// !SINGLYLINKED_H

template<typename T>
inline SinglyLinkedList<T>::SinglyLinkedList()
{
	pHead = new SinglyLinkedNode<T>(0, nullptr);
}

template<typename T>
inline SinglyLinkedList<T>::~SinglyLinkedList()
{
	SinglyLinkedNode<T> *pNode = pHead->pNext;
	if (pNode) {
		SinglyLinkedNode<T> *pTemp = pNode;
		pNode = pNode->pNext;
		delete pTemp;
	}
	if (pHead) {
		delete pHead;
		pHead = nullptr;
	}
}

template<typename T>
inline bool SinglyLinkedList<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t SinglyLinkedList<T>::size() const
{
	return count;
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedList<T>::getHead() const
{
	return pHead;
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedList<T>::getNode(int index) const
{
	if (index < 0 || index > count) {
		cerr << "getNode error" << endl;
		return nullptr;
	}
	SinglyLinkedNode<T> *pNode = pHead;
	int nTemp = 0;
	while (nTemp < index) {
		pNode = pNode->pNext;
		if (!pNode) {
			cerr << "getNode error" << endl;
			return nullptr;
		}
		++nTemp;
	}
	return pNode;
}

template<typename T>
inline T SinglyLinkedList<T>::getValue(int index) const
{
	return getNode(index)->value;
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedList<T>::insert(int index, T t)
{
	SinglyLinkedNode<T>* pNode = getNode(index);
	if (!pNode) {
		cerr << "insert error" << endl;
		return nullptr;
	}
	SinglyLinkedNode<T> *newNode = new SinglyLinkedNode<T>(t, pNode->pNext);
	pNode->pNext = newNode;
	++count;

	return NULL;
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedList<T>::insertFront(T t)
{
	return insert(0, t);
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedList<T>::insertLast(T t)
{
	return insert(count, t);
}

template<typename T>
inline T SinglyLinkedList<T>::deleteN(int index)
{
	SinglyLinkedNode<T> *preNode = getNode(index - 1);
	if (!preNode) {
		cerr << "delete error" << endl;
		return 0;
	}
	SinglyLinkedNode<T> *pDelNode = preNode->pNext;
	preNode->pNext = pDelNode->pNext;
	T temp = pDelNode->value;
	delete pDelNode;
	--count;
	return temp;
}

template<typename T>
inline T SinglyLinkedList<T>::deleteFront()
{
	return deleteN(1);
}

template<typename T>
inline T SinglyLinkedList<T>::deleteLast()
{
	return deleteN(count);
}

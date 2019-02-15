#pragma once

#ifndef DOUBLECIRCULARLINKED_H
#define DOUBLECIRCULARLINKED_H

#include "DoubleCircularLinkedNode.h"

template <typename T>
class DoubleCircularLinked {
public:
	DoubleCircularLinked();
	~DoubleCircularLinked();

	size_t size() const;
	bool isEmpty() const;

	DoubleCircularLinkedNode<T> *getHead() const;
	DoubleCircularLinkedNode<T> *getNode(int index) const;
	T getValue(int index) const;

	DoubleCircularLinkedNode<T> *insert(int index, T t);
	DoubleCircularLinkedNode<T> *insertFirst(T t);
	DoubleCircularLinkedNode<T> *insertFront(T t);
	DoubleCircularLinkedNode<T> *insertLast(T t);

	T deleteN(int index);
	T deleteFront();
	T deleteLast();

public:
	DoubleCircularLinkedNode<T> *pHead;
	DoubleCircularLinkedNode<T> *pTemp;
	int count;
};

template <typename T>
DoubleCircularLinked<T>::DoubleCircularLinked() {
	count = 0;
	pHead = new DoubleCircularLinkedNode<T>(0, nullptr, nullptr);
	pTemp = new DoubleCircularLinkedNode<T>(0, nullptr, nullptr);
	pHead->pNext = pTemp;
	pHead->pPre = pTemp;
	pTemp->pNext = pHead;
	pTemp->pPre = pHead;
}

template <typename T>
DoubleCircularLinked<T>::~DoubleCircularLinked() {
	DoubleCircularLinkedNode<T> *pNode = pHead->pNext;
	while (pNode != pHead) {
		DoubleCircularLinkedNode<T> *temp = pNode;
		pNode = pNode->pNext;
		delete temp;
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

template <typename T>
size_t DoubleCircularLinked<T>::size() const {
	return count;
}

template <typename T>
bool DoubleCircularLinked<T>::isEmpty() const {
	return count == 0;
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::getHead() const {
	return pHead;
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::getNode(int index) const {
	if (index <= 0 || index > count) {
		cerr << "getNode error" << endl;
		return nullptr;
	}
	DoubleCircularLinkedNode<T> *pNode = pHead;
	int temp = 0;
	while (temp < index) {
		pNode = pNode->pNext;
		++temp;
	}
	return pNode;
}

template <typename T>
T DoubleCircularLinked<T>::getValue(int index) const {
	if (getNode(index) == nullptr) {
		cerr << "getValue error" << endl;
		return 0;
	}
	return getNode(index)->value;
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::insert(int index, T t) {
	if (index<0 || index>count) {
		cerr << "insert error" << endl;
		return nullptr;
	}
	if (count == 0)
		return insertFirst(t);
	else if (index == 0)
		return insertFront(t);
	else if (index == count)
		return insertLast(t);
	else {
		DoubleCircularLinkedNode<T> *preNode = getNode(index);
		if (!preNode) {
			cerr << "insert error" << endl;
			return nullptr;
		}
		DoubleCircularLinkedNode<T> *newNode = new DoubleCircularLinkedNode<T>(t, preNode, preNode->pNext);
		newNode = preNode->pNext->pPre;
		preNode->pNext = newNode;
		++count;
		return newNode;
	}
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::insertFirst(T t) {
	if (count != 0) {
		cerr << "insertFirst error" << endl;
		return nullptr;
	}
	DoubleCircularLinkedNode<T> *newNode = new DoubleCircularLinkedNode<T>(t, pHead, pHead);
	pHead->pNext = newNode;
	pHead->pPre = newNode;
	++count;
	return newNode;
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::insertFront(T t) {
	DoubleCircularLinkedNode<T> *newNode = new DoubleCircularLinkedNode<T>(t, pHead, pHead->pNext);
	pHead->pNext->pPre = newNode;
	pHead->pNext = newNode;
	++count;
	return newNode;
}

template <typename T>
DoubleCircularLinkedNode<T> *DoubleCircularLinked<T>::insertLast(T t) {
	DoubleCircularLinkedNode<T> *newNode = new DoubleCircularLinkedNode<T>(t, pHead->pPre, pHead);
	pHead->pPre->pNext = newNode;
	pHead->pPre = newNode;
	++count;
	return newNode;
}

template <typename T>
T DoubleCircularLinked<T>::deleteN(int index) {
	if (index == 1)
		return deleteFront();
	DoubleCircularLinkedNode<T> *preNode = getNode(index - 1);
	if (!preNode) {
		cerr << "deleteN error" << endl;
		return 0;
	}
	DoubleCircularLinkedNode<T> *pNode = preNode->pNext;
	if (!pNode) {
		cerr << "deleteN error" << endl;
		return 0;
	}
	pNode->pNext->pPre = preNode;
	preNode->pNext = pNode->pNext;
	T temp = pNode->value;
	delete pNode;
	--count;
	return temp;
}

template <typename T>
T DoubleCircularLinked<T>::deleteFront() {
	DoubleCircularLinkedNode<T> *pNode = pHead->pNext;
	if (!pNode) {
		cerr << "deleteFront error" << endl;
		return 0;
	}
	pNode->pNext->pPre = pHead;
	pHead->pNext = pNode->pNext;
	T temp = pNode->value;
	delete pNode;
	--count;
	return temp;
}

// 多余
template <typename T>
T DoubleCircularLinked<T>::deleteLast() {
	DoubleCircularLinkedNode<T> *pNode = pHead->pPre;
	if (!pNode) {
		cerr << "deleteLast error" << endl;
		return 0;
	}
	pNode->pPre->pNext = pHead;
	pHead->pPre = pNode->pPre;
	T temp = pNode->value;
	delete pNode;
	--count;
	return temp;
}

#endif	// !DOUBLECIRCULARLINKED_H

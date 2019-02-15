#pragma once
#ifndef DOUBLELINK_H_INCLUDE
#define DOUBLELINK_H_INCLUDE

#include "DoubleLinkNode.h"
#include <iostream>

using namespace std;

template <typename T>
class DoubleLink {
public:
	DoubleLink();
	~DoubleLink();

	DoubleLinkNode<T> * getHead() const;
	DoubleLinkNode<T> * getNode(int index) const;
	T getValue(int index) const;

	int size() const;
	bool isEmpty() const;

	DoubleLinkNode<T> * insert(int index, T t);
	DoubleLinkNode<T> * insertFront(T t);
	DoubleLinkNode<T> * insertLast(T t);

	T deleteN(int index);
	T deleteFront();
	T deleteLast();

public:
	int count;
	DoubleLinkNode<T> *pHead;
	DoubleLinkNode<T> *pTemp;
};

template <typename T>
DoubleLink<T>::DoubleLink() {
	count = 0;
	pHead = new DoubleLinkNode<T>(0, nullptr, nullptr);
	pTemp = new DoubleLinkNode<T>(0, nullptr, nullptr);
	pHead->pNext = pTemp;
	pTemp->pPre = pHead;
}

template <typename T>
DoubleLink<T>::~DoubleLink() {
	DoubleLinkNode<T> *pNode = pHead->pNext;
	while (pNode) {
		DoubleLinkNode<T> *temp = pNode;
		pNode = pNode->pNext;
		delete temp;
	}
	/*if (pTemp != nullptr && count != 0) {
		delete pTemp;
		pTemp = nullptr;
	}*/
}

template <typename T>
DoubleLinkNode<T> * DoubleLink<T>::getHead() const {
	return pHead;
}

template <typename T>
DoubleLinkNode<T> * DoubleLink<T>::getNode(int index) const {
	if (index <= 0 || index > count) {
		cerr << "getNode error" << endl;
		return nullptr;
	}
	DoubleLinkNode<T> *pNode = pHead;
	int temp = 0;
	while (temp < index) {
		pNode = pNode->pNext;
		++temp;
	}
	return pNode;
}

template <typename T>
T DoubleLink<T>::getValue(int index) const {
	return getNode(index)->value;
}

template <typename T>
int DoubleLink<T>::size() const {
	return count;
}

template <typename T>
bool DoubleLink<T>::isEmpty() const {
	return count == 0;
}

template <typename T>
DoubleLinkNode<T> * DoubleLink<T>::insert(int index, T t) {
	if (index == 1)
		return insertFront(t);
	else if (index == count)
		return insertLast(t);
	DoubleLinkNode<T> *pNode = getNode(index);
	if (!pNode) {
		cerr << "insert error" << endl;
		return nullptr;
	}
	DoubleLinkNode<T> *newNode = new DoubleLinkNode<T>(t, pNode, pNode->pNext);
	pNode->pNext->pPre = newNode;
	pNode->pNext = newNode;
	++count;
	return newNode;
}

template <typename T>
DoubleLinkNode<T> * DoubleLink<T>::insertFront(T t) {
	DoubleLinkNode<T> *newNode = new DoubleLinkNode<T>(t, pHead, pHead->pNext);
	pHead->pNext->pPre = newNode;
	pHead->pNext = newNode;
	++count;
	return newNode;
}

template <typename T>
DoubleLinkNode<T> * DoubleLink<T>::insertLast(T t) {
	DoubleLinkNode<T> *pNode = getNode(count);
	if (!pNode) {
		cerr << "insertLast error" << endl;
		return nullptr;
	}
	DoubleLinkNode<T> *newNode = new DoubleLinkNode<T>(t, pNode, nullptr);
	pNode->pNext = newNode;
	++count;
	return newNode;
}

template<typename T>
inline T DoubleLink<T>::deleteN(int index)
{
	if (index == 1)
		return deleteFront();
	// 	else if (index == count)
	// 		return deleteLast();
	else {
		DoubleLinkNode<T> *pPreNode = getNode(index - 1);
		if (!pPreNode) {
			cerr << "delete error" << endl;
			return 0;
		}
		DoubleLinkNode<T> *pNode = pPreNode->pNext;
		if (!pNode) {
			cerr << "delete error" << endl;
			return 0;
		}
		pPreNode->pNext = pNode->pNext;
		if (pNode->pNext)
			pNode->pNext->pPre = pPreNode;
		T tem = pNode->value;
		delete pNode;
		pNode = nullptr;
		--count;

		return tem;
	}
}

template<typename T>
inline T DoubleLink<T>::deleteFront()
{
	if (!pHead) {
		cerr << "delete front error, no pHead error" << endl;
		return 0;
	}
	DoubleLinkNode<T> *pNode = pHead->pNext;
	if (!pNode) {
		cerr << "delete front error" << endl;
		return 0;
	}
	pHead->pNext = pNode->pNext;
	pNode->pNext->pPre = pHead;
	T tmp = pNode->value;
	delete pNode;
	pNode = nullptr;
	--count;

	return tmp;
}

template<typename T>
inline T DoubleLink<T>::deleteLast()
{
	return 0;
}

#endif	// !DOUBLELINK_H_INCLUDE
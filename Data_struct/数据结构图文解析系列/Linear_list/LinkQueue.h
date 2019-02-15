#pragma once

#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class LinkQueue {
public:
	LinkQueue();
	~LinkQueue();

public:
	bool isEmpty() const;
	size_t size() const;
	void push(T t);
	bool pop();
	T getFront() const;

private:
	Node<T> *pHead = nullptr;
	Node<T> *pEnd = nullptr;
	int count = 0;
};

template<typename T>
inline LinkQueue<T>::LinkQueue() :
	pHead(new Node<T>),
	pEnd(pHead),
	count(0)
{	}

template<typename T>
inline LinkQueue<T>::~LinkQueue()
{
	Node<T> *pNode = pHead;
	while (pNode != nullptr) {
		Node<T> *temp = pNode;
		pNode = pNode->pNext;
		delete temp;
	}
}

template<typename T>
inline bool LinkQueue<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t LinkQueue<T>::size() const
{
	return count;
}

template<typename T>
inline void LinkQueue<T>::push(T t)
{
	Node<T> *pNode = new Node<T>(t);
	pEnd->pNext = pNode;
	pEnd = pNode;
	++count;
}

template<typename T>
inline bool LinkQueue<T>::pop()
{
	if (count == 0)
		return false;
	else {
		Node<T> *pNode = pHead->pNext;
		pHead->pNext = pNode->pNext;
		delete pNode;
		pNode = nullptr;
		--count;
		return true;
	}
}

template<typename T>
inline T LinkQueue<T>::getFront() const
{
	return pHead->pNext->value;
}

#endif	// !LINK_QUEUE_H
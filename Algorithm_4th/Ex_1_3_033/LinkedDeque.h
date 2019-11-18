#pragma once

// Deque。一个双向队列（或者称为 deque）和栈或队列类似，但它同时支持在两端添加或删除元素。Deque 能够存储一组元素并支持表 1.3.9 中的 API：
//表 1.3.9　泛型双向队列的 API
//
//public class Deque<Item> implements Iterable<Item>
//Deque()	创建空双向队列
//boolean   isEmpty()	双向队列是否为空
//int   size()	双向队列中的元素数量
//void   pushLeft(Item item)	向左端添加一个新元素
//void   pushRight(Item item)	向右端添加一个新元素
//Item   popLeft()	从左端删除一个元素
//Item   popRight()	从右端删除一个元素
//编写一个使用双向链表实现这份 API 的 Deque 类，以及一个使用动态数组调整实现这份 API 的 ResizingArrayDeque 类。

#ifndef LINKED_DEQUE
#define LINKED_DEQUE

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

template <typename T>
class LinkedDeque
{
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
	LinkedDeque() :
		m_pHead(new Node()),
		m_pTail(m_pHead)
	{}
	~LinkedDeque();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	void pushLeft(T t);
	void pushRight(T t);
	T popLeft();
	T popRight();

private:
	size_t m_iCount = 0;
	Node *m_pHead = nullptr;
	Node *m_pTail = nullptr;
};

template <typename T>
LinkedDeque<T>::~LinkedDeque()
{
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode; pDelNode = nullptr;
	}
}

template <typename T>
void LinkedDeque<T>::pushLeft(T t)
{
	Node *pNewNode = new Node(t);
	pNewNode->pNext = m_pHead->pNext;
	if (m_pHead->pNext != nullptr) {
		m_pHead->pNext->pPre = pNewNode;
	}
	m_pHead->pNext = pNewNode;
	pNewNode->pPre = m_pHead;

	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}

	++m_iCount;
}

template <typename T>
void LinkedDeque<T>::pushRight(T t)
{
	Node *pNewNode = new Node(t);
	m_pTail->pNext = pNewNode;
	pNewNode->pPre = m_pTail;
	m_pTail = pNewNode;

	if (m_iCount == 0) {
		m_pHead->pNext = pNewNode;
	}

	++m_iCount;
}

template <typename T>
T LinkedDeque<T>::popLeft()
{
	Node *pNode = m_pHead->pNext;
	if (pNode == nullptr) {
		LogError("popLeft on the empty LinkedDeque");
	}

	m_pHead->pNext = pNode->pNext;
	if (m_pHead->pNext != nullptr) {
		pNode->pNext->pPre = m_pHead;
	}
	T ret = pNode->value;
	delete pNode; pNode = nullptr;

	if (m_iCount == 1) {
		m_pHead->pNext = nullptr;
		m_pTail = m_pHead;
	}

	--m_iCount;
	
	return ret;
}

template <typename T>
T LinkedDeque<T>::popRight()
{
	if (m_pTail == nullptr) {
		LogError("popRight on the empty LinkedDeque");
	}
	Node *pNode = m_pTail->pPre;
	if (pNode == nullptr) {
		LogError("popRight on the empty LinkedDeque");
	}

	T ret = m_pTail->value;
	delete m_pTail;
	m_pTail = pNode;
	m_pTail->pNext = nullptr;

	if (m_iCount == 1) {
		m_pHead->pNext = nullptr;
	}

	--m_iCount;

	return ret;
}

#endif	// !LINKED_DEQUE
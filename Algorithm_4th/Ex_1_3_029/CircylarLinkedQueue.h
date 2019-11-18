// 循环链式队列

#pragma once

#ifndef CIRCYLAR_LINKED_QUEUE
#define CIRCYLAR_LINKED_QUEUE

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"
#include <iterator>

using namespace LogInfo;

template <typename T>
class CircylarLinkedQueue
{
	class Node {
	public:
		Node(T val = T()) :
			value(val) {}
	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	CircylarLinkedQueue() :
		m_pHead(new Node()),
		m_pTail(m_pHead)
	{}
	~CircylarLinkedQueue();

public:
	bool isEmpty() const { return m_iCount == 0; }
	int size() const { return m_iCount; }
	void push(T t);
	T pop();
	T erase(int index);

private:
	Node * getNode(int index);

private:
	// 内置迭代器
	class MyIterator : iterator<input_iterator_tag, T> {
	public:
		MyIterator(Node *pNode = nullptr):
			m_pNode(pNode)
		{}

	public:
		T operator*() const {
			return m_pNode->value;
		}
		Node * operator->() const {
			return m_pNode;
		}
		MyIterator & operator++() {
			m_pNode = m_pNode->pNext;
			return *this;
		}
		MyIterator & operator++(int) {
			Node *pRet = m_pNode;
			m_pNode = m_pNode->pNext;
			return (MyIterator)pRet;
		}
		bool operator==(const MyIterator &rhs) const {
			return m_pNode == rhs.m_pNode;
		}
		bool operator!=(const MyIterator &rhs) const {
			return !(*this == rhs);
		}

	private:
		Node *m_pNode = nullptr;
	};

public:
	MyIterator begin() const {
		return m_pHead->pNext;
	}

	MyIterator end() const {
		return m_pTail;			// 环形队列的尾指针指向最后一个元素，m_pTail->pNext指向第一个元素，遍历的时候会漏掉最后一个元素，需要通过end()获取最后一个元素
	}

private:
	int m_iCount = 0;
	Node *m_pHead = nullptr;
	Node *m_pTail = nullptr;
};

template <typename T>
CircylarLinkedQueue<T>::~CircylarLinkedQueue()
{
	if (m_iCount != 0) {
		Node *pNode = m_pHead->pNext;
		while (pNode != m_pTail) {
			Node *pDelNode = pNode;
			pNode = pNode->pNext;
			delete pDelNode;
		}
		if (m_pTail != nullptr) {
			delete m_pTail; m_pTail = nullptr;
		}
	}
	delete m_pHead; m_pHead = nullptr;
}

template <typename T>
void CircylarLinkedQueue<T>::push(T t)
{
	Node *pNode = new Node(t);
	m_pTail->pNext = pNode;
	m_pTail = pNode;
	pNode->pNext = m_pHead->pNext;
	if (m_iCount == 0) {
		m_pHead->pNext = pNode;
	}
	++m_iCount;
}

template <typename T>
T CircylarLinkedQueue<T>::pop()
{
	if (m_iCount <= 0) {
		LogError("pop in empty queue");
	}

	Node *pNode = m_pHead->pNext;
	T ret = T();

	ret = pNode->value;
	m_pHead->pNext = pNode->pNext;
	m_pTail->pNext = m_pHead->pNext;
	delete pNode; pNode = nullptr;
	--m_iCount;
	if (m_iCount == 0) {
		m_pHead->pNext = nullptr;
		m_pTail = m_pHead;
	}

	return ret;
}

template <typename T>
typename CircylarLinkedQueue<T>::Node * CircylarLinkedQueue<T>::getNode(int index)
{
	if (index < 0 || index > m_iCount) {
		LogError("getNode error");
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
T CircylarLinkedQueue<T>::erase(int index)
{
	Node *pNode = getNode(index - 1);
	if (pNode == nullptr) {
		LogError("getNode return nullptr");
	}

	Node *pDelNode = pNode->pNext;
	if (pDelNode == nullptr) {
		LogError("erase: index error");
	}

	pNode->pNext = pDelNode->pNext;
	T ret = pDelNode->value;
	delete pDelNode; pDelNode = nullptr;

	if (index == m_iCount) {
		m_pTail = pNode;
	}

	--m_iCount;

	if (m_iCount == 0) {
		m_pTail = m_pHead;
	}

	return ret;
}

#endif	// !CIRCYLAR_LINKED_QUEUE
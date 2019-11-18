// 先进先出队列

#pragma once

#ifndef LING_QUEUE_H
#define LING_QUEUE_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include <iterator>
#include "../Utils/LogInfo.h"

using namespace std;
using namespace LogInfo;

template <typename T>
class LinkQueue
{
private:
	class Node {
	public:
		Node(T t = T()) :
			value(t) {}

	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	LinkQueue() :
		m_pHead(new Node()),
		m_pTail(m_pHead) {}
	LinkQueue(const LinkQueue &rhs);
	LinkQueue & operator=(const LinkQueue &rhs);
	~LinkQueue();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	T front();
	void push(T t);
	T pop();
	T erase(int index);
	void catenation(LinkQueue &rhs);

private:
	Node * getNode(int index);

private:
	// 内置迭代器
	class MyIterator :public iterator<input_iterator_tag, T> {
	public:
		MyIterator(Node *pNode = nullptr) :
			m_pNode(pNode) {}

	public:
		T operator*() const {
			return m_pNode->value;
		}

		Node * operator->() const {
			return m_pNode;
		}

		MyIterator operator++() {
			m_pNode = m_pNode->pNext;
			return *this;
		}

		MyIterator operator++(int) {
			Node *pRet = m_pNode;
			m_pNode = m_pNode->pNext;
			return (MyIterator)pRet;
		}

		bool operator==(MyIterator & rhs) const {
			return m_pNode == rhs.m_pNode;
		}

		bool operator!=(MyIterator & rhs) const {
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
		return m_pTail->pNext;	// 返回尾节点的下一个位置
	}

private:
	Node *m_pHead = nullptr;		// 头结点
	Node *m_pTail = nullptr;		// 尾节点
	size_t m_iCount = 0;			// 栈的大小
};

template <typename T>
LinkQueue<T>::~LinkQueue()
{
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
	}
}

template <typename T>
LinkQueue<T>::LinkQueue(const LinkQueue &rhs) :
	m_iCount(rhs.m_iCount),
	m_pHead(new Node()),
	m_pTail(m_pHead)
{
	Node *pRhsNode = rhs.m_pHead->pNext;
	Node *pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// 创建新节点
		Node *pNewNode = new Node(pRhsNode->value);
		// pNext指向新节点
		pNode->pNext = pNewNode;
		// 尾节点指向新节点
		m_pTail = pNewNode;
		// 移动pNode、pRhsNode到下一个位置
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}
}

template <typename T>
LinkQueue<T> & LinkQueue<T>::operator=(const LinkQueue & rhs)
{
	// 考虑自赋值的情况
	if (m_pHead == rhs.m_pHead) {
		return *this;
	}

	// 执行析构函数的功能（不删除头结点）
	Node *pNode = m_pHead->pNext;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
	}

	// 执行拷贝构造函数的功能
	m_iCount = rhs.m_iCount;
	Node *pRhsNode = rhs.m_pHead->pNext;
	pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// 创建新节点
		Node *pNewNode = new Node(pRhsNode->value);
		// pNext指向新节点
		pNode->pNext = pNewNode;
		// 尾节点指向新节点
		m_pTail = pNewNode;
		// 移动pNode、pRhsNode到下一个位置
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}

	return *this;
}

template <typename T>
T LinkQueue<T>::front()
{
	// 队空
	if (m_pHead->pNext == nullptr)
		return T();

	return m_pHead->pNext->value;
}

template <typename T>
void LinkQueue<T>::push(T t)
{
	// 创建新节点
	Node *pNewNode = new Node(t);
	// 添加新节点
	m_pTail->pNext = pNewNode;
	// 更新尾节点的位置
	m_pTail = pNewNode;
	// 若栈为空时，更新头结点的next指针
	if (m_iCount == 0) {
		m_pHead->pNext = pNewNode;
	}
	++m_iCount;
}

template <typename T>
T LinkQueue<T>::pop()
{
	// 队空
	if (m_pHead->pNext == nullptr)
		return T();

	// 记录队首节点和节点的值
	Node *pFrontNode = m_pHead->pNext;
	T frontValue = pFrontNode->value;
	// 调整pNext指针指向位置
	m_pHead->pNext = m_pHead->pNext->pNext;
	// 删除队首节点
	delete pFrontNode;
	pFrontNode = nullptr;
	--m_iCount;
	// 若队为空时，更新尾节点
	if (m_iCount == 0) {
		m_pTail = m_pHead;
	}

	return frontValue;
}

template <typename T>
typename LinkQueue<T>::Node * LinkQueue<T>::getNode(int index)
{
	if (index < 0 || index > m_iCount) {
		LogError("getNode: index error");
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
T LinkQueue<T>::erase(int index)
{
	Node *pNode = getNode(index - 1);
	if (pNode == nullptr) {
		LogError("erase:getNode return nullptr");
	}

	Node *pDelNode = pNode->pNext;
	if (pDelNode == nullptr) {
		LogError("erase:pDelNode is nullptr");
	}

	T retValue = pDelNode->value;
	pNode->pNext = pDelNode->pNext;
	delete pDelNode; pDelNode = nullptr;

	if (index == m_iCount) {
		m_pTail = pNode;
	}
	if (m_iCount == 1) {
		m_pTail = m_pHead;
	}

	--m_iCount;

	return retValue;
}

template<typename T>
void LinkQueue<T>::catenation(LinkQueue & rhs)
{
	if (rhs.isEmpty()) {
		return;
	}
	else if (isEmpty()) {
		m_pHead->pNext = rhs.m_pHead->pNext;
		m_pTail = rhs.m_pTail;
		m_iCount = rhs.m_iCount;
		// 重置rhs的状态
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
	else {
		m_pTail->pNext = rhs.m_pHead->pNext;
		m_pTail = rhs.m_pTail;
		m_iCount += rhs.m_iCount;
		// 重置rhs的状态
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
}

#endif // !LING_QUEUE_H

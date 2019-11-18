// �Ƚ��ȳ�����

#pragma once

#ifndef LING_QUEUE_H
#define LING_QUEUE_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
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
	// ���õ�����
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
		return m_pTail->pNext;	// ����β�ڵ����һ��λ��
	}

private:
	Node *m_pHead = nullptr;		// ͷ���
	Node *m_pTail = nullptr;		// β�ڵ�
	size_t m_iCount = 0;			// ջ�Ĵ�С
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
		// �����½ڵ�
		Node *pNewNode = new Node(pRhsNode->value);
		// pNextָ���½ڵ�
		pNode->pNext = pNewNode;
		// β�ڵ�ָ���½ڵ�
		m_pTail = pNewNode;
		// �ƶ�pNode��pRhsNode����һ��λ��
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}
}

template <typename T>
LinkQueue<T> & LinkQueue<T>::operator=(const LinkQueue & rhs)
{
	// �����Ը�ֵ�����
	if (m_pHead == rhs.m_pHead) {
		return *this;
	}

	// ִ�����������Ĺ��ܣ���ɾ��ͷ��㣩
	Node *pNode = m_pHead->pNext;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
	}

	// ִ�п������캯���Ĺ���
	m_iCount = rhs.m_iCount;
	Node *pRhsNode = rhs.m_pHead->pNext;
	pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// �����½ڵ�
		Node *pNewNode = new Node(pRhsNode->value);
		// pNextָ���½ڵ�
		pNode->pNext = pNewNode;
		// β�ڵ�ָ���½ڵ�
		m_pTail = pNewNode;
		// �ƶ�pNode��pRhsNode����һ��λ��
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}

	return *this;
}

template <typename T>
T LinkQueue<T>::front()
{
	// �ӿ�
	if (m_pHead->pNext == nullptr)
		return T();

	return m_pHead->pNext->value;
}

template <typename T>
void LinkQueue<T>::push(T t)
{
	// �����½ڵ�
	Node *pNewNode = new Node(t);
	// ����½ڵ�
	m_pTail->pNext = pNewNode;
	// ����β�ڵ��λ��
	m_pTail = pNewNode;
	// ��ջΪ��ʱ������ͷ����nextָ��
	if (m_iCount == 0) {
		m_pHead->pNext = pNewNode;
	}
	++m_iCount;
}

template <typename T>
T LinkQueue<T>::pop()
{
	// �ӿ�
	if (m_pHead->pNext == nullptr)
		return T();

	// ��¼���׽ڵ�ͽڵ��ֵ
	Node *pFrontNode = m_pHead->pNext;
	T frontValue = pFrontNode->value;
	// ����pNextָ��ָ��λ��
	m_pHead->pNext = m_pHead->pNext->pNext;
	// ɾ�����׽ڵ�
	delete pFrontNode;
	pFrontNode = nullptr;
	--m_iCount;
	// ����Ϊ��ʱ������β�ڵ�
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
		// ����rhs��״̬
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
	else {
		m_pTail->pNext = rhs.m_pHead->pNext;
		m_pTail = rhs.m_pTail;
		m_iCount += rhs.m_iCount;
		// ����rhs��״̬
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
}

#endif // !LING_QUEUE_H

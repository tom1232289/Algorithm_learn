#pragma once

// Deque��һ��˫����У����߳�Ϊ deque����ջ��������ƣ�����ͬʱ֧����������ӻ�ɾ��Ԫ�ء�Deque �ܹ��洢һ��Ԫ�ز�֧�ֱ� 1.3.9 �е� API��
//�� 1.3.9������˫����е� API
//
//public class Deque<Item> implements Iterable<Item>
//Deque()	������˫�����
//boolean   isEmpty()	˫������Ƿ�Ϊ��
//int   size()	˫������е�Ԫ������
//void   pushLeft(Item item)	��������һ����Ԫ��
//void   pushRight(Item item)	���Ҷ����һ����Ԫ��
//Item   popLeft()	�����ɾ��һ��Ԫ��
//Item   popRight()	���Ҷ�ɾ��һ��Ԫ��
//��дһ��ʹ��˫������ʵ����� API �� Deque �࣬�Լ�һ��ʹ�ö�̬�������ʵ����� API �� ResizingArrayDeque �ࡣ

#ifndef LINKED_DEQUE
#define LINKED_DEQUE

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
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
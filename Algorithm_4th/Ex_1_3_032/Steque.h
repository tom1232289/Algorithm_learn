#pragma once

// Steque��һ����ջΪĿ��Ķ��У���� steque������һ��֧�� push��pop �� enqueue �������������͡�Ϊ���ֳ����������Ͷ���һ�� API ������һ�ݻ��������ʵ�֡�2
// 2push��pop ���ǶԶ���ͬһ�˵Ĳ�����enqueue �� push ��Ӧ�����������Ƕ��е���һ�ˡ���������ע

#ifndef STEQUE
#define STEQUE

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

template <typename T>
class Steque
{
	class Node {
	public:
		Node(T t = T()) :
			value(t) {}

	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	Steque() :
		m_pHead(new Node()),
		m_pTail(m_pHead)
	{}
	~Steque();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	void push(T t);
	T pop();
	void enqueue(T t);
	void catenation(Steque &rhs);

private:
	size_t m_iCount = 0;
	Node *m_pHead = nullptr;
	Node *m_pTail = nullptr;
};

template <typename T>
Steque<T>::~Steque()
{
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode; pDelNode = nullptr;
	}
}

template <typename T>
void Steque<T>::push(T t)
{
	Node *pNewNode = new Node(t);
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}

	++m_iCount;
}

template <typename T>
T Steque<T>::pop()
{
	Node *pNode = m_pHead->pNext;
	if (pNode == nullptr) {
		LogError("pop on the empty steque");
	}

	m_pHead->pNext = pNode->pNext;
	T ret = pNode->value;
	delete pNode; pNode = nullptr;

	if (m_iCount == 1) {
		m_pTail = m_pHead;
	}

	--m_iCount;

	return ret;
}

template <typename T>
void Steque<T>::enqueue(T t)
{
	Node *pNewNode = new Node(t);
	m_pTail->pNext = pNewNode;
	m_pTail = pNewNode;
	if (m_iCount == 0) {
		m_pHead->pNext = pNewNode;
	}

	++m_iCount;
}

template<typename T>
void Steque<T>::catenation(Steque & rhs)
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

#endif	// !STEQUE

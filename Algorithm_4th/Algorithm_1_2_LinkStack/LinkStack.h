// ��ѹ��ջ������ʵ�֣�

#pragma once

#ifndef LINK_STACK_H
#define LINK_STACK_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
class LinkStack
{
private:
	// ��������ڵ�
	class Node {
	public:
		Node(T t = T()) :
			value(t)
		{	}

	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	LinkStack() :
		m_pHead(new Node()),
		m_pTail(m_pHead)
	{	}
	LinkStack(const LinkStack &rhs);
	LinkStack & operator=(const LinkStack &rhs);
	~LinkStack();

public:
	bool isEmpty() const;	// ջ�Ƿ�Ϊ��
	size_t size() const;	// ջ�Ĵ�С
	T top() const;			// ��ȡջ��Ԫ��
	void push(T t);			// ��ջ
	T pop();				// ��ջ
	void clear();			// ���ջ
	void catenation(LinkStack &rhs);

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

		MyIterator & operator++() {
			m_pNode = m_pNode->pNext;
			return *this;
		}

		MyIterator & operator++(int) {
			Node *pRet = m_pNode;
			m_pNode = m_pNode->pNext;
			return (MyIterator)pRet;
		}

		bool operator==(MyIterator &rhs) const {
			return m_pNode == rhs.m_pNode;
		}

		bool operator!=(MyIterator &rhs) const {
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
	size_t m_iCount = 0;			// ջ�Ĵ�С
	Node *m_pHead = nullptr;		// ͷ���
	Node *m_pTail = nullptr;		// β�ڵ㣨���ڱ�����
};

template <typename T>
LinkStack<T>::~LinkStack()
{
	if (m_pHead != nullptr) {
		Node *pNode = m_pHead->pNext;
		while (pNode != nullptr) {
			Node *pTemp = pNode;
			pNode = pNode->pNext;
			delete pTemp;
		}

		delete m_pHead;	m_pHead = nullptr;
	}
	m_pTail = nullptr;
}

template <typename T>
LinkStack<T>::LinkStack(const LinkStack<T> &rhs) :
	m_iCount(rhs.m_iCount),
	m_pHead(new Node())
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
		// pNode��pRhsNodeָ����Ե���һ��λ��
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}
}

template <typename T>
LinkStack<T> & LinkStack<T>::operator=(const LinkStack<T> &rhs)
{
	// �����Ը�ֵ�����
	if (m_pHead == rhs.m_pHead)
		return *this;

	// ִ�����������Ĺ���
	Node *pNode = m_pHead->pNext;
	while (pNode != nullptr) {
		Node *pTemp = pNode;
		pNode = pNode->pNext;
		delete pTemp;
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
		// pNode��pRhsNodeָ����Ե���һ��λ��
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}

	return *this;
}

template <typename T>
bool LinkStack<T>::isEmpty() const
{
	return m_iCount == 0;
}

template <typename T>
size_t LinkStack<T>::size() const
{
	return m_iCount;
}

template <typename T>
T LinkStack<T>::top() const
{
	if (m_pHead->pNext == nullptr) {
		return T();
	}
	else {
		return m_pHead->pNext->value;
	}
}

template <typename T>
void LinkStack<T>::push(T t)
{
	Node *pNewNode = new Node(t);
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;
	// ����ʱջ�գ�����ջβָ���λ��
	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}
	++m_iCount;
}

template <typename T>
T LinkStack<T>::pop()
{
	// ջ��
	if (m_pHead == nullptr || m_pHead->pNext == nullptr)
		return T();

	// ��¼ջ��Ԫ��
	T ret = m_pHead->pNext->value;
	// ��ջ
	Node *delNode = m_pHead->pNext;
	m_pHead->pNext = m_pHead->pNext->pNext;
	delete delNode;
	delNode = nullptr;
	--m_iCount;
	// ����ʱջ�գ�����ջβָ���λ��
	if (m_iCount == 0) {
		m_pTail = m_pHead;
	}

	return ret;
}

template <typename T>
void LinkStack<T>::clear()
{
	// ջ��
	if (m_pHead == nullptr || m_pHead->pNext == nullptr)
		return;

	Node *pNode = m_pHead->pNext;
	while (pNode != nullptr) {
		Node *pTemp = pNode;
		pNode = pNode->pNext;
		delete pTemp;
	}

	m_iCount = 0;
	m_pHead->pNext = nullptr;
	m_pTail = m_pHead;
}

template<typename T>
void LinkStack<T>::catenation(LinkStack & rhs)
{
	if (rhs.isEmpty()) {
		return;
	}
	else if (isEmpty()) {
		m_iCount = rhs.m_iCount;
		m_pHead->pNext = rhs.m_pHead->pNext;
		m_pTail = rhs.m_pTail;
		// ����rhs״̬
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
	else {
		rhs.m_pTail->pNext = m_pHead->pNext;
		m_pHead->pNext = rhs.m_pHead->pNext;
		m_iCount += rhs.m_iCount;
		// ����rhs״̬
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
}

#endif // !LINK_STACK_H
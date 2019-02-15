#pragma once

#ifndef LINK_STACK_H
#define LINK_STACK_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#define _UNICODE

#include "Node.h"

template <typename T>
class LinkStack
{
public:
	LinkStack() :
		count(0),
		pHead(new Node<T>())
	{	}
	LinkStack(const LinkStack &ls) :
		count(ls.count),
		pHead(new Node<T>())
	{	}
	LinkStack<T> & operator=(const LinkStack<T> &rhs);

	~LinkStack();

public:
	bool isEmpty() const;
	size_t size() const;
	T top() const;				// ��ȡջ��Ԫ��
	void push(T t);				// ��ջ
	T pop();					// ��ջ
	void clear();

private:
	size_t count = 0;
	Node<T> *pHead = nullptr;
};

template <typename T>
LinkStack<T>::~LinkStack() {
	Node<T> *pNode = pHead->pNext;
	while (pNode != nullptr) {
		Node<T> *temp = pNode;
		pNode = pNode->pNext;
		delete temp;
	}
	delete pHead;
	pHead = nullptr;
}

template<typename T>
inline bool LinkStack<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t LinkStack<T>::size() const
{
	return count;
}

template<typename T>
inline T LinkStack<T>::top() const
{
	if (pHead->pNext != nullptr)
		return pHead->pNext->value;
	else
		return T();
}

template<typename T>
inline void LinkStack<T>::push(T t)
{
	Node<T> *newNode = new Node<T>(t, pHead->pNext);
	pHead->pNext = newNode;
	++count;
}

template<typename T>
inline T LinkStack<T>::pop()
{
	Node<T> *pNode = pHead->pNext;
	if (pNode != nullptr) {
		T temp = pNode->value;
		pHead->pNext = pNode->pNext;
		delete pNode;
		--count;
		return temp;
	}
	else
		return T();
}

template<typename T>
inline void LinkStack<T>::clear()
{
	Node<T> *pNode = pHead->pNext;
	while (pNode != nullptr) {
		Node<T> *temp = pNode;
		pNode = pNode->pNext;
		delete temp;
	}
	count = 0;
	pHead->pNext = nullptr;
}

template<typename T>
inline LinkStack<T> & LinkStack<T>::operator=(const LinkStack<T> & rhs)
{
	// TODO: �ڴ˴����� return ���
	auto newp = new Node<T>();
	delete pHead;
	pHead = newp;
	count = rhs.count;
	return *this;
}

#endif	// !LINK_STACK_H
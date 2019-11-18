// ��������ʽ�洢��

#pragma once

#ifndef LINK_BAG_H
#define LINK_BAG_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
class LinkBag
{
private:
	// ��������ڵ�
	class Node {
	public:
		Node(T t = T()) :
			value(t) {}

	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	LinkBag() :
		m_pHead(new Node()),
		m_pTail(m_pHead) {}
	LinkBag(const LinkBag &rhs);
	LinkBag & operator=(const LinkBag &rhs);
	~LinkBag();

public:
	bool isEmpty() const { return m_iCount == 0; }	// �����Ƿ�Ϊ��
	size_t size() const { return m_iCount; }		// �����Ĵ�С
	void push(T t);			// ���뱳��

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
		return m_pTail->pNext;
	}

private:
	size_t m_iCount = 0;		// �����Ĵ�С
	Node *m_pHead = nullptr;	// ͷ���ָ��
	Node *m_pTail = nullptr;	// β���ָ�루���ڱ�����
};

template <typename T>
LinkBag<T>::~LinkBag()
{
	// ��ͷ��㿪ʼɾ
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
		pDelNode = nullptr;
	}
}

template <typename T>
LinkBag<T>::LinkBag(const LinkBag &rhs) :
	m_iCount(rhs.m_iCount),
	m_pHead(new Node())
{
	Node *pRhsNode = rhs.m_pHead->pNext;
	Node *pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// �����½��
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
LinkBag<T> & LinkBag<T>::operator=(const LinkBag<T> &rhs)
{
	// �����Ը�ֵ�����
	if (m_pHead == rhs.m_pHead)
		return *this;

	// ִ�����������Ĺ���
	Node *pNode = m_pHead->pNext;
	while (pNode) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
		pDelNode = nullptr;
	}

	// ִ�п������캯���Ĺ���
	m_iCount = rhs.m_iCount;
	Node *pRhsNode = rhs.m_pHead->pNext;
	pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// �����½��
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
void LinkBag<T>::push(T t)
{
	Node *pNewNode = new Node(t);
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;
	// ����ʱ�����գ�����βָ���λ��
	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}
	// ����count
	++m_iCount;
}

#endif // !LINK_BAG_H
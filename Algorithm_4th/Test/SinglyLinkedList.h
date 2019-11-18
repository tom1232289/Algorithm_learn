// ������

#pragma once

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "../Utils/LogInfo.h"
#include <iterator>

using namespace std;
using namespace LogInfo;

template <typename T>
class SinglyLinkedList
{
public:
	// ��������
	class Node {
	public:
		Node(T t = T()) :
			value(t) {}

	public:
		T value = T();
		Node *pNext = nullptr;
	};

public:
	SinglyLinkedList() :
		m_pHead(new Node()),
		m_pTail(m_pHead)
	{}
	SinglyLinkedList(const SinglyLinkedList &rhs) = delete;
	SinglyLinkedList & operator=(const SinglyLinkedList &rhs) = delete;
	~SinglyLinkedList();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	Node* insert(int index, T t);
	T erase(int index);
	bool remove(T key);
	Node* getHead() { return m_pHead; }
	void setTail(Node *pNode) { m_pTail = pNode; }

private:
	Node *getNode(int index);

private:
	// ���õ�����
	class MyIterator : public iterator<input_iterator_tag, T> {
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
		return m_pTail->pNext;
	}

private:
	size_t m_iCount = 0;		// �������
	Node *m_pHead = nullptr;	// ͷ���ָ��
	Node *m_pTail = nullptr;	// β�ڵ�ָ��
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
		pDelNode = nullptr;
	}
}

template <typename T>
typename SinglyLinkedList<T>::Node * SinglyLinkedList<T>::getNode(int index)
{
	if (index < 0 || index > m_iCount) {
		LogError("getNode: out of range");
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
typename SinglyLinkedList<T>::Node * SinglyLinkedList<T>::insert(int index, T t)
{
	// �ҵ�Ҫ����Ľ���λ��
	Node *pNode = getNode(index);
	if (pNode == nullptr) {
		LogDebug("insert:" + to_string(index) + " out of range");
		return nullptr;
	}

	// �����½��
	Node *pNewNode = new Node(t);
	// ���Ľ��ָ��ָ��
	pNewNode->pNext = pNode->pNext;
	pNode->pNext = pNewNode;

	// ����βָ��
	if (index == m_iCount) {
		m_pTail = pNewNode;
	}

	// ���ȼ�һ
	++m_iCount;

	return pNewNode;
}

template <typename T>
T SinglyLinkedList<T>::erase(int index)
{
	if (index <= 0 || index > m_iCount) {
		LogError("erase: out of range");
	}

	// �ҵ�Ҫɾ���Ľ���ǰһ�����
	Node *pNode = getNode(index - 1);
	if (pNode == nullptr) {
		LogError("erase:index out of range");
		return T();
	}
	// �ҵ�Ҫɾ���Ľ��
	Node *pDelNode = pNode->pNext;
	if (pDelNode == nullptr) {
		LogError("erase:index out of range");
		return T();
	}
	// ���Ľ��ָ��ָ��
	pNode->pNext = pDelNode->pNext;
	// ����Ҫɾ���Ľ���ָ��
	T ret = pDelNode->value;
	// ɾ�����
	delete pDelNode;
	pDelNode = nullptr;
	// ����βָ��
	if (index == m_iCount) {
		m_pTail = pNode;
	}
	if (m_iCount == 1) {
		m_pTail = m_pHead;
	}
	// ���ȼ�һ
	--m_iCount;

	return ret;
}

template<typename T>
bool SinglyLinkedList<T>::remove(T key)
{
	bool bRet = false;
	Node *pNode = m_pHead;
	while (pNode != nullptr) {
		Node *pDelNode = pNode->pNext;
		if (pDelNode == nullptr) {
			break;
		}
		else {
			if (pDelNode->value == key) {
				bRet = true;
				// ���ɾ������β��㣬�����βָ��
				if (pDelNode->pNext == nullptr) {
					m_pTail = pNode;
				}
				// ɾ�����
				pNode->pNext = pDelNode->pNext;
				delete pDelNode; pDelNode = nullptr;
				--m_iCount;
			}
			else {
				pNode = pNode->pNext;
			}
		}
	}

	return bRet;
}

#endif // !SINGLY_LINKED_LIST_H

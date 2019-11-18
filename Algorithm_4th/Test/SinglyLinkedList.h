// 单链表

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
	// 单链表结点
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
	// 内置迭代器
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
	size_t m_iCount = 0;		// 链表个数
	Node *m_pHead = nullptr;	// 头结点指针
	Node *m_pTail = nullptr;	// 尾节点指针
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
	// 找到要插入的结点的位置
	Node *pNode = getNode(index);
	if (pNode == nullptr) {
		LogDebug("insert:" + to_string(index) + " out of range");
		return nullptr;
	}

	// 创建新结点
	Node *pNewNode = new Node(t);
	// 更改结点指针指向
	pNewNode->pNext = pNode->pNext;
	pNode->pNext = pNewNode;

	// 更改尾指针
	if (index == m_iCount) {
		m_pTail = pNewNode;
	}

	// 长度加一
	++m_iCount;

	return pNewNode;
}

template <typename T>
T SinglyLinkedList<T>::erase(int index)
{
	if (index <= 0 || index > m_iCount) {
		LogError("erase: out of range");
	}

	// 找到要删除的结点的前一个结点
	Node *pNode = getNode(index - 1);
	if (pNode == nullptr) {
		LogError("erase:index out of range");
		return T();
	}
	// 找到要删除的结点
	Node *pDelNode = pNode->pNext;
	if (pDelNode == nullptr) {
		LogError("erase:index out of range");
		return T();
	}
	// 更改结点指针指向
	pNode->pNext = pDelNode->pNext;
	// 保存要删除的结点的指针
	T ret = pDelNode->value;
	// 删除结点
	delete pDelNode;
	pDelNode = nullptr;
	// 更改尾指针
	if (index == m_iCount) {
		m_pTail = pNode;
	}
	if (m_iCount == 1) {
		m_pTail = m_pHead;
	}
	// 长度减一
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
				// 如果删除的是尾结点，则更新尾指针
				if (pDelNode->pNext == nullptr) {
					m_pTail = pNode;
				}
				// 删除结点
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

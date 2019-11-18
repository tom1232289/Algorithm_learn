// 背包（链式存储）

#pragma once

#ifndef LINK_BAG_H
#define LINK_BAG_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
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
	// 内置链表节点
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
	bool isEmpty() const { return m_iCount == 0; }	// 背包是否为空
	size_t size() const { return m_iCount; }		// 背包的大小
	void push(T t);			// 放入背包

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
	size_t m_iCount = 0;		// 背包的大小
	Node *m_pHead = nullptr;	// 头结点指针
	Node *m_pTail = nullptr;	// 尾结点指针（用于遍历）
};

template <typename T>
LinkBag<T>::~LinkBag()
{
	// 从头结点开始删
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
		// 创建新结点
		Node *pNewNode = new Node(pRhsNode->value);
		// pNext指向新节点
		pNode->pNext = pNewNode;
		// 尾节点指向新节点
		m_pTail = pNewNode;
		// pNode、pRhsNode指向各自的下一个位置
		pNode = pNode->pNext;
		pRhsNode = pRhsNode->pNext;
	}
}

template <typename T>
LinkBag<T> & LinkBag<T>::operator=(const LinkBag<T> &rhs)
{
	// 考虑自赋值的情况
	if (m_pHead == rhs.m_pHead)
		return *this;

	// 执行析构函数的功能
	Node *pNode = m_pHead->pNext;
	while (pNode) {
		Node *pDelNode = pNode;
		pNode = pNode->pNext;
		delete pDelNode;
		pDelNode = nullptr;
	}

	// 执行拷贝构造函数的功能
	m_iCount = rhs.m_iCount;
	Node *pRhsNode = rhs.m_pHead->pNext;
	pNode = m_pHead;
	while (pRhsNode != nullptr) {
		// 创建新结点
		Node *pNewNode = new Node(pRhsNode->value);
		// pNext指向新节点
		pNode->pNext = pNewNode;
		// 尾节点指向新节点
		m_pTail = pNewNode;
		// pNode、pRhsNode指向各自的下一个位置
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
	// 若此时背包空，更新尾指针的位置
	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}
	// 增加count
	++m_iCount;
}

#endif // !LINK_BAG_H
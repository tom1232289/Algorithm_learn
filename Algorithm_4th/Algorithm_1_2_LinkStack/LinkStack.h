// 下压堆栈（链表实现）

#pragma once

#ifndef LINK_STACK_H
#define LINK_STACK_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
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
	// 内置链表节点
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
	bool isEmpty() const;	// 栈是否为空
	size_t size() const;	// 栈的大小
	T top() const;			// 获取栈顶元素
	void push(T t);			// 入栈
	T pop();				// 出栈
	void clear();			// 清空栈
	void catenation(LinkStack &rhs);

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
		return m_pTail->pNext;	// 返回尾节点的下一个位置
	}

private:
	size_t m_iCount = 0;			// 栈的大小
	Node *m_pHead = nullptr;		// 头结点
	Node *m_pTail = nullptr;		// 尾节点（用于遍历）
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
		// 创建新节点
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
LinkStack<T> & LinkStack<T>::operator=(const LinkStack<T> &rhs)
{
	// 考虑自赋值的情况
	if (m_pHead == rhs.m_pHead)
		return *this;

	// 执行析构函数的功能
	Node *pNode = m_pHead->pNext;
	while (pNode != nullptr) {
		Node *pTemp = pNode;
		pNode = pNode->pNext;
		delete pTemp;
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
		// pNode、pRhsNode指向各自的下一个位置
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
	// 若此时栈空，更新栈尾指针的位置
	if (m_iCount == 0) {
		m_pTail = pNewNode;
	}
	++m_iCount;
}

template <typename T>
T LinkStack<T>::pop()
{
	// 栈空
	if (m_pHead == nullptr || m_pHead->pNext == nullptr)
		return T();

	// 记录栈顶元素
	T ret = m_pHead->pNext->value;
	// 出栈
	Node *delNode = m_pHead->pNext;
	m_pHead->pNext = m_pHead->pNext->pNext;
	delete delNode;
	delNode = nullptr;
	--m_iCount;
	// 若此时栈空，更新栈尾指针的位置
	if (m_iCount == 0) {
		m_pTail = m_pHead;
	}

	return ret;
}

template <typename T>
void LinkStack<T>::clear()
{
	// 栈空
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
		// 重置rhs状态
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
	else {
		rhs.m_pTail->pNext = m_pHead->pNext;
		m_pHead->pNext = rhs.m_pHead->pNext;
		m_iCount += rhs.m_iCount;
		// 重置rhs状态
		rhs.m_iCount = 0;
		rhs.m_pHead->pNext = nullptr;
		rhs.m_pTail = nullptr;
	}
}

#endif // !LINK_STACK_H
// 编写一个类 ResizingArrayQueueOfStrings，使用定长数组实现队列的抽象，然后扩展实现，使用调整数组的方法突破大小的限制。

#pragma once

#ifndef RESIZING_ARRAY_QUEUE_H
#define RESIZING_ARRAY_QUEUE_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

const int ICOUNT = 10;	// 默认分配的数组容量

template <typename T>
class ResizingArrayQueue
{
public:
	ResizingArrayQueue() :
		m_iCapacity(10),
		m_pArray(new T[ICOUNT]) {}
	ResizingArrayQueue(const ResizingArrayQueue &rhs);
	ResizingArrayQueue & operator=(const ResizingArrayQueue &rhs);
	~ResizingArrayQueue();

public:
	bool isEmpty() const { return m_iCount == 0; }
	size_t size() const { return m_iCount; }
	size_t capacity() const { return m_iCapacity; }
	bool resize(size_t max);	// 调整队列的容量为max，失败则返回false

	T top() const;	// 获取队首元素
	void push(T t);	// 入队列
	T pop();		// 出队列
	void clear();	// 清空队列
	T erase(int index);	// 按位置出队列

private:
	// 内置迭代器
	class iterator {
	public:
		iterator(T *ptr = nullptr) :
			m_ptr(ptr) {}

	public:
		T operator*() const {
			return *m_ptr;
		}
		T * operator->() const {
			return m_ptr;
		}
		iterator & operator++() {
			++m_ptr;
			return *this;
		}
		iterator & operator++(int) {
			T * pRet = m_ptr;
			++m_ptr;
			return (iterator)pRet;
		}
		iterator & operator--() {
			--m_ptr;
			return *this;
		}
		iterator & operator--(int) {
			T *pRet = m_ptr;
			--m_ptr;
			return (iterator)pRet;
		}
		bool operator==(const iterator &rhs) const {
			return m_ptr == rhs.m_ptr;
		}
		bool operator!=(const iterator &rhs) const {
			return !(*this == rhs);
		}

	private:
		T *m_ptr = nullptr;
	};

public:
	iterator begin() const {
		// 队列空
		if (isEmpty()) {
			LogError("begin() at empty queue");
		}

		return iterator(&(m_pArray[0]));
	}

	iterator end() const {
		// 队列空
		if (isEmpty()) {
			LogError("end() at empty queue");
		}

		return iterator(&(m_pArray[m_iCount - 1]) + 1);
	}

private:
	size_t m_iCount = 0;	// 队列的大小
	size_t m_iCapacity = 0;	// 队列的容量
	T *m_pArray = nullptr;	// 数组作为数据的表示方式
};

template <typename T>
ResizingArrayQueue<T>::~ResizingArrayQueue()
{
	if (m_iCount != 0) {
		delete[] m_pArray;
		m_pArray = nullptr;
	}
}

template <typename T>
ResizingArrayQueue<T>::ResizingArrayQueue(const ResizingArrayQueue<T> &rhs) :
	m_iCount(rhs.m_iCount),
	m_iCapacity(rhs.m_iCapacity)
{
	m_pArray = new T[m_iCapacity];
	for (size_t i = 0; i < m_iCount; ++i) {
		m_pArray[i] = rhs.m_pArray[i];
	}
}

template <typename T>
ResizingArrayQueue<T> & ResizingArrayQueue<T>::operator=(const ResizingArrayQueue<T> &rhs)
{
	// 考虑自赋值的情况，new一个新的数组
	T *pNewArray = new T[rhs.capacity()];
	for (size_t i = 0; i < rhs.m_iCount; ++i) {
		pNewArray[i] = rhs.m_pArray[i];
	}

	// 执行析构函数的功能
	delete[] m_pArray;

	// 执行拷贝构造函数的功能
	m_iCount = rhs.m_iCount;
	m_iCapacity = rhs.m_iCapacity;
	m_pArray = pNewArray;

	return *this;
}

template <typename T>
bool ResizingArrayQueue<T>::resize(size_t max)
{
	// 如果要调整的容量 <= 当前的容量，则返回false
	if (max <= m_iCapacity) {
		return false;
	}

	// 拷贝数组元素到新创建的数组上
	T *newArray = new T[max];
	for (size_t i = 0; i < m_iCount; ++i) {
		newArray[i] = m_pArray[i];
	}

	// 销毁旧的数组
	delete[] m_pArray;
	m_pArray = newArray;

	m_iCapacity = max;

	return true;
}

template <typename T>
T ResizingArrayQueue<T>::top() const
{
	// 队列为空
	if (m_iCount == 0)
		LogError("queue is empty");

	return m_pArray[0];
}

template <typename T>
void ResizingArrayQueue<T>::push(T t)
{
	// 若超出数组大小，则新开辟一块内存
	if (m_iCount == m_iCapacity) {
		resize(m_iCapacity + m_iCapacity / 4);
	}

	m_pArray[m_iCount++] = t;
}

template <typename T>
T ResizingArrayQueue<T>::pop()
{
	// 队列为空
	if (m_iCount == 0) {
		LogError("pop in the empty queue");
	}
	// 记录队首元素
	T topElement = m_pArray[0];
	// 删除队首元素
	++m_pArray;
	--m_iCount;

	// 如果数组大小 < 容量的1/4，将数组容量调整为当前的一半（10以下不判断）
	if (m_iCount > 10 && m_iCount < m_iCapacity / 4) {
		resize(m_iCapacity / 2);
	}

	return topElement;
}

template <typename T>
void ResizingArrayQueue<T>::clear()
{
	while (!isEmpty()) {
		pop();
	}
}

template <typename T>
T ResizingArrayQueue<T>::erase(int index)
{
	if (index <= 0 || index > m_iCount) {
		LogError("erase:index error");
	}

	T retValue = m_pArray[index - 1];

	while (index < m_iCount) {
		m_pArray[index - 1] = m_pArray[index];
		++index;
	}

	--m_iCount;

	// 如果数组大小 < 容量的1/4，将数组容量调整为当前的一半（10以下不判断）
	if (m_iCount > 10 && m_iCount < m_iCapacity / 4) {
		resize(m_iCapacity / 2);
	}

	return retValue;
}

#endif // !RESIZING_ARRAY_QUEUE_H
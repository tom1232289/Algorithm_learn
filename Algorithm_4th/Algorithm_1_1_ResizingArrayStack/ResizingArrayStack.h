// 下压（LIFO）栈（能够动态调整数组大小的实现）

#pragma once

#ifndef RESIZING_ARRAY_STACK_H
#define RESIZING_ARRAY_STACK_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"
#include <iterator>

using namespace LogInfo;
using namespace std;

const int ICOUNT = 10;	// 默认分配的数组容量

template <typename T>
class ResizingArrayStack
{
public:
	ResizingArrayStack();
	ResizingArrayStack(const ResizingArrayStack &rhs);
	ResizingArrayStack & operator=(const ResizingArrayStack &rhs);
	~ResizingArrayStack();

public:
	bool isEmpty() const;	// 栈是否为空
	size_t size() const;	// 获取栈的大小
	size_t capacity() const;// 获取栈的容量
	bool resize(size_t max);// 调整栈的容量为max，失败则返回false

	T top() const;			// 获取栈顶元素
	void push(T t);			// 入栈（按值传递）
	T pop();				// 出栈
	void clear();			// 清空栈

private:
	// 内置迭代器
	class MyIterator : public iterator<input_iterator_tag, T> {
	public:
		MyIterator(T *ptr = nullptr) :
			m_ptr(ptr) {}

	public:
		T operator*() const {
			return *m_ptr;
		}
		T * operator->() const {
			return m_ptr;
		}
		MyIterator & operator++() {
			++m_ptr;
			return *this;
		}
		MyIterator & operator++(int) {
			T *temp = m_ptr;
			++m_ptr;
			return (MyIterator)temp;
		}
		MyIterator & operator--() {
			--m_ptr;
			return *this;
		}
		MyIterator & operator--(int) {
			T *temp = m_ptr;
			--m_ptr;
			return (MyIterator)temp;
		}
		bool operator==(const MyIterator &rhs) const {
			return m_ptr == rhs.m_ptr;
		}
		bool operator!=(const MyIterator &rhs) const {
			return !(*this == rhs);
		}

	private:
		T *m_ptr = nullptr;
	};

public:
	MyIterator begin() const {
		if (isEmpty())
			return nullptr;

		return MyIterator(&(m_pArray[0]));
	}

	MyIterator end() const {
		if (isEmpty())
			return nullptr;

		return MyIterator(&(m_pArray[m_iCount - 1]) + 1);
	}

private:
	size_t m_iCount = 0;		// 栈的大小
	size_t m_iCapacity = 0;		// 栈的容量
	T *m_pArray = nullptr;		// 数组作为数据的表示方式
};

// 构造函数
template <typename T>
ResizingArrayStack<T>::ResizingArrayStack() :
	m_iCount(0),
	m_iCapacity(ICOUNT),
	m_pArray(new T[ICOUNT])
{	}

// 析构函数
template <typename T>
ResizingArrayStack<T>::~ResizingArrayStack()
{
	delete[] m_pArray;
	m_pArray = nullptr;
}

// 拷贝构造函数
template <typename T>
ResizingArrayStack<T>::ResizingArrayStack(const ResizingArrayStack<T> &rhs) :
	m_iCount(rhs.m_iCount),
	m_iCapacity(rhs.m_iCapacity)
{
	m_pArray = new T[m_iCapacity];
	for (size_t i = 0; i < m_iCount; ++i) {
		m_pArray[i] = rhs.m_pArray[i];
	}
}

// 拷贝赋值运算符
template <typename T>
ResizingArrayStack<T> & ResizingArrayStack<T>::operator=(const ResizingArrayStack<T> &rhs)
{
	// 考虑自赋值的情况，new一个新的数组
	T *newArray = new T[rhs.m_iCapacity];
	for (size_t i = 0; i < rhs.m_iCount; ++i) {
		newArray[i] = rhs.m_pArray[i];
	}

	// 执行析构函数的功能
	delete[] m_pArray;

	// 执行拷贝构造函数的功能
	m_pArray = newArray;
	m_iCount = rhs.m_iCount;
	m_iCapacity = rhs.m_iCapacity;

	return *this;
}

template<typename T>
inline bool ResizingArrayStack<T>::isEmpty() const
{
	return m_iCount == 0;
}

template<typename T>
inline size_t ResizingArrayStack<T>::size() const
{
	return m_iCount;
}

template<typename T>
inline size_t ResizingArrayStack<T>::capacity() const
{
	return m_iCapacity;
}

template<typename T>
inline bool ResizingArrayStack<T>::resize(size_t max)
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

template<typename T>
inline T ResizingArrayStack<T>::top() const
{
	// 判断数组为空的情况
	if (isEmpty())
		return T();

	return m_pArray[m_iCount - 1];
}

template<typename T>
inline void ResizingArrayStack<T>::push(T t)
{
	if (m_iCount == m_iCapacity) {
		resize(m_iCapacity + m_iCapacity / 4);
	}
	m_pArray[m_iCount++] = t;
}

template<typename T>
inline T ResizingArrayStack<T>::pop()
{
	// 判断数组为空的情况
	if (isEmpty()) {
		LogError("pop in the empty ArrayStack");
	}

	// 记录下栈顶元素
	T topElement = m_pArray[m_iCount - 1];

	// 删除栈顶元素
	m_pArray[m_iCount - 1] = T();
	--m_iCount;

	// 如果数组大小 < 容量的1/4，将数组容量调整为当前的一半
	if (m_iCount > 10 && m_iCount < m_iCapacity / 4) {
		resize(m_iCapacity / 2);
	}

	return topElement;
}

template<typename T>
inline void ResizingArrayStack<T>::clear()
{
	while (!isEmpty()) {
		pop();
	}
}

#endif // !RESIZING_ARRAY_STACK_H

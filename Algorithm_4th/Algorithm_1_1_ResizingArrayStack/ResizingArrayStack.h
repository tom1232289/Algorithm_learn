// ��ѹ��LIFO��ջ���ܹ���̬���������С��ʵ�֣�

#pragma once

#ifndef RESIZING_ARRAY_STACK_H
#define RESIZING_ARRAY_STACK_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"
#include <iterator>

using namespace LogInfo;
using namespace std;

const int ICOUNT = 10;	// Ĭ�Ϸ������������

template <typename T>
class ResizingArrayStack
{
public:
	ResizingArrayStack();
	ResizingArrayStack(const ResizingArrayStack &rhs);
	ResizingArrayStack & operator=(const ResizingArrayStack &rhs);
	~ResizingArrayStack();

public:
	bool isEmpty() const;	// ջ�Ƿ�Ϊ��
	size_t size() const;	// ��ȡջ�Ĵ�С
	size_t capacity() const;// ��ȡջ������
	bool resize(size_t max);// ����ջ������Ϊmax��ʧ���򷵻�false

	T top() const;			// ��ȡջ��Ԫ��
	void push(T t);			// ��ջ����ֵ���ݣ�
	T pop();				// ��ջ
	void clear();			// ���ջ

private:
	// ���õ�����
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
	size_t m_iCount = 0;		// ջ�Ĵ�С
	size_t m_iCapacity = 0;		// ջ������
	T *m_pArray = nullptr;		// ������Ϊ���ݵı�ʾ��ʽ
};

// ���캯��
template <typename T>
ResizingArrayStack<T>::ResizingArrayStack() :
	m_iCount(0),
	m_iCapacity(ICOUNT),
	m_pArray(new T[ICOUNT])
{	}

// ��������
template <typename T>
ResizingArrayStack<T>::~ResizingArrayStack()
{
	delete[] m_pArray;
	m_pArray = nullptr;
}

// �������캯��
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

// ������ֵ�����
template <typename T>
ResizingArrayStack<T> & ResizingArrayStack<T>::operator=(const ResizingArrayStack<T> &rhs)
{
	// �����Ը�ֵ�������newһ���µ�����
	T *newArray = new T[rhs.m_iCapacity];
	for (size_t i = 0; i < rhs.m_iCount; ++i) {
		newArray[i] = rhs.m_pArray[i];
	}

	// ִ�����������Ĺ���
	delete[] m_pArray;

	// ִ�п������캯���Ĺ���
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
	// ���Ҫ���������� <= ��ǰ���������򷵻�false
	if (max <= m_iCapacity) {
		return false;
	}

	// ��������Ԫ�ص��´�����������
	T *newArray = new T[max];
	for (size_t i = 0; i < m_iCount; ++i) {
		newArray[i] = m_pArray[i];
	}

	// ���پɵ�����
	delete[] m_pArray;
	m_pArray = newArray;

	m_iCapacity = max;

	return true;
}

template<typename T>
inline T ResizingArrayStack<T>::top() const
{
	// �ж�����Ϊ�յ����
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
	// �ж�����Ϊ�յ����
	if (isEmpty()) {
		LogError("pop in the empty ArrayStack");
	}

	// ��¼��ջ��Ԫ��
	T topElement = m_pArray[m_iCount - 1];

	// ɾ��ջ��Ԫ��
	m_pArray[m_iCount - 1] = T();
	--m_iCount;

	// ��������С < ������1/4����������������Ϊ��ǰ��һ��
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

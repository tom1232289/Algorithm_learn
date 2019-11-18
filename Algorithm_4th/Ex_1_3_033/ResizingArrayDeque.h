#pragma once

#ifndef DEQUE
#define DEQUE

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"
#include <iterator>

using namespace LogInfo;

const int ICOUNT = 10;	// Ĭ�Ϸ������������

template <typename T>
class ResizingArrayDeque
{
public:
	ResizingArrayDeque() :
		m_iCapacity(ICOUNT),
		m_pArray(new T[ICOUNT])
	{}
	~ResizingArrayDeque();

public:
	bool isEmpty() const { return m_iHead == m_iTail; }
	size_t size() const { return m_iTail - m_iHead; }
	size_t capacity() const { return m_iCapacity; }
	void pushLeft(T t);
	void pushRight(T t);
	T popLeft();
	T popRight();

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
			return temp;
		}

		MyIterator & operator--() {
			--m_ptr;
			return *this;
		}

		MyIterator & operator--(int) {
			T *temp = m_ptr;
			--m_ptr;
			return temp;
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
		if (isEmpty()) {
			return nullptr;
		}

		return MyIterator(&(m_pArray[m_iHead]));
	}

	MyIterator end() const {
		if (isEmpty()) {
			return nullptr;
		}

		return MyIterator(&(m_pArray[m_iTail]));
	}

private:
	void resize(int max);

	// private:
public:
	size_t m_iCapacity = ICOUNT;
	T *m_pArray = nullptr;
	size_t m_iHead = ICOUNT / 3;
	size_t m_iTail = ICOUNT / 3;
};

template <typename T>
ResizingArrayDeque<T>::~ResizingArrayDeque()
{
	delete[] m_pArray;
}

template <typename T>
void ResizingArrayDeque<T>::pushLeft(T t)
{
	if (m_iHead == 0) {
		resize(3 * size());
	}
	m_pArray[--m_iHead] = t;
}

template <typename T>
void ResizingArrayDeque<T>::pushRight(T t)
{
	if (m_iTail == m_iCapacity) {
		resize(3 * size());
	}
	m_pArray[m_iTail++] = t;
}

template <typename T>
T ResizingArrayDeque<T>::popLeft()
{
	if (isEmpty()) {
		LogError("popLeft on the empty ResizingArrayDeque");
	}
	// ���������С���ڴ�
	if (size() * 6 < m_iCapacity) {
		resize(3 * size());
	}
	// head�����ƶ�һλ
	return m_pArray[m_iHead++];
}

template <typename T>
T ResizingArrayDeque<T>::popRight()
{
	if (isEmpty()) {
		LogError("popRight on the empty ResizingArrayDeque");
	}
	// ���������С���ڴ�
	if (size() * 6 < m_iCapacity) {
		resize(3 * size());
	}
	// tail�����ƶ�һλ
	return m_pArray[m_iTail--];
}

template <typename T>
void ResizingArrayDeque<T>::resize(int max)
{
	Log("resize:" + to_string(max));
	if (max < ICOUNT) {
		max = ICOUNT;
	}
	m_iCapacity = max;
	// �������ڴ�
	T *temp = new T[max];
	// ����Ԫ�ص����ڴ���
	size_t first = max / 3;
	size_t last = first;
	for (int i = m_iHead; i < m_iTail; ++i) {
		temp[last++] = m_pArray[i];
	}
	// �ͷ�ԭ�����ڴ�
	delete[] m_pArray;
	// ����ָ��ָ��λ��
	m_pArray = temp;
	m_iHead = first;
	m_iTail = last;
}

#endif	// !DEQUE
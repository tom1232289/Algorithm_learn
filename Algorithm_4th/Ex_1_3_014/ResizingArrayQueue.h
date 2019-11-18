// ��дһ���� ResizingArrayQueueOfStrings��ʹ�ö�������ʵ�ֶ��еĳ���Ȼ����չʵ�֣�ʹ�õ�������ķ���ͻ�ƴ�С�����ơ�

#pragma once

#ifndef RESIZING_ARRAY_QUEUE_H
#define RESIZING_ARRAY_QUEUE_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

const int ICOUNT = 10;	// Ĭ�Ϸ������������

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
	bool resize(size_t max);	// �������е�����Ϊmax��ʧ���򷵻�false

	T top() const;	// ��ȡ����Ԫ��
	void push(T t);	// �����
	T pop();		// ������
	void clear();	// ��ն���
	T erase(int index);	// ��λ�ó�����

private:
	// ���õ�����
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
		// ���п�
		if (isEmpty()) {
			LogError("begin() at empty queue");
		}

		return iterator(&(m_pArray[0]));
	}

	iterator end() const {
		// ���п�
		if (isEmpty()) {
			LogError("end() at empty queue");
		}

		return iterator(&(m_pArray[m_iCount - 1]) + 1);
	}

private:
	size_t m_iCount = 0;	// ���еĴ�С
	size_t m_iCapacity = 0;	// ���е�����
	T *m_pArray = nullptr;	// ������Ϊ���ݵı�ʾ��ʽ
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
	// �����Ը�ֵ�������newһ���µ�����
	T *pNewArray = new T[rhs.capacity()];
	for (size_t i = 0; i < rhs.m_iCount; ++i) {
		pNewArray[i] = rhs.m_pArray[i];
	}

	// ִ�����������Ĺ���
	delete[] m_pArray;

	// ִ�п������캯���Ĺ���
	m_iCount = rhs.m_iCount;
	m_iCapacity = rhs.m_iCapacity;
	m_pArray = pNewArray;

	return *this;
}

template <typename T>
bool ResizingArrayQueue<T>::resize(size_t max)
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

template <typename T>
T ResizingArrayQueue<T>::top() const
{
	// ����Ϊ��
	if (m_iCount == 0)
		LogError("queue is empty");

	return m_pArray[0];
}

template <typename T>
void ResizingArrayQueue<T>::push(T t)
{
	// �����������С�����¿���һ���ڴ�
	if (m_iCount == m_iCapacity) {
		resize(m_iCapacity + m_iCapacity / 4);
	}

	m_pArray[m_iCount++] = t;
}

template <typename T>
T ResizingArrayQueue<T>::pop()
{
	// ����Ϊ��
	if (m_iCount == 0) {
		LogError("pop in the empty queue");
	}
	// ��¼����Ԫ��
	T topElement = m_pArray[0];
	// ɾ������Ԫ��
	++m_pArray;
	--m_iCount;

	// ��������С < ������1/4����������������Ϊ��ǰ��һ�루10���²��жϣ�
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

	// ��������С < ������1/4����������������Ϊ��ǰ��һ�루10���²��жϣ�
	if (m_iCount > 10 && m_iCount < m_iCapacity / 4) {
		resize(m_iCapacity / 2);
	}

	return retValue;
}

#endif // !RESIZING_ARRAY_QUEUE_H
#pragma once

// ���λ����������λ��������ֳ�Ϊ���ζ��У���һ�ֶ���Ϊ N ���Ƚ��ȳ������ݽṹ�����ڽ��̼���첽���ݴ�����¼��־�ļ�ʱʮ�����á���������Ϊ��ʱ�������߻������ݴ��뻺����ǰ�ȴ�������������ʱ�������߻�ȴ������ݴ��뻺������ΪRingBuffer ���һ��API ���ã��ػ������齫��ʵ�֡�

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>

#include <memory>
#include "../Utils/LogInfo.h"

using namespace std;
using namespace LogInfo;

// ���ÿճ�һλ�ķ�ʽ
template <typename T>
class RingBuffer
{
public:
	explicit RingBuffer(size_t size) :
		m_pBuf(unique_ptr<T[]>(new T[size])),
		m_iCapacity(size)
	{}

public:
	void reset();
	size_t capacity() const { return m_iCapacity; }
	size_t size() const { return (m_iRear - m_iFront + m_iCapacity) % m_iCapacity; }
	void push(T t);
	T pop();

private:
	bool isEmpty() const { return m_iFront == m_iRear; }
	bool isFull() const { return m_iFront == (m_iRear + 1) % m_iCapacity; }

private:
	unique_ptr<T[]> m_pBuf;
	size_t m_iFront = 0;
	size_t m_iRear = 0;
	const size_t m_iCapacity;
};

template <typename T>
void RingBuffer<T>::reset()
{
	m_iFront = m_iRear;
}

template <typename T>
void RingBuffer<T>::push(T t)
{
	if (isFull()) {
		return;
	}

	m_pBuf[m_iRear] = t;
	m_iRear = (m_iRear + 1) % m_iCapacity;
}

template <typename T>
T RingBuffer<T>::pop()
{
	if (isEmpty()) {
		LogError("pop on the empty RingBuffer");
	}

	T retValue = m_pBuf[m_iFront];
	m_iFront = (m_iFront + 1) % m_iCapacity;

	return retValue;
}

#endif	// !RING_BUFFER_H
#pragma once

// 环形缓冲区。环形缓冲区，又称为环形队列，是一种定长为 N 的先进先出的数据结构。它在进程间的异步数据传输或记录日志文件时十分有用。当缓冲区为空时，消费者会在数据存入缓冲区前等待；当缓冲区满时，生产者会等待将数据存入缓冲区。为RingBuffer 设计一份API 并用（回环）数组将其实现。

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>

#include <memory>
#include "../Utils/LogInfo.h"

using namespace std;
using namespace LogInfo;

// 采用空出一位的方式
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
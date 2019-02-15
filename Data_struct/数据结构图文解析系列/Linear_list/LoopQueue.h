#pragma once

#ifndef LOOP_QUEUE_H
#define LOOP_QUEUE_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#define _UNICODE

#include <iostream>

using namespace std;

template <typename T>
class LoopQueue {
public:
	LoopQueue(size_t c = 10);
	LoopQueue(const LoopQueue &lq);
	LoopQueue<T> & operator=(const LoopQueue<T> &rhs);
	~LoopQueue();

public:
	bool isEmpty() const;
	size_t size() const;
	bool push(T t);
	bool pop();
	T getFront() const;
	T * getQueueArray() const;		// ��Ҫ�ͷŷ���ֵ

private:
	size_t capacity;
	int begin;
	int end;
	T * queue;
};

template<typename T>
inline LoopQueue<T>::LoopQueue(size_t c) :
	capacity(c),
	begin(0),
	end(0),
	queue(new T[capacity])
{	}

template<typename T>
inline LoopQueue<T>::LoopQueue(const LoopQueue & lq) :
	capacity(lq.capacity),
	begin(lq.begin),
	end(lq.end)
{
	queue = new T[capacity];
	for (int i = 0; i < capacity; ++i) {
		queue[i] = lq.queue[i];
	}
}

template<typename T>
inline LoopQueue<T>& LoopQueue<T>::operator=(const LoopQueue<T>& rhs)
{
	// TODO: �ڴ˴����� return ���
	auto newp = new T[capacity];
	for (int i = 0; i < capacity; ++i)
		newp[i] = rhs.queue[i];
	delete[] queue;
	queue = newp;
	capacity = rhs.capacity;
	begin = rhs.begin;
	end = rhs.end;
	return *this;
}

template<typename T>
inline LoopQueue<T>::~LoopQueue()
{
	delete[] queue;
}

template<typename T>
inline bool LoopQueue<T>::isEmpty() const
{
	return begin == end;
}

template<typename T>
inline size_t LoopQueue<T>::size() const
{
	return (end - begin + capacity) % capacity;		// ������г���
}

template<typename T>
inline bool LoopQueue<T>::push(T t)
{
	if ((end + 1) % capacity == begin)				// �ж϶���
		return false;
	else {
		queue[end] = t;
		end = (end + 1) % capacity;
		return true;
	}
}

template<typename T>
inline bool LoopQueue<T>::pop()
{
	if (end == begin)
		return false;
	else {
		begin = (begin + 1) % capacity;
		return true;
	}
}

template<typename T>
inline T LoopQueue<T>::getFront() const
{
	if (end == begin)
		return T();
	else
		return queue[begin];
}

template<typename T>
inline T * LoopQueue<T>::getQueueArray() const
{
	auto QueueArray = new T[capacity];
	auto val = begin;
	for (int i = 0; i < capacity; ++i) {
		QueueArray[i] = queue[val];
		val = (val + 1) % capacity;
	}
	return QueueArray;
}

#endif	// !LINK_QUEUE_H
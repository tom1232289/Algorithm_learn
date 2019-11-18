#pragma once

// 双向队列与栈。用一个双向队列实现两个栈，保证每个栈操作只需要常数次的双向队列操作（请见练习 1.3.33）。

#ifndef STACK_DOUBLE
#define STACK_DOUBLE

#include "../Ex_1_3_033/LinkedDeque.h"

template <typename T>
class StackDouble
{
public:
	bool leftIsEmpty() const { return m_iLeftSize == 0; }
	bool rightIsEmpty() const { return m_iRightSize == 0; }
	size_t leftSize() const { return m_iLeftSize; }
	size_t rightSize() const { return m_iRightSize; }
	void pushLeft(T t);
	void pushRight(T t);
	T popLeft();
	T popRight();

private:
	LinkedDeque<T> m_lq;
	size_t m_iLeftSize = 0;
	size_t m_iRightSize = 0;
};

#endif	// !STACK_DOUBLE

template<typename T>
void StackDouble<T>::pushLeft(T t)
{
	m_lq.pushLeft(t);
	++m_iLeftSize;
}

template<typename T>
void StackDouble<T>::pushRight(T t)
{
	m_lq.pushRight(t);
	++m_iRightSize;
}

template<typename T>
T StackDouble<T>::popLeft()
{
	if (m_iLeftSize == 0) {
		LogError("popLeft: leftStack is empty");
	}
	--m_iLeftSize;
	return m_lq.popLeft();
}

template<typename T>
T StackDouble<T>::popRight()
{
	if (m_iRightSize == 0) {
		LogError("popRight: rightStack is empty");
	}
	--m_iRightSize;
	return m_lq.popRight();
}
#pragma once

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#define _UNICODE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class ArrayStack {
public:
	ArrayStack(int s = 10);
	ArrayStack(const ArrayStack &as);
	ArrayStack<T> & operator=(const ArrayStack<T> &rhs);
	~ArrayStack();

public:
	bool isEmpty() const;
	size_t size() const;
	T top() const;			// ��ȡջ��Ԫ��
	void push(T t);			// ��ջ
	T pop();				// ��ջ
	vector<T> *getVec() const;	// ��ȡ����
	void clear();

private:
	size_t count;				// ջ��Ԫ������
	int capacity;			// ջ������
	vector<T> *vec;			// �ײ�Ϊ����
};

template<typename T>
inline ArrayStack<T>::ArrayStack(int s) :
	count(0),
	capacity(s),
	vec(new vector<T>())
{	}

template<typename T>
inline ArrayStack<T>::~ArrayStack()
{
	delete vec;
}

template<typename T>
inline ArrayStack<T>::ArrayStack(const ArrayStack & as) :
	count(as.count),
	capacity(as.capacity)
{
	array = new T[as.capacity];
	for (int i = 0; i < as.count; ++i) {
		array[i] = as.array[i];
	}
}

template<typename T>
inline ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs)
{
	// TODO: �ڴ˴����� return ���
	auto newArray = new T[rhs.capacity];
	for (int i = 0; i < rhs.count; ++i) {
		newArray[i] = rhs.array[i];
	}
	delete array;
	array = newArray;
	count = rhs.count;
	capacity = rhs.capacity;
	return *this;
}

template<typename T>
inline bool ArrayStack<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t ArrayStack<T>::size() const
{
	return count;
}

template<typename T>
inline T ArrayStack<T>::top() const
{
	if (count != 0) {
		return vec->back();
	}
	else
		return T();
}

template<typename T>
inline void ArrayStack<T>::push(T t)
{
	if (count != capacity) {
		vec->push_back(t);
		++count;
	}
}

template<typename T>
inline T ArrayStack<T>::pop()
{
	if (count != 0) {
		T temp = vec->back();
		vec->pop_back();
		--count;
		return temp;
	}
	else
		return T();
}

template<typename T>
inline vector<T> * ArrayStack<T>::getVec() const
{
	return vec;
}

template<typename T>
inline void ArrayStack<T>::clear()
{
	while (!isEmpty())
		this->pop();
	vec->reserve(5);
}

#endif	// !ARRAYSTACK_H
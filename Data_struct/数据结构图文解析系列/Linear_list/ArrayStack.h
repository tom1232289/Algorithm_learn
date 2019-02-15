#pragma once

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#define _UNICODE

#include <iostream>

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
	T top() const;		// 获取栈顶元素
	void push(T t);	// 入栈
	T pop();		// 出栈
	T *getArray() const;	// 获取数组
	void clear();

private:
	size_t count = 0;		// 栈的元素数量
	size_t capacity = 0;	// 栈的容量
	T *array = nullptr;		// 底层为数组
};

template<typename T>
inline ArrayStack<T>::ArrayStack(int s) :
	count(0),
	capacity(s),
	array(new T[s])
{	}

template<typename T>
inline ArrayStack<T>::~ArrayStack()
{
	delete[] array;
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
	// TODO: 在此处插入 return 语句
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
		return array[count - 1];
	}
	else
		return T();
}

template<typename T>
inline void ArrayStack<T>::push(T t)
{
	if (count != capacity)
		array[count++] = t;
}

template<typename T>
inline T ArrayStack<T>::pop()
{
	if (count != 0)
		return array[--count];
	else
		return T();
}

template<typename T>
inline T * ArrayStack<T>::getArray() const
{
	return array;
}

template<typename T>
inline void ArrayStack<T>::clear()
{
	while (!isEmpty())
		this->pop();
}

#endif	// !ARRAYSTACK_H
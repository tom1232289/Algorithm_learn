#pragma once

#ifndef DOUBLECIRCULARLINKEDNODE_H
#define DOUBLECIRCULARLINKEDNODE_H

#include <iostream>
using namespace std;

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

template <typename T>
class DoubleCircularLinkedNode {
public:
	DoubleCircularLinkedNode() = default;
	DoubleCircularLinkedNode(T val, DoubleCircularLinkedNode<T> *pre_ptr, DoubleCircularLinkedNode<T> *next_ptr) :
		value(val),
		pPre(pre_ptr),
		pNext(next_ptr)
	{ }
	~DoubleCircularLinkedNode();
public:
	T value;
	DoubleCircularLinkedNode<T> *pPre;
	DoubleCircularLinkedNode<T> *pNext;
};

template<typename T>
inline DoubleCircularLinkedNode<T>::~DoubleCircularLinkedNode()
{
}

#endif // !DOUBLECIRCULARLINKEDNODE_H
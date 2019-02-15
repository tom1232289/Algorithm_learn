#pragma once

#ifndef SINGLYLINKEDNODE_H
#define SINGLYLINKEDNODE_H

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#include <iostream>

using namespace std;

template <typename T>
class SinglyLinkedNode {
public:
	SinglyLinkedNode() = default;
	SinglyLinkedNode(T val, SinglyLinkedNode<T> *next_ptr) :
		value(val),
		pNext(next_ptr)
	{ }
	~SinglyLinkedNode() { };

public:
	T value;
	SinglyLinkedNode<T> *pNext;
};

#endif	// !SINGLYLINKEDNODE_H
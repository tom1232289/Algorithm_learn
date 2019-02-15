#pragma once

#ifndef SINGLYLINKEDNODE_H
#define SINGLYLINKEDNODE_H

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
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
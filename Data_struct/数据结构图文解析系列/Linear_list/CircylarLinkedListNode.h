#pragma once

#ifndef CIRCYLARLINKEDLISTNODE_H
#define CIRCYLARLINKEDLISTNODE_H

#include <iostream>

using namespace std;

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

template <typename T>
class CircylarLinkedListNode {
public:
	CircylarLinkedListNode() = default;
	CircylarLinkedListNode(T val, CircylarLinkedListNode<T> *next_ptr) :
		value(val),
		pNext(next_ptr)
	{ }

public:
	T value;
	CircylarLinkedListNode<T> *pNext = nullptr;
};

#endif	// !CIRCYLARLINKEDLISTNODE_H
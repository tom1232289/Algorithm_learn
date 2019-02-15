#pragma once

#ifndef CIRCYLARLINKEDLISTNODE_H
#define CIRCYLARLINKEDLISTNODE_H

#include <iostream>

using namespace std;

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
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
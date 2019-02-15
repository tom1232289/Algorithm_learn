#pragma once
#ifndef DOUBLELINKNODE_H_INCLUDE
#define DOUBLELINKNODE_H_INCLUDE

template <typename T>
class DoubleLinkNode {
public:
	DoubleLinkNode() = default;
	DoubleLinkNode(T val, DoubleLinkNode<T> *pre_pre, DoubleLinkNode<T> *next_ptr) :
		value(val),
		pPre(pre_pre),
		pNext(next_ptr)
	{ }
public:
	T value;
	DoubleLinkNode<T> *pPre;
	DoubleLinkNode<T> *pNext;
};

#endif	// !DOUBLELINKNODE_H_INCLUDE
#pragma once
#ifndef BSNODE_H
#define BSNODE_H

#include <iostream>

using namespace std;

template<typename T>
class BSNode {
public:
	BSNode() = default;
	BSNode(T t) :
		value(t),
		lchild(nullptr),
		rchild(nullptr)
	{	}

public:
	T value = T();
	BSNode<T> *lchild = nullptr;
	BSNode<T> *rchild = nullptr;
	BSNode<T> *parent = nullptr;
};

#endif	// !BSNODE_H
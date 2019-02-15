#pragma once

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	Node() :
		value(T()),
		pNext(nullptr)
	{	}
	Node(T t) :
		value(t),
		pNext(nullptr)
	{	}
	Node(T t, Node<T> *next) :
		value(t),
		pNext(next)
	{	}

public:
	T value;
	Node<T> *pNext;
};

#endif	// !NODE_H
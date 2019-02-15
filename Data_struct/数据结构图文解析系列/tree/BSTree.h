#pragma once

#ifndef BSTREE_H
#define BSTREE_H

// 把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

#define _UNICODE

#include "BSNode.h"

template<typename T>
class BSTree {
public:
	BSTree() = default;
	~BSTree();

public:
	void preOrder();	// 先序遍历二叉树
	void inOrder();		// 中序遍历二叉树
	void postOrder();	// 后序遍历二叉树
	void layerOrder();	// 层次遍历二叉树

	BSNode<T> *search_recursion(T key)	const;	// 递归地进行查找
	BSNode<T> *search_iterator(T key)	const;	// 迭代地进行查找

	T search_minimum() const;	// 查找最小元素
	T search_maxmum() const;	// 查找最大元素

	BSNode<T> *successor(BSNode<T> *pNode);		// 查找指定节点的后继节点
	BSNode<T> *predecessor(BSNode<T> *pNode);	// 查找指定节点的前驱节点

	void insert(T key);		// 插入指定节点
	void remove(T key);		// 删除指定节点
	void destory();			// 销毁二叉树
	void print();			// 打印二叉树

private:
	BSNode<T> *root = nullptr;	// 根节点

private:
	BSNode<T> *search(BSNode<T> *&pNode, T key);
	void remove(BSNode<T> *pNode, T key);
	void preOrder(BSNode<T> *pNode);
	void inOrder(BSNode<T> *pNode);
	void postOrder(BSNode<T> *pNode);
	T search_minimum(BSNode<T> *pNode);
	T search_maxmum(BSNode<T> *pNode);
	void destory(BSNode<T> *&pNode);
};

template<typename T>
BSTree<T>::~BSTree()
{
	destory();
}

/// 销毁二叉树
template<typename T>
void BSTree<T>::destory()
{
	destory(root);
}
/// 销毁二叉树（内部使用函数）
template<typename T>
void BSTree<T>::destory(BSNode<T> *&p)
{
	if (p != nullptr) {
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}
}

/// 插入节点
template<typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T> *pParent = nullptr;
	BSNode<T> *pNode = root;

	while (pNode != nullptr) {		// 寻找合适的插入位置
		pParent = pNode;
		if (key < pNode->value)
			pNode = pNode->lchild;
		else if (key > pNode->value)
			pNode = pNode->rchild;
		else
			break;
	}

	pNode = new BSNode<T>(key);		// 以元素的值构建新节点

	if (pParent == nullptr)			// 如果是空树
		root = pNode;				// 则新节点为根
	else {
		if (key < pParent->value)
			pParent->lchild = pNode;	// 否则新节点为其父节点的左孩子
		else
			pParent->rchild = pNode;	// 或右孩子
	}
	pNode->parent = pParent;
}

/// 先序遍历二叉树
template<typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
}
template<typename T>
void BSTree<T>::preOrder(BSNode<T> *p)
{
	if (p != nullptr) {
		cout << p->value << " ";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

/// 中序遍历二叉树
template<typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}
template<typename T>
void BSTree<T>::inOrder(BSNode<T> *p)
{
	if (p != nullptr) {
		inOrder(p->lchild);
		cout << p->value << " ";
		inOrder(p->rchild);
	}
}

/// 后续遍历二叉树
template<typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
}
template<typename T>
void BSTree<T>::postOrder(BSNode<T> *p)
{
	if (p != nullptr) {
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << " ";
	}
}

//////////////////////////////////////////////////////////////////////////
// 一个节点的前驱节点有3种情况：
// 1.它有左子树，则其前驱节点为其左子树的最右节点。
// 2.它没有左子树，且它本身为右子树，则其父节点为其前驱节点。
// 3.它没有左子树，且它本身为左子树，则它的前驱节点为“第一个拥有右子树的父节点”。
//////////////////////////////////////////////////////////////////////////
/// 寻找前驱节点
template<typename T>
BSNode<T> * BSTree<T>::predecessor(BSNode<T> *pNode)
{
	if (pNode->lchild != nullptr) {
		pNode = pNode->lchild;
		while (pNode->rchild != nullptr) {
			pNode = pNode->rchild;
		}
		return pNode;
	}
	else {
		BSNode<T> *pParent = pNode->parent;
		while (pParent != nullptr && pParent->lchild == pNode) {
			pNode = pParent;
			pParent = pParent->parent;
		}
		return pParent;
	}
}

//////////////////////////////////////////////////////////////////////////
// 同样的，一个节点的后继节点也有三种情况：
// 1.它有右子树；则其后继节点为其右子树的最左节点。
// 2.它没有右子树，但它本身是一个左孩子，则后继节点为它的双亲。
// 3.它没有右子树，但它本身是一个右孩子，则其后继节点为“具有左孩子的最近父节点”。
//////////////////////////////////////////////////////////////////////////
/// 寻找后继节点
template<typename T>
BSNode<T> *BSTree<T>::successor(BSNode<T> *pNode)
{
	if (pNode->rchild != nullptr) {
		pNode = pNode->rchild;
		while (pNode->lchild != nullptr) {
			pNode = pNode->lchild;
		}
		return pNode;
	}
	else {
		BSNode<T> *pParent = pNode->parent;
		while (pParent != nullptr && pParent->rchild == pNode) {
			pNode = pParent;
			pParent = pParent->parent;
		}
		return pParent;
	}
}

//////////////////////////////////////////////////////////////////////////
// 删除二叉排序树的某个节点有三种情况：
// 1.被删除节点同时有左子树与右子树。
// 2.被删除节点只有左子树或只有右子树。
// 3.被删除节点没有子树。
// 对于第一种情况，我们的处理方式是将前驱节点的值保存在当前结点，继而删除前驱节点。
// 对于第二种情况，我们直接用子树替换被删节点。
// 对于第三种情况，我们可以直接删除节点。
//////////////////////////////////////////////////////////////////////////
/// 删除指定节点
template<typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
}
template<typename T>
void BSTree<T>::remove(BSNode<T>* pNode, T key)
{
	if (pNode == nullptr)
		return;
	if (key == pNode->value) {
		BSNode<T> *pDel = nullptr;

		if (pNode->lchild == nullptr || pNode->rchild == nullptr)
			pDel = pNode;
		else
			pDel = predecessor(pNode);

		// 此时，被删节点pDel只有一个孩子（或没有孩子），保存该孩子指针
		BSTree<T> *pChild = nullptr;
		if (pDel->lchild != nullptr)
			pChild = pDel->lchild;
		else
			pChild = pDel->rchild;

		// 让孩子的父节点指向被删除节点的父节点
		if (pChild != nullptr)
			pChild->parent = pDel->parent;

		// 如果要删除的节点是头结点，注意更改root的值
		if (pDel->parent == nullptr)
			root = pChild;

		// 如果要删除的节点不是头结点，要注意更改它的双亲节点指向新的孩子节点
		else if (pDel->parent->lchild == pDel)
			pDel->parent->lchild = pChild;
		else
			pDel->parent->rchild = pChild;

		if (pNode->value != pDel->value)
			pNode->value = pDel->value;

		delete pDel;
	}
	// 进行递归删除
	else if (key > pNode.value)
		remove(pNode->rchild, key);		// 情况二、三：被删节点只有左子树或右子树，或者没有孩子
	else
		remove(pNode->lchild, key);		// 情况一：被删节点同时有左右子树，则删除该节点的前驱
}

#endif	// !BSTREE_H
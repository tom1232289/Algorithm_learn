#pragma once

#ifndef BSTREE_H
#define BSTREE_H

// �ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
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
	void preOrder();	// �������������
	void inOrder();		// �������������
	void postOrder();	// �������������
	void layerOrder();	// ��α���������

	BSNode<T> *search_recursion(T key)	const;	// �ݹ�ؽ��в���
	BSNode<T> *search_iterator(T key)	const;	// �����ؽ��в���

	T search_minimum() const;	// ������СԪ��
	T search_maxmum() const;	// �������Ԫ��

	BSNode<T> *successor(BSNode<T> *pNode);		// ����ָ���ڵ�ĺ�̽ڵ�
	BSNode<T> *predecessor(BSNode<T> *pNode);	// ����ָ���ڵ��ǰ���ڵ�

	void insert(T key);		// ����ָ���ڵ�
	void remove(T key);		// ɾ��ָ���ڵ�
	void destory();			// ���ٶ�����
	void print();			// ��ӡ������

private:
	BSNode<T> *root = nullptr;	// ���ڵ�

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

/// ���ٶ�����
template<typename T>
void BSTree<T>::destory()
{
	destory(root);
}
/// ���ٶ��������ڲ�ʹ�ú�����
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

/// ����ڵ�
template<typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T> *pParent = nullptr;
	BSNode<T> *pNode = root;

	while (pNode != nullptr) {		// Ѱ�Һ��ʵĲ���λ��
		pParent = pNode;
		if (key < pNode->value)
			pNode = pNode->lchild;
		else if (key > pNode->value)
			pNode = pNode->rchild;
		else
			break;
	}

	pNode = new BSNode<T>(key);		// ��Ԫ�ص�ֵ�����½ڵ�

	if (pParent == nullptr)			// ����ǿ���
		root = pNode;				// ���½ڵ�Ϊ��
	else {
		if (key < pParent->value)
			pParent->lchild = pNode;	// �����½ڵ�Ϊ�丸�ڵ������
		else
			pParent->rchild = pNode;	// ���Һ���
	}
	pNode->parent = pParent;
}

/// �������������
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

/// �������������
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

/// ��������������
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
// һ���ڵ��ǰ���ڵ���3�������
// 1.����������������ǰ���ڵ�Ϊ�������������ҽڵ㡣
// 2.��û������������������Ϊ�����������丸�ڵ�Ϊ��ǰ���ڵ㡣
// 3.��û������������������Ϊ��������������ǰ���ڵ�Ϊ����һ��ӵ���������ĸ��ڵ㡱��
//////////////////////////////////////////////////////////////////////////
/// Ѱ��ǰ���ڵ�
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
// ͬ���ģ�һ���ڵ�ĺ�̽ڵ�Ҳ�����������
// 1.�����������������̽ڵ�Ϊ��������������ڵ㡣
// 2.��û��������������������һ�����ӣ����̽ڵ�Ϊ����˫�ס�
// 3.��û��������������������һ���Һ��ӣ������̽ڵ�Ϊ���������ӵ�������ڵ㡱��
//////////////////////////////////////////////////////////////////////////
/// Ѱ�Һ�̽ڵ�
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
// ɾ��������������ĳ���ڵ������������
// 1.��ɾ���ڵ�ͬʱ������������������
// 2.��ɾ���ڵ�ֻ����������ֻ����������
// 3.��ɾ���ڵ�û��������
// ���ڵ�һ����������ǵĴ���ʽ�ǽ�ǰ���ڵ��ֵ�����ڵ�ǰ��㣬�̶�ɾ��ǰ���ڵ㡣
// ���ڵڶ������������ֱ���������滻��ɾ�ڵ㡣
// ���ڵ�������������ǿ���ֱ��ɾ���ڵ㡣
//////////////////////////////////////////////////////////////////////////
/// ɾ��ָ���ڵ�
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

		// ��ʱ����ɾ�ڵ�pDelֻ��һ�����ӣ���û�к��ӣ�������ú���ָ��
		BSTree<T> *pChild = nullptr;
		if (pDel->lchild != nullptr)
			pChild = pDel->lchild;
		else
			pChild = pDel->rchild;

		// �ú��ӵĸ��ڵ�ָ��ɾ���ڵ�ĸ��ڵ�
		if (pChild != nullptr)
			pChild->parent = pDel->parent;

		// ���Ҫɾ���Ľڵ���ͷ��㣬ע�����root��ֵ
		if (pDel->parent == nullptr)
			root = pChild;

		// ���Ҫɾ���Ľڵ㲻��ͷ��㣬Ҫע���������˫�׽ڵ�ָ���µĺ��ӽڵ�
		else if (pDel->parent->lchild == pDel)
			pDel->parent->lchild = pChild;
		else
			pDel->parent->rchild = pChild;

		if (pNode->value != pDel->value)
			pNode->value = pDel->value;

		delete pDel;
	}
	// ���еݹ�ɾ��
	else if (key > pNode.value)
		remove(pNode->rchild, key);		// �������������ɾ�ڵ�ֻ����������������������û�к���
	else
		remove(pNode->lchild, key);		// ���һ����ɾ�ڵ�ͬʱ��������������ɾ���ýڵ��ǰ��
}

#endif	// !BSTREE_H
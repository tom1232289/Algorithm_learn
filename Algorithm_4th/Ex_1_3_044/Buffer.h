#pragma once

//�ı��༭���Ļ�������Ϊ�ı��༭���Ļ��������һ���������Ͳ�ʵ�ֱ� 1.3.13 �е� API��
//
//�� 1.3.13���ı��������� API
//
//Public class Buffer
//Buffer()	����һ��ջ�����
//void   insert(char c)	�ڹ��λ�ò����ַ� c
//char   delete()	ɾ�������ع��λ�õ��ַ�
//void   left(int k)	����������ƶ� k ��λ��
//void   right(int k)	����������ƶ� k ��λ��
//int   size()	�������е��ַ�����
//��ʾ��ʹ������ջ��

//��������ʹ������ջ��ģ�⻺������
//���� / �����ƶ� = ���� / ��ջ������Ӧ������Ԫ�ز�ѹ������һ��ջ��
//���� / ɾ�� = ��ջѹ�� / ����һ��Ԫ�ء�
//�ַ����� = ��ջ���� + ��ջ������

#include "../Algorithm_1_1_ResizingArrayStack/ResizingArrayStack.h"

class Buffer
{
public:
	Buffer() = default;

public:
	void insert(char c);
	char erase();
	void left(int k);
	void right(int k);
	int size() { return m_leftStack.size() + m_rightStack.size(); }

private:
	ResizingArrayStack<char> m_leftStack;
	ResizingArrayStack<char> m_rightStack;
};

void Buffer::insert(char c)
{
	m_leftStack.push(c);
}

char Buffer::erase()
{
	auto ret = m_leftStack.top();
	m_leftStack.pop();
	return ret;
}

void Buffer::left(int k)
{
	for (int i = 0; i < k; ++i) {
		auto c = m_leftStack.top();
		m_leftStack.pop();
		m_rightStack.push(c);
	}
}

void Buffer::right(int k)
{
	for (int i = 0; i < k; ++i) {
		auto c = m_rightStack.top();
		m_rightStack.pop();
		m_leftStack.push(c);
	}
}
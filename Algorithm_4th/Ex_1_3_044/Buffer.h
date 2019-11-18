#pragma once

//文本编辑器的缓冲区。为文本编辑器的缓冲区设计一种数据类型并实现表 1.3.13 中的 API。
//
//表 1.3.13　文本缓冲区的 API
//
//Public class Buffer
//Buffer()	创建一块空缓冲区
//void   insert(char c)	在光标位置插入字符 c
//char   delete()	删除并返回光标位置的字符
//void   left(int k)	将光标向左移动 k 个位置
//void   right(int k)	将光标向右移动 k 个位置
//int   size()	缓冲区中的字符数量
//提示：使用两个栈。

//这里我们使用两个栈来模拟缓冲区。
//向左 / 向右移动 = 从左 / 右栈弹出相应数量的元素并压入另外一个栈。
//插入 / 删除 = 左栈压入 / 弹出一个元素。
//字符数量 = 左栈数量 + 右栈数量。

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
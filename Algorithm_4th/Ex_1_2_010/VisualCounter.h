#pragma once

#ifndef VISUAL_COUNTER_H
#define VISUAL_COUNTER_H

// 编写一个类 VisualCounter，支持加一和减一操作。它的构造函数接受两个参数 N 和 max，其中 N 指定了操作的最大次数，max 指定了计数器的最大绝对值。作为副作用，用图像显示每次计数器变化后的值。

#include <math.h>
#include <QtGui/QPainter>

using namespace std;

class VisualCounter
{
public:
	VisualCounter(int N, int max) :
		m_iMaxTimes(N),
		m_iMaxCount(max) {}

public:
	void increment() {
		if (m_iOperatorTimes <= m_iMaxTimes && abs(m_iCount) < m_iMaxCount) {
			++m_iOperatorTimes;
			++m_iCount;
		}
	}

	void decrement() {
		if (m_iOperatorTimes <= m_iMaxTimes && abs(m_iCount) < m_iMaxTimes) {
			++m_iOperatorTimes;
			--m_iCount;
		}
	}

	void draw(QPainter &painter) {
		painter.setPen(QPen(Qt::black, 2));
		painter.drawPoint(m_iOperatorTimes, m_iCount + 200);
	}

private:
	int m_iMaxTimes = 0;
	int m_iMaxCount = 0;
	int m_iOperatorTimes = 0;
	int m_iCount = 0;
};

#endif // !VISUAL_COUNTER_H

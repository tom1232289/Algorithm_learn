#pragma once

#ifndef VISUAL_COUNTER_H
#define VISUAL_COUNTER_H

// ��дһ���� VisualCounter��֧�ּ�һ�ͼ�һ���������Ĺ��캯�������������� N �� max������ N ָ���˲�������������max ָ���˼�������������ֵ����Ϊ�����ã���ͼ����ʾÿ�μ������仯���ֵ��

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

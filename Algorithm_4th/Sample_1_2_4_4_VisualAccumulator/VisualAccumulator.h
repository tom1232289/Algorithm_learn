#pragma once

#ifndef VISUAL_ACCUMULATOR_H
#define VISUAL_ACCUMULATOR_H

#include <QtGui/QPainter>

class VisualAccumulator
{
public:
	VisualAccumulator(int trials, double max, QPainter &painter) :
		m_trials(trials),
		m_max(max),
		m_painter(painter) {}

public:
	void addDataValue(double val);	// 添加一个新的数据值
	double mean();	// 所有数据的平均值

private:
	int m_trials = 0;
	double m_max = 0.0;
	QPainter &m_painter;
	int N = 0;
	double m_total = 0.0;
};

void VisualAccumulator::addDataValue(double val)
{
	++N;
	m_total += val;
	m_painter.setPen(QPen(Qt::darkGray));
	m_painter.drawPoint(N, m_max - val);
	m_painter.setPen(QPen(Qt::red));
	m_painter.drawPoint(N, m_max - m_total / N);
}

double VisualAccumulator::mean()
{
	return m_total / N;
}

#endif // !VISUAL_ACCUMULATOR_H

#include "VisualAccumulator.h"
#include <iomanip>
#include <algorithm>

CVisualAccumulator::CVisualAccumulator(int trials, double max, QPainter &painter) :
	m_max(max),
	m_painter(painter)
{
	m_painter.setPen(QPen(Qt::blue, 5));
}

void CVisualAccumulator::addDataValue(double value)
{
	++N;
	m_total += value;
	m_painter.setPen(QPen(Qt::darkGray, 2));
	m_painter.drawPoint(N, m_max - value);
	m_painter.setPen(QPen(Qt::red, 2));
	m_painter.drawPoint(N, m_max - m_total / N);
}

ostream & CVisualAccumulator::print(ostream &os)
{
	os << "mean(" << N << " values) ";
	os << fixed << setprecision(7) << mean();
	return os;
}
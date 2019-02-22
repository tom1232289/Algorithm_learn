#include "TestPoint2DDlg.h"
#include <random>

CTestPoint2DDlg::CTestPoint2DDlg(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void CTestPoint2DDlg::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2));

	m_PointCoordinate.clear();
	CreateRandomPoint();

	for (auto c : m_PointCoordinate) {
		painter.drawPoint(c.rx(), c.ry());
	}
}

void CTestPoint2DDlg::CreateRandomPoint()
{
	random_device rd;
	mt19937_64 generator(rd());
	uniform_int_distribution<int> distribution(100, 600);

	const int N = 100;
	for (int i = 0; i < N; ++i) {
		int x = distribution(generator);
		int y = distribution(generator);
		m_PointCoordinate.push_back(QPoint(x, y));
	}

	double min = numeric_limits<double>::max();
	double trueLength = 0.0;
	for (auto i = m_PointCoordinate.begin(); i != m_PointCoordinate.end(); ++i) {
		for (auto j = i + 1; j != m_PointCoordinate.end(); ++j) {
			auto temp1 = pow((*j).rx() - (*i).rx(), 2);
			auto temp2 = pow((*j).ry() - (*i).ry(), 2);
			trueLength = sqrt(pow((*j).rx() - (*i).rx(), 2) + pow((*j).ry() - (*i).ry(), 2));
			if (trueLength < min)
				min = trueLength;
		}
	}

	ui.label->setText(QString::number(min));
}
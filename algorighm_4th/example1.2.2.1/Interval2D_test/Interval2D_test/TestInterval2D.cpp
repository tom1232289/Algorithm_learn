#include "TestInterval2D.h"
#include <QtGui/QPainter>
#include <random>
#include <QMessageBox>

using namespace std;

CTestInterval2D::CTestInterval2D(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void CTestInterval2D::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2));
	QRect rect(20, 50, 300, 100);
	painter.drawRect(rect);

// 	painter.drawRect(0, 0, 100, 100);
	painter.setPen(QPen(Qt::red, 1));

	const int T = 10000;
	m_nCount = 0;
	for (int i = 0; i < T; ++i) {
		random_device rd;
		mt19937_64 generator(rd());
		uniform_real_distribution<double> distribution(0.0, 1000.0);

		double x = distribution(generator);
		double y = distribution(generator);
		QPoint p(x, y);
		if (rect.contains(p))
			++m_nCount;
		else
			painter.drawPoint(p);
	}
	m_dArea = rect.width()*rect.height();
}

void CTestInterval2D::OnClickedButtonCompute()
{
	QString qsText = QString::number(m_nCount) + "\n" + QString::number(m_dArea);
	QMessageBox::information(this, NULL, qsText, QMessageBox::Ok);
}

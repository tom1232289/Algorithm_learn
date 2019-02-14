#include "Histogram.h"
#include <QtGui/QPainter>
#include "HistogramInfo.h"

using namespace std;

vector<double> dvec(10000, 0);

CHistogram::CHistogram(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void CHistogram::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2));

	size_t N = 100;
	double Lower = 100.0, Upper = 500.0;
	srand((unsigned)time(NULL));
	for (auto &c : dvec) {
		c = rand() / (double)RAND_MAX *(Upper - Lower) + Lower;
	}
	CHistogramInfo info(N, Lower, Upper, dvec);

	for (int i = 0; i < info.N; ++i) {
		double height = info.statistics[i];
		QRect rect(info.left, 300 - height, info.interval, height);
		painter.drawRect(rect);
		painter.fillRect(rect, Qt::red);
		info.left += info.interval;
	}
}

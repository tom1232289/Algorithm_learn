#include "Ex_1_1_032.h"
#include <random>
#include <QtGui/QPainter>
#include "Histogram.h"
#include <algorithm>
#include <QMessageBox>

int N = 0;
double l = 0;
double r = 0;
const int iY0 = 400;
const int iWidth = 50;	// 每一个小方格的宽度

Ex_1_1_032::Ex_1_1_032(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 连接信号与槽
	connect(ui.Btn_OK, SIGNAL(clicked()), this, SLOT(OnClickedBtnOK()));
}

void Ex_1_1_032::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	auto his = Histogram::GenerateHistograms(N, l, r);
	Histogram::ComputeHistogramsCount(Histogram::randomDigitals(l, r), his);

	// 计算高度比例
	int iMaxCount = 0;
	for (auto iter = his.begin(); iter != his.end(); ++iter) {
		if (iter->count > iMaxCount) {
			iMaxCount = iter->count;
		}
	}
	double dHighScale = iMaxCount / (iY0 - 250);

	painter.setPen(QPen(Qt::black, 2));
	int iX0 = 20;
	for (auto hi : his) {
		QRect rect(iX0, iY0 - hi.count / dHighScale, iWidth, hi.count / dHighScale);
		iX0 = iX0 + iWidth;
		painter.drawRect(rect);
		painter.fillRect(rect, Qt::gray);
	}
}

void Ex_1_1_032::OnClickedBtnOK()
{
	N = ui.LE_N->text().toInt();
	l = ui.LE_L->text().toDouble();
	r = ui.LE_R->text().toDouble();
	if (!(N > 0)) {
		QMessageBox::critical(this, QStringLiteral("错误"), QStringLiteral("N必须大于0"), QMessageBox::Yes);
		return;
	}
	if (l >= r) {
		QMessageBox::critical(this, QStringLiteral("错误"), QStringLiteral("l必须小于r"), QMessageBox::Yes);
		return;
	}

	update();
}
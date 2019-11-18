// 将圆N等分：
// 设圆方程为(x-x0)²+(y-y0)²=r²，以过圆心且与x轴平行的直线与圆产生的右交点A1(x0+r,y0)为起点，将圆n等分，等分点依次记为A1、A2、A3、......An。
// A1的坐标为(x0+r,y0)，
// A2的坐标为(x0 + r*cos(2π / n), y0 + r*sin(2π / n))，
// A3的坐标为(x0 + r*cos(2π*2 / n), y0 + r*sin(2π*2 / n))，
// ......
// An的坐标为(x0 + r*cos(2π*(n - 1) / n), y0 + r*sin(2π*(n - 1) / n))。
// Ax的坐标为 x0 + r*cos(2π*(x-1) / n), y0 + r*sin(2π*(x-1) / n)。

#include "Ex_1_1_031.h"
#include <QtGui/QPainter>
#include <random>

using namespace std;

const double PI = std::acos(-1);

int N = 0;
double probability = 0;

Ex_1_1_031::Ex_1_1_031(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Ex_1_1_031::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	painter.setPen(QPen(Qt::blue, 1));
	// 画出圆
	double r = 200;
	double x0 = 20 + r;
	double y0 = 100 + r;
	painter.drawEllipse(x0 - r, y0 - r, r * 2, r * 2);	// x,y为矩形的左上角

	painter.setPen(QPen(Qt::red, 4));
	pair<double, double> point;
	vector<pair<double, double>> points;
	// 在圆上取等距离的N个点
	for (int index = 0; index < N; ++index) {
		double x = x0 + r*cos(2 * PI*index / N);
		double y = y0 + r*sin(2 * PI*index / N);
		points.emplace_back(make_pair(x, y));
		// 画点
		painter.drawPoint(x, y);
	}

	painter.setPen(QPen(Qt::black, 1));
	// 随机连线
	random_device rd;
	mt19937_64 gen(rd());
	bernoulli_distribution distribution(probability);	// 伯努利分布（p的概率返回true，1-p的概率返回false）
	for (auto p1 : points) {
		for (auto p2 : points) {
			if (distribution(gen)) {
				painter.drawLine(p1.first, p1.second, p2.first, p2.second);
			}
		}
	}
}

void Ex_1_1_031::OnClickedBtnOK()
{
	N = ui.LE_equal->text().toInt();
	probability = ui.LE_probability->text().toDouble();

	update();
}
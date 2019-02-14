#include "Ex_1_1_31.h"
#include <math.h>
#include <random>
#include <vector>
#include <iostream>


using namespace std;

Ex_1_1_31::Ex_1_1_31(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

const double PI = std::acos(-1);
size_t N = 20;
double p = 0.1;

void Ex_1_1_31::paintEvent(QPaintEvent * event)
{
	getParam(N, p);
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 4));

	double r = 200;
	double x0 = 20 + r;
	double y0 = 20 + r;
	painter.drawEllipse(x0-r, y0-r, r * 2, r * 2);

	pair<double, double> points;
	vector<pair<double, double>> pairvec;
	painter.setPen(QPen(Qt::red, 5));
	for (int idn = 0; idn < N; ++idn) {
		double x = x0 + r * cos(2 * PI*idn / N);
		double y = y0 + r * sin(2 * PI*idn / N);
		painter.drawPoint(x, y);

		points.first = x;
		points.second = y;
		pairvec.push_back(points);
	}

	painter.setPen(QPen(Qt::black, 1));
	std::random_device rd;
	std::mt19937_64 generator(rd());
	std::bernoulli_distribution distribution(p);
	for (auto i : pairvec) {
		for (auto j : pairvec) {
			if (distribution(generator)) {
				painter.drawLine(i.first, i.second, j.first, j.second);
			}
		}
	}
}

void Ex_1_1_31::getParam(size_t & N, double & p)
{
	if (p < 0 || p>1)
		return;
	std::cin >> N >> p;
}

#include "Ex_1_2_010.h"
#include "VisualCounter.h"
#include <random>

using namespace std;

Ex_1_2_010::Ex_1_2_010(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Ex_1_2_010::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	random_device rd;
	mt19937_64 gen(rd());
	bernoulli_distribution distribution(0.5);
	VisualCounter vc(100, 30);
	for (int i = 0; i < 100; ++i) {
		if (distribution(gen)) {
			vc.increment();
		}
		else {
			vc.decrement();
		}

		vc.draw(painter);
	}
}
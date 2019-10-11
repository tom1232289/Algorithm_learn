#include "VisualAccumulatorDlg.h"
#include "VisualAccumulator.h"
#include <QtGui/QPainter>
#include <random>
#include <QMessageBox>

using namespace std;

int T = 500;
double MAX = 500;

VisualAccumulatorDlg::VisualAccumulatorDlg(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 连接信号与槽
	connect(ui.Btn_Avg, SIGNAL(clicked()), this, SLOT(OnClickedBtnAvg()));
}

void VisualAccumulatorDlg::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	random_device rd;
	mt19937_64 gen(rd());
	uniform_real_distribution<double> distribution(0, T);

	VisualAccumulator va(T, MAX, painter);
	for (int t = 0; t < T; t++) {
		va.addDataValue(distribution(gen));
	}

	m_dAvg = va.mean();
}

void VisualAccumulatorDlg::OnClickedBtnAvg()
{
	QMessageBox::information(this, NULL, QString::number(m_dAvg), QMessageBox::Yes);
}
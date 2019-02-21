#include "VisualAccumulatorDlg.h"
#include "VisualAccumulator.h"
#include <random>
#include <QMessageBox>
#include <sstream>
#include <QtWidgets/QScrollArea>

CVisualAccumulatorDlg::CVisualAccumulatorDlg(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void CVisualAccumulatorDlg::paintEvent(QPaintEvent * event)
{
	const int T = 1000;
	QPainter painter(this);
	random_device rd;
	mt19937_64 generator(rd());
	uniform_real_distribution<double> distribution(0, T);

	CVisualAccumulator va(T, 1000, painter);
	for (int i = 0; i < T; ++i) {
		va.addDataValue(distribution(generator));
	}

	ostringstream ss;
	ss << va.print(ss).rdbuf();
	string str = ss.str();
	m_qsVisualAccumulate = QString::fromStdString(str);
}

void CVisualAccumulatorDlg::OnClickedButtonPrint()
{
	QMessageBox::information(nullptr, NULL, m_qsVisualAccumulate);
}
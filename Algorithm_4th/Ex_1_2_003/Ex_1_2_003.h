#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ex_1_2_003.h"
#include <vector>

using namespace std;

class Ex_1_2_003 : public QMainWindow
{
	Q_OBJECT

public:
	Ex_1_2_003(QWidget *parent = Q_NULLPTR);

private:
	void paintEvent(QPaintEvent *event);

private:
	QRect randomRect();
	void ComputeICCount();

	private slots:
	void OnClickedBtnIC();

private:
	Ui::Ex_1_2_003Class ui;

private:
	int m_iIntersect = 0;
	int m_iContain = 0;
	vector<QRect> m_rects;
	bool m_bRefresh = false;
};

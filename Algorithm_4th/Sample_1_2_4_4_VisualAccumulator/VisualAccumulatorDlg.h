#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VisualAccumulatorDlg.h"

class VisualAccumulatorDlg : public QMainWindow
{
	Q_OBJECT

public:
	VisualAccumulatorDlg(QWidget *parent = Q_NULLPTR);

private:
	void paintEvent(QPaintEvent *event);

	private slots:
	void OnClickedBtnAvg();

private:
	Ui::VisualAccumulatorDlgClass ui;

private:
	double m_dAvg = 0.0;
};

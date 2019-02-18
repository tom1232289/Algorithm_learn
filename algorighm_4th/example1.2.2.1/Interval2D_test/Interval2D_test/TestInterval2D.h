#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestInterval2D.h"
#include <QLabel>
#include <QPushButton>

class CTestInterval2D : public QMainWindow
{
	Q_OBJECT

public:
	CTestInterval2D(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);

public slots:
	void OnClickedButtonCompute();

private:
	Ui::CTestInterval2DClass ui;
	int m_nCount = 0;
	double m_dArea = 0.0;
};

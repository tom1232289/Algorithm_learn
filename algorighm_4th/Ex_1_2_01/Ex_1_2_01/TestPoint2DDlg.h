#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestPoint2DDlg.h"
#include <QPainter>
#include <vector>
#include <QMessageBox>
#include <QLabel>

using namespace std;

class CTestPoint2DDlg : public QMainWindow
{
	Q_OBJECT

public:
	CTestPoint2DDlg(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);
public:
	void CreateRandomPoint();
private:
	Ui::CTestPoint2DDlgClass ui;
	vector<QPoint> m_PointCoordinate;
};

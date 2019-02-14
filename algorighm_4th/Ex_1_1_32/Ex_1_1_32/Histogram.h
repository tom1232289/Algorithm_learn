#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CHistogram.h"
#include <vector>

using namespace std;

class CHistogram : public QMainWindow
{
	Q_OBJECT

public:
	CHistogram(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);
	
private:
	Ui::CHistogramClass ui;
};

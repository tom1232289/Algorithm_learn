#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ex_1_1_31.h"
#include <QtGui/QPainter>

class Ex_1_1_31 : public QMainWindow
{
	Q_OBJECT

public:
	Ex_1_1_31(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);
	void getParam(size_t &N, double &p);
private:
	Ui::Ex_1_1_31Class ui;
};

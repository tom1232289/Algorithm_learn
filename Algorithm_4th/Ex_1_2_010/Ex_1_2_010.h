#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ex_1_2_010.h"

class Ex_1_2_010 : public QMainWindow
{
	Q_OBJECT

public:
	Ex_1_2_010(QWidget *parent = Q_NULLPTR);

private:
	void paintEvent(QPaintEvent *event);

private:
	Ui::Ex_1_2_010Class ui;
};

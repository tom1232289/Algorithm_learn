#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ex_1_1_032.h"
#include <vector>

using namespace std;

class Ex_1_1_032 : public QMainWindow
{
	Q_OBJECT

public:
	Ex_1_1_032(QWidget *parent = Q_NULLPTR);

private:
	void paintEvent(QPaintEvent *event);

	private slots:
	void OnClickedBtnOK();

private:
	Ui::Ex_1_1_032Class ui;
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ex_1_1_031.h"

class Ex_1_1_031 : public QMainWindow
{
	Q_OBJECT

public:
	Ex_1_1_031(QWidget *parent = Q_NULLPTR);

public:
	void paintEvent(QPaintEvent *event);

// ²Û
private slots:
	void OnClickedBtnOK();

private:
	Ui::Ex_1_1_031Class ui;
};

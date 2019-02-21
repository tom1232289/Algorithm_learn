#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VisualAccumulatorDlg.h"

class CVisualAccumulatorDlg : public QMainWindow
{
	Q_OBJECT

public:
	CVisualAccumulatorDlg(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *event);
public slots:
	void OnClickedButtonPrint();
private:
	Ui::CVisualAccumulatorDlgClass ui;
	QString m_qsVisualAccumulate;
};

#include "VisualAccumulatorDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CVisualAccumulatorDlg w;
	w.show();
	return a.exec();
}

#include "VisualAccumulatorDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VisualAccumulatorDlg w;
	w.show();
	return a.exec();
}

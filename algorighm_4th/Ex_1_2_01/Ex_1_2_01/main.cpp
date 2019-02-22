#include "TestPoint2DDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CTestPoint2DDlg w;
// 	w.CreateRandomPoint();
	w.show();
	return a.exec();
}

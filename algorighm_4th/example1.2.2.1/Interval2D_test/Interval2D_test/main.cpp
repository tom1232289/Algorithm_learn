#include "TestInterval2D.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CTestInterval2D w;
	w.show();

	return a.exec();
}
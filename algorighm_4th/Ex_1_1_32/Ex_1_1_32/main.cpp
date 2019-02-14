#include "Histogram.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CHistogram w;
	w.show();
	return a.exec();
}

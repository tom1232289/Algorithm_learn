#include "Ex_1_1_31.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	// ����ȫ�ַ��
	QApplication::setStyle(QStyleFactory::create("Fusion"));

	Ex_1_1_31 w;
	w.show();

	return a.exec();
}

// 假设标准输入流中含有一系列 double 值。编写一段程序，从命令行接受一个整数 N 和两个 double 值 l 和 r。将 (l,r) 分为 N 段并使用 StdDraw 画出输入流中的值落入每段的数量的直方图。

#include "Ex_1_1_032.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ex_1_1_032 w;
	w.show();
	return a.exec();
}
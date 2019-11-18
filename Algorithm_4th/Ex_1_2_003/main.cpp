// 编写一个 Interval2D 的用例，从命令行接受参数 N、min 和 max。生成 N 个随机的 2D 间隔，其宽和高均匀地分布在单位正方形中的 min 和max 之间。用StdDraw 画出它们并打印出相交的间隔对的数量以及有包含关系的间隔对数量。

#include "Ex_1_2_003.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ex_1_2_003 w;
	w.show();
	return a.exec();
}
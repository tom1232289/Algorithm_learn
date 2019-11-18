#include "Steque.h"

//可以定位到发生内存泄露 所在的文件和具体那一行，用于检测 malloc 分配的内存
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 开启内存泄漏
inline void EnableMemLeakCheck() {
	//该语句在程序退出时自动调用 _CrtDumpMemoryLeaks(),用于多个退出出口的情况.
	//如果只有一个退出位置，可以在程序退出之前调用 _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
	EnableMemLeakCheck();

	Steque<int> steque;
// 	steque.push(1);
// 	steque.push(2);
// 	steque.push(3);
	steque.enqueue(5);
	steque.enqueue(4);

	Steque<int> steque2;
	steque2.enqueue(1);
	steque2.enqueue(2);
	steque2.enqueue(3);

	steque.catenation(steque2);

	return 0;
}
#include "LinkBag.h"

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

	LinkBag<int> lb;
	lb.push(1);
	lb.push(2);
	lb.push(3);

	for (auto iter = lb.begin(); iter != lb.end(); ++iter) {
		std::cout << *iter << " ";
	}

	LinkBag<int> lb2(lb);
	LinkBag<int> lb3;
	lb3 = lb2;
	lb3 = lb3;

	return 0;
}
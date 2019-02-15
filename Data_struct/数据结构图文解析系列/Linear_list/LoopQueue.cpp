#include "LoopQueue.h"
#include <tchar.h>
#include <string>

//可以定位到发生内存泄露 所在的文件和具体那一行，用于检测 malloc 分配的内存
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 有用
inline void EnableMemLeakCheck() {
	//该语句在程序退出时自动调用 _CrtDumpMemoryLeaks(),用于多个退出出口的情况.
	//如果只有一个退出位置，可以在程序退出之前调用 _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int _tmain()
{
	EnableMemLeakCheck();

	//运行到 第 n 次 内存分配的时候停下来
	//_CrtSetBreakAlloc(154);

	LoopQueue<string> lq;
	for (int i = 0; i < 20; ++i)
		lq.push(to_string(i));
	lq.pop();
	lq.push("a");
	LoopQueue<string> lq2(lq);
	lq2.pop();
	LoopQueue<string> lq3;
	lq3 = lq2;
	lq3.push("b");

	auto QueueArray = lq3.getQueueArray();
	auto len = lq3.size();
	for (int i = 0; i < len; ++i) {
		cout << QueueArray[i] << endl;
	}
	delete[] QueueArray;
	QueueArray = nullptr;

	system("pause");
	return 0;
}
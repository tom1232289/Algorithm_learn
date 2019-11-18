#include "LinkStack.h"
#include <iostream>

using namespace std;

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

	LinkStack<int> ls;
	auto a = ls.isEmpty();
	auto aa = ls.size();
	ls.push(1);
	ls.push(2);
	ls.push(3);
	ls.push(4);
	ls.pop();
	// 	auto temp = ls.pop();
	auto temp2 = ls.top();
	auto b = ls.isEmpty();
	auto bb = ls.size();
	// 	ls.clear();
	auto c = ls.isEmpty();
	auto cc = ls.size();

	LinkStack<int> ls2(ls);
	LinkStack<int> ls3;
	ls3 = ls2;
	ls3 = ls3;

	for (auto iter = ls3.begin(); iter != ls3.end(); ++iter) {
		cout << iter->value << endl;
	}

	//ls3.clear();

	ls3.catenation(ls);

	return 0;
}
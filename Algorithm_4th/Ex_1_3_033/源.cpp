#include "LinkedDeque.h"
#include "ResizingArrayDeque.h"
#include <string>

using namespace std;

//可以定位到发生内存泄露 所在的文件和具体那一行，用于检测 malloc 分配的内存
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 开启内存泄漏检测
inline void EnableMemLeakCheck() {
	//该语句在程序退出时自动调用 _CrtDumpMemoryLeaks(),用于多个退出出口的情况.
	//如果只有一个退出位置，可以在程序退出之前调用 _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
	EnableMemLeakCheck();

	//LinkedDeque<int> ld;
	//ld.pushLeft(1);
	//ld.pushRight(2);
	//ld.popRight();
	//ld.popLeft();

	ResizingArrayDeque<int> rad;
	
	for (int i = 1; i <= 10; ++i) {
		rad.pushLeft(i);
	}
	for (int i = 21; i <= 30; ++i) {
		rad.pushRight(i);
	}
	rad.popLeft();
	rad.popRight();
	rad.popRight();
	rad.popLeft();
	rad.popLeft();

	for (int i = 0; i < rad.capacity(); ++i) {
		cout << rad.m_pArray[i] << " ";
	}
	cout << endl;

	for (auto iter = rad.begin(); iter != rad.end(); ++iter) {
		cout << *iter << " ";
	}

	return 0;
}
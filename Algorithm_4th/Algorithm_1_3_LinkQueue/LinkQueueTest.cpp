#include "LinkQueue.h"
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

	LinkQueue<int> lq;
	auto temp1 = lq.isEmpty();
	auto temp11 = lq.size();
	lq.push(1);
	auto temp2 = lq.isEmpty();
	auto temp22 = lq.size();
	auto temp33 = lq.front();
	auto temp3 = lq.pop();
	auto temp4 = lq.front();
	lq.pop();
	lq.push(2);
	lq.push(3);

	LinkQueue<int> lq2(lq);
	LinkQueue<int> lq3;
	lq3 = lq2;
	lq3 = lq3;

	for (auto iter = lq3.begin(); iter != lq3.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	lq3.erase(1);
	for (auto iter = lq3.begin(); iter != lq3.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	lq3.erase(lq3.size());
	for (auto iter = lq3.begin(); iter != lq3.end(); ++iter) {
		cout << *iter << " ";
	}

	lq3.push(4);

	lq3.catenation(lq);

	return 0;
}
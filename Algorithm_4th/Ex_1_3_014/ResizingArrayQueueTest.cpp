#include "ResizingArrayQueue.h"
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

	ResizingArrayQueue<int> queue;
	auto temp1 = queue.isEmpty();
	auto temp2 = queue.size();
	auto temp3 = queue.capacity();
	auto temp4 = queue.resize(15);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	auto temp11 = queue.isEmpty();
	auto temp22 = queue.size();
	auto temp33 = queue.capacity();
	auto temp44 = queue.resize(15);
	auto temp5 = queue.top();
	auto temp6 = queue.pop();

	for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	ResizingArrayQueue<int> queue2(queue);
	ResizingArrayQueue<int> queue3;
	queue3 = queue2;
	queue3 = queue3;
	for (auto iter = queue2.begin(); iter != queue2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	for (auto iter = queue3.begin(); iter != queue3.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	queue3.erase(1);
	for (auto iter = queue3.begin(); iter != queue3.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	queue3.erase(queue3.size());
	for (auto iter = queue3.begin(); iter != queue3.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	queue.clear();

	return 0;
}
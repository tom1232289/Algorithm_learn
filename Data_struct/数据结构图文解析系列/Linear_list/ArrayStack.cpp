#include "ArrayStack.h"
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

// 	ArrayStack<int> as1;
// 	for (int i = 0; i < 10; ++i) {
// 		as1.push(i);
// 	}
// 	ArrayStack<int> as2(as1);
// 	ArrayStack<int> as3;
// 	as3 = as2;
// // 	as2.pop();
// 	for (int i = 0; i < as1.size(); ++i) {
// 		cout << as1.getArray()[i] << endl;
// 	}
// 	cout << endl;
// 	for (int i = 0; i < as2.size(); ++i) {
// 		cout << as2.getArray()[i] << endl;
// 	}
// 	cout << endl;
// 	for (int i = 0; i < as3.size(); ++i) {
// 		cout << as3.getArray()[i] << endl;
// 	}

// 	ArrayStack<string> as1;
// 	for (int i = 0; i < 10; ++i) {
// 		as1.push(to_string(i));
// 	}
// 
// 	for (auto c : *as1.getVec()) {
// 		cout << c << " ";
// 	}
// 	cout << endl;
// 	cout << as1.size() << endl;
// 
// 	as1.pop();
// 	
// 	for (auto c : *as1.getVec()) {
// 		cout << c << " ";
// 	}
// 	cout << endl;
// // 	cout << as1.size() << endl;
// 
// // 	cout << as1.top() << endl;
// 
// 	as1.clear();
// 	cout << as1.getVec()->capacity() << endl;
// 
// 	for (auto c : *as1.getVec()) {
// 		cout << c << " ";
// 	}
// 	cout << endl;
// 	cout << as1.size() << endl;

	ArrayStack<string> as;
	for (int i = 0; i < 10; ++i) {
		as.push(to_string(i));
	}
	auto array = as.getArray();
	auto len = as.size();
	for (int i = 0; i < len; ++i) {
		cout << array[i] << endl;
	}
	

	system("pause");
	return 0;
}
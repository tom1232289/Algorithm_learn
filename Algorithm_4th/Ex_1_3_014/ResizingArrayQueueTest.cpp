#include "ResizingArrayQueue.h"
#include <iostream>

using namespace std;

//���Զ�λ�������ڴ�й¶ ���ڵ��ļ��;�����һ�У����ڼ�� malloc ������ڴ�
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �����ڴ�й©
inline void EnableMemLeakCheck() {
	//������ڳ����˳�ʱ�Զ����� _CrtDumpMemoryLeaks(),���ڶ���˳����ڵ����.
	//���ֻ��һ���˳�λ�ã������ڳ����˳�֮ǰ���� _CrtDumpMemoryLeaks()
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
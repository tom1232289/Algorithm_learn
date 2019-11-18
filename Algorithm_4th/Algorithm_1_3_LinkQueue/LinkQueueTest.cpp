#include "LinkQueue.h"
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
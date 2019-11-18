#include "LinkStack.h"
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
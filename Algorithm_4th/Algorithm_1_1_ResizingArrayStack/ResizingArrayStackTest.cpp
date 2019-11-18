#include "ResizingArrayStack.h"
#include <string>
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

	//���е� �� n �� �ڴ�����ʱ��ͣ����
	//_CrtSetBreakAlloc(154);

	ResizingArrayStack<string> ras;
	ras.push("0");
	ras.push("1");
	ras.push("2");

	ras.resize(20);

	auto ras2 = ras;

	ResizingArrayStack<string> ras3;
	ras3 = ras2;

	return 0;
}
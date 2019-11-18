#include "Steque.h"

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

	Steque<int> steque;
// 	steque.push(1);
// 	steque.push(2);
// 	steque.push(3);
	steque.enqueue(5);
	steque.enqueue(4);

	Steque<int> steque2;
	steque2.enqueue(1);
	steque2.enqueue(2);
	steque2.enqueue(3);

	steque.catenation(steque2);

	return 0;
}
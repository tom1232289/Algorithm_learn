#include "LinkStack.h"	
#include <tchar.h>

//���Զ�λ�������ڴ�й¶ ���ڵ��ļ��;�����һ�У����ڼ�� malloc ������ڴ�
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// ����
inline void EnableMemLeakCheck() {
	//������ڳ����˳�ʱ�Զ����� _CrtDumpMemoryLeaks(),���ڶ���˳����ڵ����.
	//���ֻ��һ���˳�λ�ã������ڳ����˳�֮ǰ���� _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int _tmain()
{
	EnableMemLeakCheck();

	//���е� �� n �� �ڴ�����ʱ��ͣ����
	//_CrtSetBreakAlloc(154);

	LinkStack<int> aaa;
	aaa.push(2);
	LinkStack<int> bbb(aaa), ccc;
	ccc = aaa;
	bbb.push(3);
	cout << aaa.top() << endl;
	cout << bbb.top() << endl;
	cout << ccc.top() << endl;
	
	system("pause");
	return 0;
}
#include "CircylarLinkedQueue.h"

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

	CircylarLinkedQueue<int> clq;
// 	clq.push(1);
// 	clq.push(2);
// 	clq.push(3);
// 	clq.push(4);
// 	clq.pop();
// 	clq.pop();
// 	clq.pop();
// 	clq.pop();

	return 0;
}
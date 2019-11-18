#include "LinkBag.h"

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

	LinkBag<int> lb;
	lb.push(1);
	lb.push(2);
	lb.push(3);

	for (auto iter = lb.begin(); iter != lb.end(); ++iter) {
		std::cout << *iter << " ";
	}

	LinkBag<int> lb2(lb);
	LinkBag<int> lb3;
	lb3 = lb2;
	lb3 = lb3;

	return 0;
}
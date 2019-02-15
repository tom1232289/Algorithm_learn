#include "LoopQueue.h"
#include <tchar.h>
#include <string>

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

	LoopQueue<string> lq;
	for (int i = 0; i < 20; ++i)
		lq.push(to_string(i));
	lq.pop();
	lq.push("a");
	LoopQueue<string> lq2(lq);
	lq2.pop();
	LoopQueue<string> lq3;
	lq3 = lq2;
	lq3.push("b");

	auto QueueArray = lq3.getQueueArray();
	auto len = lq3.size();
	for (int i = 0; i < len; ++i) {
		cout << QueueArray[i] << endl;
	}
	delete[] QueueArray;
	QueueArray = nullptr;

	system("pause");
	return 0;
}
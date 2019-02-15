#include "BSTree.h"
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

	BSTree<int> bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(2);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);

	bst.preOrder();
	cout << endl;

	bst.inOrder();
	cout << endl;

	bst.postOrder();
	cout << endl;

	system("pause");
	return 0;
}
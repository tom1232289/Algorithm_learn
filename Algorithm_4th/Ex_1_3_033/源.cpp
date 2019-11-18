#include "LinkedDeque.h"
#include "ResizingArrayDeque.h"
#include <string>

using namespace std;

//���Զ�λ�������ڴ�й¶ ���ڵ��ļ��;�����һ�У����ڼ�� malloc ������ڴ�
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �����ڴ�й©���
inline void EnableMemLeakCheck() {
	//������ڳ����˳�ʱ�Զ����� _CrtDumpMemoryLeaks(),���ڶ���˳����ڵ����.
	//���ֻ��һ���˳�λ�ã������ڳ����˳�֮ǰ���� _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
	EnableMemLeakCheck();

	//LinkedDeque<int> ld;
	//ld.pushLeft(1);
	//ld.pushRight(2);
	//ld.popRight();
	//ld.popLeft();

	ResizingArrayDeque<int> rad;
	
	for (int i = 1; i <= 10; ++i) {
		rad.pushLeft(i);
	}
	for (int i = 21; i <= 30; ++i) {
		rad.pushRight(i);
	}
	rad.popLeft();
	rad.popRight();
	rad.popRight();
	rad.popLeft();
	rad.popLeft();

	for (int i = 0; i < rad.capacity(); ++i) {
		cout << rad.m_pArray[i] << " ";
	}
	cout << endl;

	for (auto iter = rad.begin(); iter != rad.end(); ++iter) {
		cout << *iter << " ";
	}

	return 0;
}
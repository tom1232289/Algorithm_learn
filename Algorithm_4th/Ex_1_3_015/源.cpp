// ��дһ�� Queue ������������һ�������в��� k ����ӡ����׼�����еĵ����� k ���ַ����������׼������������ k ���ַ�������

#include "../Algorithm_1_3_LinkQueue/LinkQueue.h"
#include <string>

using namespace std;

const int K = 7;

int main()
{
	LinkQueue<string> lq;
	lq.push("1");
	lq.push("2");
	lq.push("3");
	lq.push("4");
	lq.push("5");
	lq.push("6");
	lq.push("7");
	int iCount = lq.size();
	for (size_t i = 0; i < iCount - K; ++i) {
		auto temp = lq.pop();
	}
	cout << lq.front() << endl;

	return 0;
}
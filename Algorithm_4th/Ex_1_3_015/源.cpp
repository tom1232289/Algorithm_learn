// 编写一个 Queue 的用例，接受一个命令行参数 k 并打印出标准输入中的倒数第 k 个字符串（假设标准输入中至少有 k 个字符串）。

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
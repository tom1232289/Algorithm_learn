// Josephus 问题。在这个古老的问题中，N 个身陷绝境的人一致同意通过以下方式减少生存人数。他们围坐成一圈（位置记为 0 到 N-1）并从第一个人开始报数，报到 M 的人会被杀死，直到最后一个人留下来。传说中 Josephus 找到了不会被杀死的位置。编写一个 Queue 的用例 Josephus，从命令行接受N 和M 并打印出人们被杀死的顺序（这也将显示Josephus 在圈中的位置）。

//% java Josephus 7 2
//1 3 5 0 4 2 6

//报数时将一个人出队然后入队来模拟一个环。
//报到 M 个后将那个人出队但不入队（删除）
//随后继续循环。

#include <queue>
#include <iostream>

using namespace std;

void Josephus(int n, int m)
{
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < m - 1; ++i) {
			auto temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	int n = 41;
	int m = 3;
	Josephus(n, m);
	cout << endl;

	return 0;
}
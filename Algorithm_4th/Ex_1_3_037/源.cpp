// Josephus ���⡣��������ϵ������У�N �����ݾ�������һ��ͬ��ͨ�����·�ʽ������������������Χ����һȦ��λ�ü�Ϊ 0 �� N-1�����ӵ�һ���˿�ʼ���������� M ���˻ᱻɱ����ֱ�����һ��������������˵�� Josephus �ҵ��˲��ᱻɱ����λ�á���дһ�� Queue ������ Josephus���������н���N ��M ����ӡ�����Ǳ�ɱ����˳����Ҳ����ʾJosephus ��Ȧ�е�λ�ã���

//% java Josephus 7 2
//1 3 5 0 4 2 6

//����ʱ��һ���˳���Ȼ�������ģ��һ������
//���� M �����Ǹ��˳��ӵ�����ӣ�ɾ����
//������ѭ����

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
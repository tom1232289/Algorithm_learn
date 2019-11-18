// ǰ�Ʊ��롣�ӱ�׼�����ȡһ���ַ���ʹ����������Щ�ַ�������ظ��ַ��������ȡ��һ����δ�������ַ�ʱ�����������ͷ�������ȡ��һ���ظ����ַ�ʱ��������������ɾȥ���ٴβ����ͷ������ĳ�������Ϊ MoveToFront����ʵ����������ǰ�Ʊ�����ԣ����ֲ��Լ���������ʹ���Ԫ�غܿ��ܻ��ٴη��ʣ���˿������ڻ��桢����ѹ������ೡ����

#include <string>
#include "../Test/SinglyLinkedList.h"

using namespace std;

template <typename T>
void MoveToFront(string str,SinglyLinkedList<T> &sll)
{
	bool bHasSameChar = false;
	for (auto c : str) {
		for (auto node : sll) {
			if (c == node) {
				bHasSameChar = true;
			}
		}
		if (bHasSameChar) {
			sll.remove(c);
		}

		sll.insert(0, c);
	}
}

int main()
{
	string str = "ABCADC";
	SinglyLinkedList<char> sll;
	MoveToFront(str, sll);

	return 0;
}
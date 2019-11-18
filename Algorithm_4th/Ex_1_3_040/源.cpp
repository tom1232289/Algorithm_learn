// 前移编码。从标准输入读取一串字符，使用链表保存这些字符并清除重复字符。当你读取了一个从未见过的字符时，将它插入表头。当你读取了一个重复的字符时，将它从链表中删去并再次插入表头。将你的程序命名为 MoveToFront：它实现了著名的前移编码策略，这种策略假设最近访问过的元素很可能会再次访问，因此可以用于缓存、数据压缩等许多场景。

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
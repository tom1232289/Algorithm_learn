// 编写一个方法 find()，接受一条链表和一个字符串 key 作为参数。如果链表中的某个结点的 item 域的值为 key，则方法返回 true，否则返回 false。

#include "../Test/SinglyLinkedList.h"
#include <string>

using namespace std;

template <typename T>
bool find(SinglyLinkedList<T> &sll, T key)
{
	for (auto iter = sll.begin(); iter != sll.end(); ++iter) {
		if (key == *iter) {
			return true;
		}
	}
	return false;
}

int main()
{
	SinglyLinkedList<string> sll;
	sll.insert(sll.size(), "a");
	sll.insert(sll.size(), "ab");
	sll.insert(sll.size(), "abc");

	auto temp3 = ::find(sll, (string)"a");

	cout << boolalpha << temp3 << endl;

	return 0;
}
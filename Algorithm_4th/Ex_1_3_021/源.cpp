// ��дһ������ find()������һ�������һ���ַ��� key ��Ϊ��������������е�ĳ������ item ���ֵΪ key���򷽷����� true�����򷵻� false��

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
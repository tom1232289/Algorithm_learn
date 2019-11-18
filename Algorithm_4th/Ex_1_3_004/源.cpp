// ��дһ�� Stack ������ Parentheses���ӱ�׼�����ж�ȡһ���ı�����ʹ��ջ�ж����е������Ƿ�������������磬���� [()]{}{[()()]()} ����Ӧ�ô�ӡ true������ [(]) ���ӡ false��

#include "../Algorithm_1_2_LinkStack/LinkStack.h"
#include <iostream>
#include <string>

using namespace std;

bool Parentheses(const string &str)
{
	LinkStack<char> ls;
	for (auto c : str) {
		if (c == '[' || c == '(' || c == '{') {
			ls.push(c);
		}
		else if (c == ']') {
			if (ls.pop() != '[') {
				return false;
			}
		}
		else if (c == ')') {
			if (ls.pop() != '(') {
				return false;
			}
		}
		else if (c == '}') {
			if (ls.pop() != '{') {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	string str1 = "[()]{}{[()()]()}";
	string str2 = "[(])";
	cout << boolalpha << Parentheses(str1) << endl;
	cout << boolalpha << Parentheses(str2) << endl;

	return 0;
}
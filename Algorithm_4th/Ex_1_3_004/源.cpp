// 编写一个 Stack 的用例 Parentheses，从标准输入中读取一个文本流并使用栈判定其中的括号是否配对完整。例如，对于 [()]{}{[()()]()} 程序应该打印 true，对于 [(]) 则打印 false。

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
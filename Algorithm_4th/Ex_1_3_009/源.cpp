// 编写一段程序，从标准输入得到一个缺少左括号的表达式并打印出补全括号之后的中序表达式。例如，给定输入：
// 1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )
// 你的程序应该输出：
// ((1 + 2) * ((3 - 4) * (5 - 6)))

#include "../Algorithm_1_2_LinkStack/LinkStack.h"
#include <string>
#include <iostream>

using namespace std;

bool isDigit(char ch)
{
	return ch > '0' && ch < '9';
}

bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string CompleteParentheses(const string &str)
{
	LinkStack<string> operatorStack;	// 运算符栈
	LinkStack<string> digitStack;		// 运算数栈
	for (auto c : str) {
		if (isOperator(c)) {
			operatorStack.push(string(1, c));
		}
		else if (isDigit(c)) {
			digitStack.push(string(1, c));
		}
		else if (c == ')') {
			string opt = operatorStack.pop();
			string digit1 = digitStack.pop();
			string digit2 = digitStack.pop();
			string sRet = "(" + digit2 + " " + opt + " " + digit1 + ")";
			digitStack.push(sRet);
		}
		else {
			continue;
		}
	}

	return digitStack.pop();
}

int main()
{
	string str1 = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
	string str2 = CompleteParentheses(str1);
	cout << str2 << endl;

	return 0;
}
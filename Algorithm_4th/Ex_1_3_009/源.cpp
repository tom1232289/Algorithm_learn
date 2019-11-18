// ��дһ�γ��򣬴ӱ�׼����õ�һ��ȱ�������ŵı��ʽ����ӡ����ȫ����֮���������ʽ�����磬�������룺
// 1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )
// ��ĳ���Ӧ�������
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
	LinkStack<string> operatorStack;	// �����ջ
	LinkStack<string> digitStack;		// ������ջ
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
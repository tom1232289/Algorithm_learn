// ��дһ�γ��� EvaluatePostfix���ӱ�׼�����еõ�һ��������ʽ����ֵ����ӡ���������һ��ĳ����еõ�������ùܵ����ݸ���һ�γ�����Եõ��� Evaluate ��ͬ����Ϊ����

#pragma once

#include <string>
#include "../Algorithm_1_2_LinkStack/LinkStack.h"

using namespace std;

class CEvaluatePostfix
{
public:
	static double EvaluatePostfix(string &str);
private:
	static bool isDigit(char ch);
	static bool isOperator(char ch);
};

bool CEvaluatePostfix::isDigit(char ch)
{
	return ch > '0' && ch < '9';
}

bool CEvaluatePostfix::isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double CEvaluatePostfix::EvaluatePostfix(string & str)
{
	LinkStack<double> stack;
	for (auto c : str) {
		// �����־�ѹջ
		if (isDigit(c)) {
			stack.push(stod(&c));
		}
		// �ǲ������ͳ�ջ����
		else if (isOperator(c)) {
			double digit1 = stack.pop();
			double digit2 = stack.pop();
			double result = 0;
			if (c == '+') {
				result = digit2 + digit1;
			}
			else if (c == '-') {
				result = digit2 - digit1;
			}
			else if (c == '*') {
				result = digit2 * digit1;
			}
			else if (c == '/') {
				result = digit2 / digit1;
			}
			// �����ѹջ
			stack.push(result);
		}
	}
	return stack.top();
}
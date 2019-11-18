// 编写一段程序 EvaluatePostfix，从标准输入中得到一个后序表达式，求值并打印结果（将上一题的程序中得到的输出用管道传递给这一段程序可以得到和 Evaluate 相同的行为）。

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
		// 是数字就压栈
		if (isDigit(c)) {
			stack.push(stod(&c));
		}
		// 是操作符就出栈计算
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
			// 将结果压栈
			stack.push(result);
		}
	}
	return stack.top();
}
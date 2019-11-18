#pragma once

// 编写一个过滤器 InfixToPostfix，将算术表达式由中序表达式转为后序表达式。

// 中序转后序算法
//1、当输入的是操作数时候，直接输出
//2、当输入开括号时候，把它压栈
//3、当输入的是闭括号时候，先判断栈是否为空，若为空，则发生错误并进行相关处理。若非空，把栈中元素依次出栈输出，直到遇到第一个开括号，若没有遇到开括号，也发生错误，进行相关处理
//4、当输入是运算符op（ + 、 - 、×、 / ）时候
//a)循环，当（栈非空and栈顶不是开括号and栈顶运算符的优先级不低于输入的运算符的优先级）时，反复操作：将栈顶元素出栈输出
//b)把输入的运算符op压栈
//5、当中序表达式的符号序列全部读入后，若栈内仍有元素，把他们依次出栈输出。若弹出的元素遇到空括号，则说明不匹配，发生错误，并进行相关处理

// 例子：
// 2*3/(2-1)+3*(4-1)	中序表达式
// 23*21-/341-*+		后序表达式

#include "../Algorithm_1_2_LinkStack/LinkStack.h"
#include <string>
#include "../Utils/LogInfo.h"

using namespace LogInfo;

using namespace std;

class CInfixToPostfix
{
public:
	static string InfixToPostfix(const string &str);
private:
	static bool isLowerOperator(char optTop, char optCurr);
};

bool CInfixToPostfix::isLowerOperator(char optTop, char optCurr)
{
	if ((optTop == '+' || optTop == '-') && (optCurr == '*' || optCurr == '/'))
		return true;

	return false;
}

string CInfixToPostfix::InfixToPostfix(const string &str)
{
	string sPostfix;	// 后序表达式
	LinkStack<char> operatorStack;
	for (auto c : str) {
		// 1、当输入的是操作数时候，直接输出
		if (c > '0'&&c < '9') {
			sPostfix.push_back(c);
		}
		// 2、当输入左括号时候，把它压栈
		else if (c == '(') {
			operatorStack.push(c);
		}
		// 3、当输入的是右括号时候，先判断栈是否为空，若为空，则发生错误并进行相关处理。若非空，把栈中元素依次出栈输出，直到遇到第一个开括号，若没有遇到开括号，也发生错误，进行相关处理
		else if (c == ')') {
			if (operatorStack.isEmpty()) {
				LogError("operatorStack is empty");
			}
			else {
				char top = operatorStack.pop();
				while (top != '(') {
					if (operatorStack.isEmpty()) {
						LogError("Infix error, can not find '('");
					}
					sPostfix.push_back(top);
					top = operatorStack.pop();
				}
			}
		}
		// 4、当输入是运算符op（ + 、 - 、×、 / ）时候
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			// a)循环，当（栈非空and栈顶不是左括号and栈顶运算符的优先级不低于输入的运算符的优先级）时，反复操作：将栈顶元素出栈输出
			bool bIsLowerOperator = isLowerOperator(operatorStack.top(), c);
			while (!operatorStack.isEmpty() && operatorStack.top() != '(' && !bIsLowerOperator) {
				sPostfix.push_back(operatorStack.pop());
			}
			// b)把输入的运算符op压栈
			operatorStack.push(c);
		}
	}
	// 5、当中序表达式的符号序列全部读入后，若栈内仍有元素，把他们依次出栈输出。若弹出的元素遇到空括号，则说明不匹配，发生错误，并进行相关处理
	while (!operatorStack.isEmpty()) {
		char top = operatorStack.pop();
		if (top == '(' || top == ')') {
			LogError("Infix error, extra '(' or ')'");
		}
		sPostfix.push_back(top);
	}

	return sPostfix;
}
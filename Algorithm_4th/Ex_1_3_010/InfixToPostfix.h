#pragma once

// ��дһ�������� InfixToPostfix�����������ʽ��������ʽתΪ������ʽ��

// ����ת�����㷨
//1����������ǲ�����ʱ��ֱ�����
//2�������뿪����ʱ�򣬰���ѹջ
//3����������Ǳ�����ʱ�����ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ��������󲢽�����ش������ǿգ���ջ��Ԫ�����γ�ջ�����ֱ��������һ�������ţ���û�����������ţ�Ҳ�������󣬽�����ش���
//4���������������op�� + �� - ������ / ��ʱ��
//a)ѭ��������ջ�ǿ�andջ�����ǿ�����andջ������������ȼ����������������������ȼ���ʱ��������������ջ��Ԫ�س�ջ���
//b)������������opѹջ
//5����������ʽ�ķ�������ȫ���������ջ������Ԫ�أ����������γ�ջ�������������Ԫ�����������ţ���˵����ƥ�䣬�������󣬲�������ش���

// ���ӣ�
// 2*3/(2-1)+3*(4-1)	������ʽ
// 23*21-/341-*+		������ʽ

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
	string sPostfix;	// ������ʽ
	LinkStack<char> operatorStack;
	for (auto c : str) {
		// 1����������ǲ�����ʱ��ֱ�����
		if (c > '0'&&c < '9') {
			sPostfix.push_back(c);
		}
		// 2��������������ʱ�򣬰���ѹջ
		else if (c == '(') {
			operatorStack.push(c);
		}
		// 3�����������������ʱ�����ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ��������󲢽�����ش������ǿգ���ջ��Ԫ�����γ�ջ�����ֱ��������һ�������ţ���û�����������ţ�Ҳ�������󣬽�����ش���
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
		// 4���������������op�� + �� - ������ / ��ʱ��
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			// a)ѭ��������ջ�ǿ�andջ������������andջ������������ȼ����������������������ȼ���ʱ��������������ջ��Ԫ�س�ջ���
			bool bIsLowerOperator = isLowerOperator(operatorStack.top(), c);
			while (!operatorStack.isEmpty() && operatorStack.top() != '(' && !bIsLowerOperator) {
				sPostfix.push_back(operatorStack.pop());
			}
			// b)������������opѹջ
			operatorStack.push(c);
		}
	}
	// 5����������ʽ�ķ�������ȫ���������ջ������Ԫ�أ����������γ�ջ�������������Ԫ�����������ţ���˵����ƥ�䣬�������󣬲�������ش���
	while (!operatorStack.isEmpty()) {
		char top = operatorStack.pop();
		if (top == '(' || top == ')') {
			LogError("Infix error, extra '(' or ')'");
		}
		sPostfix.push_back(top);
	}

	return sPostfix;
}
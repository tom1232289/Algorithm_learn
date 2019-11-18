#include "EvaluatePostfix.h"
#include "../Ex_1_3_010/InfixToPostfix.h"

int main()
{
	string sInfix = "2*3/(2-1)+3*(4-1)";
	double result = CEvaluatePostfix::EvaluatePostfix(CInfixToPostfix::InfixToPostfix(sInfix));
	return 0;
}
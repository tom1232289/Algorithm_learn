#include "InfixToPostfix.h"

int main()
{
	string sInfix = "2 * 3 / (2 - 1) + 3 * (4 - 1)";
	string sPostfix = CInfixToPostfix::InfixToPostfix(sInfix);

	return 0;
}
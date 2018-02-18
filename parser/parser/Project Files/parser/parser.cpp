#include "parser.h"

void parser::tokeniseStr()
{
	for (size_t iter = 0; iter < entStr.ssize(); ++iter)
	{
		dString tempStr; 
		for (; !isCharOperator(entStr[iter]) && iter < entStr.ssize(); ++iter)
		{
			tempStr.pushBack(entStr[iter]);
		}
		oprdToken.pushBack(new operandToken(tempStr.str));
		oprtrToken.pushBack(new operatorToken(entStr[iter]));
	}
}

dString parser::retStr() 
{ 
	return entStr;
}

void parser::printAllTokens()
{
	std::cout << "Printing Operand Tokens...\n";
	for (size_t iter = 0; iter < oprdToken.size(); ++iter)
	{
		std::cout << oprdToken[iter]->retCont() << std::endl;
	}
	std::cout << "Printing Operator Tokens...\n";
	for (size_t iter = 0; iter < oprtrToken.size(); ++iter)
	{
		std::cout << oprtrToken[iter]->retCont() << std::endl;
	}
}

bool isCharOperator(char ent)
{
	if (ent == '/' || ent == '*' || ent == '+' || ent == '-')
	{
		return true;
	}
	return false;
}
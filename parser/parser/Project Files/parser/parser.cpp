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
		oprdToken.pushBack(*(new operandToken(tempStr.str)));
		std::cout << oprdToken[oprdToken.size() - 1].retNumNumerals();
//		operatorToken; //continue here
	}
}

dString parser::retStr() 
{ 
	return entStr;
}

bool isCharOperator(char ent)
{
	if (ent == '/' || ent == '*' || ent == '+' || ent == '-')
	{
		return true;
	}
	return false;
}
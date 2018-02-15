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
		oprdTk[numOprdTk] = *(new operandToken(tempStr.str));
		std::cout << oprdTk[numOprdTk].retNumNumerals();
		++numOprdTk;
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
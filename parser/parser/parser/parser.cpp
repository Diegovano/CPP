#include "parser.h"

void parser::tokeniseStr()
{
	for (size_t index = 0; index < entStr.ssize(); ++index)
	{
		dString tempStr; //declared here!!
		for (int iter = 0; entStr[iter] != '/' || entStr[iter] != '*' || entStr[iter] != '+' || entStr[iter] != ; ++iter)
		{
			tempStr.pushBack(entStr[iter]);
		}
		operandToken *tok = new operandToken(tempStr.str); //why is temp undeclared??!!
		std::cout << tok->retNumNumerals();
	}
}

dString parser::retStr() 
{ //???
	return entStr;
}